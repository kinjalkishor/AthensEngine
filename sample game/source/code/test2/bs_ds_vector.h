#pragma once

#include "bs_ds_util.h"

#include <stdint.h>
#include <stdlib.h>
#include <initializer_list>


// std::vector resize & reserve to exact size, push_back increases by algorithm
// std::string resize & reserve, push_back to next_power2_ceil
//=====================================

namespace sdf 
{

template<class T>
class vector {
private:
	T* m_data = nullptr;	
    ptrdiff_t m_size = 0;
	ptrdiff_t m_capacity = 0;      
    sys_allocator* m_allocator = nullptr; 

	T* allocate(size_t count) {
        if (m_allocator) {
            return static_cast<T*>(m_allocator->allocate(count*sizeof(T)));
        } else {
            return static_cast<T*>(malloc(count*sizeof(T)));
        }
    }
    void deallocate(T* ptr) { 
        if (m_allocator) {
            m_allocator->deallocate(ptr); 
        } else {
            free(ptr);
        }
    }

    ptrdiff_t next_capacity(ptrdiff_t requested_size) { 
		return dsf::next_power2_ceil(requested_size); 
        //return dsf::vector_calculate_growth(requested_size, capacity(), max_size());
		//return requested_size;
	}

    bool is_reserve_needed(ptrdiff_t required_size) { return (required_size > capacity()); }

public:
    vector() {}
    virtual ~vector() { clear_memory(); }

    void clear_memory() {
        for (ptrdiff_t i=0; i < size(); ++i) { dsf::element_destruct(&m_data[i]); }
        if (m_data) {            
            deallocate(m_data);            
            m_data = nullptr;
        }        
        m_capacity = 0;
        m_size = 0;
    }
    
	void clear() {
        for (ptrdiff_t i=0; i < size(); ++i) { dsf::element_destruct(&m_data[i]); }
        m_size = 0;        
    }

    ptrdiff_t size() const { return m_size; }
	ptrdiff_t capacity() const { return m_capacity; }	
    bool empty() const { return (size() == 0); }    

    const T* data() const { return m_data; }
	T* data() { return m_data; }

    const T& operator [](ptrdiff_t i) const { return m_data[i]; }
	T& operator [](ptrdiff_t i) { return m_data[i]; } 

    ptrdiff_t max_size() const { return PTRDIFF_MAX; }


    void allocate_new_block(ptrdiff_t count, bool geometric_growth) {
        ptrdiff_t old_size = size();
        ptrdiff_t copy_size = size();
        if (count < size()) { copy_size = count; }
        T* new_data = nullptr;
        ptrdiff_t allocate_capacity = count;
        if (geometric_growth) { allocate_capacity = next_capacity(count); }
        // Allocate new memory block
        new_data = allocate(allocate_capacity);
        // Copy old elements
        for (ptrdiff_t i=0; i < copy_size; ++i) { dsf::element_copy_construct(&new_data[i], m_data[i]); }     
        // Destruct old elements
        for (ptrdiff_t i=0; i < old_size; ++i) { dsf::element_destruct(&m_data[i]); }
        // Dellocate old memory block
		if (m_data) { deallocate(m_data); }
        // Point data to new memory block
        m_data = new_data;
        new_data = nullptr;

        m_capacity = allocate_capacity;
    }


    void reserve(ptrdiff_t count) {
        if (count <= capacity()) { return; }
        allocate_new_block(count, true);
    }

    void reserve_exact(ptrdiff_t count) {
        // Does not shrink.
        if (count <= capacity()) { return; }
        allocate_new_block(count, false);
    }

    void resize_helper(ptrdiff_t count, bool geometric_growth, bool allocate_on_shrink) {
        if (count == size()) { return; }

        if (count > size()) {
            // Expand.
            if (count > capacity()) {                
                // Memory not available, reallocate.                
                allocate_new_block(count, geometric_growth);
            }           
            // Memory available.
            // Construct extra elements.
            for (ptrdiff_t i=size(); i < count; ++i) { dsf::element_construct(&m_data[i]); }
            m_size = count;
        } else {
            // Shrink.            
            if (!allocate_on_shrink) {
                // Memory not deallocated.
                // Destruct extra elements.
                for (ptrdiff_t i=count; i < size(); ++i) { dsf::element_destruct(&m_data[i]); }
                m_size = count;
            } else {
                allocate_new_block(count, geometric_growth);
                m_size = count;
            }
        }        
    }
    
    void resize(ptrdiff_t count) {
        // vector resize allocates exact count of elements.
        resize_helper(count, false, false);
    }


    void resize_exact(ptrdiff_t count) {
        resize_helper(count, false, true);
    }


    vector(ptrdiff_t count) {
        resize(count);
    }

    vector(std::initializer_list<T> ilist) {
        //_Construct_n(_Convert_size<size_type>(_Ilist.size()), _Ilist.begin(), _Ilist.end());
        const ptrdiff_t list_size = ilist.end() - ilist.begin();
        resize(list_size);
        for (ptrdiff_t i=0; i<list_size; ++i) { m_data[i] = *(ilist.begin()+i); }
    }

    
    void push_back(const T& element) {
        const ptrdiff_t required_size = size()+1;
        if (is_reserve_needed(required_size)) {
            allocate_new_block(required_size, true);
        }
        dsf::element_copy_construct(&m_data[m_size], element);
        m_size += 1;             
    }

    void pop_back() {
        if (!empty()) {
            dsf::element_destruct(&m_data[m_size-1]);
            m_size -= 1;
        }
    }    


    //------------------
    // insert
    // 0 1 2 3 4 5 6 7
    // 0 1 2 . . 3 4 5 6 7 
    // 0 1 2 3 4 5 6 7 8 9
    // req size 8+2=10 //for N=2, pi=3
    // construct [8]..[9]
    // shift [9]..[5]    
    // remove
    // 0 1 2 3 4 5 6 7
    // 0 1 2 5 6 7 . .
    // 0 1 2 3 4 5 6 7
    // shift [3]..[5]
    // destruct [6]..[7]

    void insert_range(ptrdiff_t pos_index, T* src, ptrdiff_t src_len) {
        const ptrdiff_t N = src_len;
        // Extra space = size()+N
        const ptrdiff_t required_size = size()+N;         
        if (pos_index <= size()) {
            if (is_reserve_needed(required_size)) {
                allocate_new_block(required_size, true);
            }
            // Construct extra elements at end.
            for (ptrdiff_t i=size(); i < N; ++i) { dsf::element_construct(&m_data[i]); }
            // Shift elements.
            const ptrdiff_t last_pos_index = required_size-1;
            const ptrdiff_t shift_till_index = pos_index + N;
            for (ptrdiff_t i=last_pos_index; i >= shift_till_index; --i) { m_data[i] = m_data[i-N]; }
            // Insert element after shifting.
            for (ptrdiff_t i=0; i < N; ++i) { m_data[i+pos_index] = src[i]; }
            m_size += N;
        } 
    }
    
    void remove_range(ptrdiff_t pos_index, ptrdiff_t remove_len) {
        const ptrdiff_t N = remove_len;
        const ptrdiff_t last_pos_index = size()-1;
        if (pos_index <= size()) {
            // Shift elements.
            const ptrdiff_t shift_till_index = last_pos_index-N;
            for (ptrdiff_t i=pos_index; i <= shift_till_index; ++i) { m_data[i] = m_data[i+N]; }
            // Destruct extra elements at end.
            ptrdiff_t start_delete_index = shift_till_index+1;
            for (ptrdiff_t i=0; i < N; ++i) { dsf::element_destruct(&m_data[i+start_delete_index]); }
            m_size -= N;
        }
    }

    void insert_pos(ptrdiff_t pos_index, const T& element) { 
        const ptrdiff_t N = 1;
        // Extra space = size()+N
        const ptrdiff_t required_size = size()+N;         
        if (pos_index <= size()) {
            if (is_reserve_needed(required_size)) {
                allocate_new_block(required_size, true);
            }
            // Construct extra elements at end.
            for (ptrdiff_t i=size(); i < N; ++i) { dsf::element_construct(&m_data[i]); }
            // Shift elements.
            const ptrdiff_t last_pos_index = required_size-1;
            const ptrdiff_t shift_till_index = pos_index + N;
            for (ptrdiff_t i=last_pos_index; i >= shift_till_index; --i) { m_data[i] = m_data[i-N]; }
            // Insert element after shifting.
            //for (ptrdiff_t i=0; i < N; ++i) { m_data[i+pos_index] = src[i]; }
            m_data[pos_index] = element;
            m_size += N;
        } 
    }

    void remove_pos(ptrdiff_t pos_index) {
        remove_range(pos_index, 1);
    }

    //------------------
    void swap(vector& other) noexcept {
        dsf::swap(m_data, other.m_data);
        dsf::swap(m_capacity, other.m_capacity);
        dsf::swap(m_size, other.m_size);        
    }


    void copy_from_other(const T* src, ptrdiff_t src_len) {
        if (src_len > capacity()) {
            clear_memory();
            allocate_new_block(src_len, false);
            // capacity = src_len now.
        } else {
            clear();
            // capacity = old_capacity now.
        }        
        for (ptrdiff_t i=0; i < src_len; ++i) { dsf::element_copy_construct(&m_data[i], src[i]); }
        m_size = src_len;
    }


    // Copy constructor
    vector(const vector& other) {
        copy_from_other(other.data(), other.size());
    }

    // Assignment operator
    vector& operator=(const vector& other) {
        copy_from_other(other.data(), other.size());
        return *this;
    }


};




}