#pragma once

#include "bs_ds_util.h"

#include <stdint.h>
#include <stdlib.h>
#include <initializer_list>

#include <string.h>


namespace sdf 
{

template<class T>
class basic_string {
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
    basic_string() {}
    virtual ~basic_string() { clear_memory(); }

    void clear_memory() {
        if (m_data) {            
            deallocate(m_data);            
            m_data = nullptr;
        }        
        m_capacity = 0;
        m_size = 0;
    }
    
	void clear() {
        m_size = 0; 
        if (capacity() > 0) { m_data[0] = dsf::k_null_char<T>(); }
    }

    ptrdiff_t size() const { return m_size; }
	ptrdiff_t capacity() const { return m_capacity; }	
    bool empty() const { return (size() == 0); }    

    const T* data() const { return m_data; }
	T* data() { return m_data; }
    const T* c_str() const { return m_data; }

    const T& operator [](ptrdiff_t i) const { return m_data[i]; }
	T& operator [](ptrdiff_t i) { return m_data[i]; } 

    ptrdiff_t max_size() const { return PTRDIFF_MAX; }


    void allocate_new_block(ptrdiff_t count, bool geometric_growth) {
        ptrdiff_t old_size = size();
        ptrdiff_t copy_size = size();
        if (count < size()) { copy_size = count; }
        T* new_data = nullptr;
        ptrdiff_t allocate_capacity = count;
        if (geometric_growth) { allocate_capacity = next_capacity(count)-1; }
        // Allocate new memory block
        new_data = allocate(allocate_capacity+1);
        // Copy old elements
        memcpy(new_data, m_data, copy_size*sizeof(T));
        new_data[copy_size] = dsf::k_null_char<T>();
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
            // Set elements to default char so that no element is null in expanded memory.
            for (ptrdiff_t i=size(); i < count; ++i) { m_data[i] = dsf::k_default_char<T>(); }
            m_size = count;
            m_data[m_size] = dsf::k_null_char<T>();
        } else {
            // Shrink.            
            if (!allocate_on_shrink) {
                // Memory not deallocated.
                m_size = count;
                m_data[m_size] = dsf::k_null_char<T>();
            } else {
                allocate_new_block(count, geometric_growth);
                m_size = count;
                m_data[m_size] = dsf::k_null_char<T>();
            }
        }        
    }
    
    void resize(ptrdiff_t count) {
        // basic_string resize allocates geometric_growth count of elements.
        resize_helper(count, true, false);
    }


    void resize_exact(ptrdiff_t count) {
        resize_helper(count, true, true);
    }


    basic_string(ptrdiff_t count) {
        resize(count);
    }

    basic_string(std::initializer_list<T> ilist) {
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
        m_data[m_size] = element;
        m_size += 1;            
        m_data[m_size] = dsf::k_null_char<T>();
    }

    void pop_back() {
        if (!empty()) {
            m_size -= 1;
            m_data[m_size] = dsf::k_null_char<T>();
        }
    }    

    
    //------------------
    void insert_range(ptrdiff_t pos_index, T* src, ptrdiff_t src_len) {
        const ptrdiff_t N = src_len;
        // Extra space = size()+N
        const ptrdiff_t required_size = size()+N;         
        if (pos_index <= size()) {
            if (is_reserve_needed(required_size)) {
                allocate_new_block(required_size, true);
            }
             // Shift elements.
            const ptrdiff_t last_pos_index = required_size-1;
            const ptrdiff_t shift_till_index = pos_index + N;
            for (ptrdiff_t i=last_pos_index; i >= shift_till_index; --i) { m_data[i] = m_data[i-N]; }
            // Insert element after shifting.
            //for (ptrdiff_t i=0; i < N; ++i) { m_data[i+pos_index] = src[i]; }
            memcpy(&m_data[pos_index], src, N*sizeof(T));
            m_size += N;
            m_data[m_size] = dsf::k_null_char<T>();
        } 
    }
    
    void remove_range(ptrdiff_t pos_index, ptrdiff_t remove_len) {
        const ptrdiff_t N = remove_len;
        const ptrdiff_t last_pos_index = size()-1;
        if (pos_index <= size()) {
            // Shift elements.
            const ptrdiff_t shift_till_index = last_pos_index-N;
            for (ptrdiff_t i=pos_index; i <= shift_till_index; ++i) { m_data[i] = m_data[i+N]; }
            m_size -= N;
            m_data[m_size] = dsf::k_null_char<T>();
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
            // Shift elements.
            const ptrdiff_t last_pos_index = required_size-1;
            const ptrdiff_t shift_till_index = pos_index + N;
            for (ptrdiff_t i=last_pos_index; i >= shift_till_index; --i) { m_data[i] = m_data[i-N]; }
            // Insert element after shifting.
            //for (ptrdiff_t i=0; i < N; ++i) { m_data[i+pos_index] = src[i]; }
            m_data[pos_index] = element;
            m_size += N;
            m_data[m_size] = dsf::k_null_char<T>();
        } 
    }

    void remove_pos(ptrdiff_t pos_index) {
        remove_range(pos_index, 1);
    }

    //------------------
    void swap(basic_string& other) noexcept {
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
        memcpy(m_data, src, src_len*sizeof(T));
        m_data[src_len] = dsf::k_null_char<T>();
        m_size = src_len;        
    }

    // Copy constructor
    basic_string(const basic_string& other) {
        copy_from_other(other.data(), other.size(), other.capacity());
    }

    // Assignment operator
    basic_string& operator=(const basic_string& other) {
        copy_from_other(other.data(), other.size(), other.capacity());
        return *this;
    }


    //------------------
    basic_string& assign(const T* src, ptrdiff_t src_len) {
        copy_from_other(src, src_len, src_len);
        return *this;
    }
    basic_string& assign(const T* src) { return assign(src, dsf::strz_len(src)); }

    basic_string& append(const T* src, ptrdiff_t src_len) {
        ptrdiff_t dest_len = size();
        ptrdiff_t total_len = dest_len + src_len;  
        if (total_len > size()) { resize(total_len); }
        ptrdiff_t append_len = total_len - dest_len;
        memcpy(&m_data[dest_len], &src[0], append_len*sizeof(T));
        m_data[total_len] = dsf::k_null_char<T>();
        return *this;
    }
    basic_string& append(const T* src) { return append(src, dsf::strz_len(src)); }

    bool operator==(const basic_string& src) { return dsf::str_equals<T>(data(), size(), src.data(), src.size()); }

};




}