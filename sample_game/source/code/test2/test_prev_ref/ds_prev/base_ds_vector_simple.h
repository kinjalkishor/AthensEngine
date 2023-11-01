#pragma once

#include "base_types.h"
#include "base_def.h"
#include "base_print.h"

#include "base_ds_algorithm.h"

////#include "base_io.h"
////#include <iostream>

//#include "base_ds_iterators.h"

//------------------------------------

//#include <string.h>
//#include <stdlib.h>
//#include <type_traits>
//#include <initializer_list>


// std::vector resize & reserve to exact size, push_back increases by algorithm
// std::string resize & reserve, push_back to next_power2_ceil

//TODO:
// MOVE CONSTRUCTOR & MOVE ASSIGNMENT

//=====================================


namespace sdf 
{

template<class T>
class vector {
private:
    sys_allocator<T>* m_allocator = nullptr; 
    isz m_size = 0;
	isz m_capacity = 0;      
    T* m_data = nullptr; 
    //T* m_end = nullptr;

	T* allocate(size_t cnt) {
        if (m_allocator) {
            return m_allocator->allocate(cnt);
        } else {
            //println("DEFAULT ALLOC CALLED");
            return sdf::sys_allocate<T>(cnt);
        }
    }
    void deallocate(T* ptr) { 
        if (m_allocator) {
            m_allocator->deallocate(ptr); 
        } else {
            sdf::sys_deallocate<T>(ptr);
        }
    }

    isz next_capacity(isz requested_size) { 
		return sdf::next_power2_ceil(requested_size); 
        //return sdf::vec_calculate_growth(requested_size, capacity());
		//return requested_size;
	}

    bool is_reserve_needed(isz required_size) { return (required_size > capacity()); }

public:

	vector() {}


    void clear_memory() {
        if (m_data) {
            for_range (i, 0, size()) { sdf::element_destruct(&m_data[i]); }
            deallocate(m_data);            
            m_data = nullptr;
        }
        m_size = 0;
        m_capacity = 0;
    }

    virtual ~vector() { clear_memory(); }

    vector(isz count) {
        resize(count);
    }

    //constexpr vector(std::initializer_list<T> ilist) {
    //    //_Construct_n(_Convert_size<size_type>(_Ilist.size()), _Ilist.begin(), _Ilist.end());
    //    const isz list_size = ilist.end() - ilist.begin();
    //    resize(list_size);
    //    for (isz i=0; i<list_size; ++i) { m_data[i] = *(ilist.begin()+i); }
    //}

    isz size() const { return m_size; }
	isz capacity() const { return m_capacity; }	
    bool empty() { return (size() == 0); }
    //isz size_bytes() const { return (sizeof(T) * size()); }

    const T* data() const { return m_data; }
	T* data() { return m_data; }

    const T& operator[] (isz i) const { return m_data[i]; }
	T& operator[] (isz i) { return m_data[i]; } 

    void reserve_allocate(isz count, isz copy_size, isz old_size) {
        // Allocate new memory block
        T* new_data = allocate(count);
        //for_range (i, 0, copy_size) { sdf::element_construct(&new_data[i]); }
        // Copy old elements
        //for_range (i, 0, copy_size) { new_data[i] = m_data[i]; }
        for_range (i, 0, copy_size) { sdf::element_copy_construct(&new_data[i], m_data[i]); }


        // Dellocate old memory block
        for_range (i, 0, old_size) { sdf::element_destruct(&m_data[i]); }
        deallocate(m_data);            

        // Point data to new memory block
        m_data = new_data;
        new_data = nullptr;

        m_capacity = count;
    }

    void reserve_exact(isz count) {
        // Don't reserve when count is less than or equal to size.
        // count is greater than size for reserve.
        if (count <= size()) { return; }

        isz old_size = size();

        reserve_allocate(count, old_size, old_size);

        // Don't change size.
        //m_size = count;
    }

    void resize_exact(isz count, bool reserve_growth) {
        // Don't resize when count is equal to size.
        if (count == size()) { return; }

        isz old_size = size();

        // Expand.
        isz copy_size = size();
        // Shrink.
        if (count < size()) {
            copy_size = count;
        }

        isz reserve_count = count;
        if (reserve_growth) {
            isz next_count = next_capacity(count);
            reserve_count = next_count;
        }

        reserve_allocate(reserve_count, copy_size, old_size);

        m_size = count;
    }


    //---------------------
    void resize(isz count) { 
        if (count > size()) {
            if (count > capacity()) {
                // Expand.
                resize_exact(count, false);
            } else {
                // Construct extra elements.
                for_range (i, size(), count) { sdf::element_construct(&m_data[i]); }
                m_size = count;
            }
        } else {
            // Shrink.
            // Destruct extra elements.
            for_range (i, count, size()) { sdf::element_destruct(&m_data[i]); }
            m_size = count;
        }        
    }

    void reserve_growth(isz count) {
        // Expand only.
        if (count > capacity()) {
            //reserve_exact(count);
            isz next_count = next_capacity(count);
            reserve_exact(next_count);            
        }
        // Do nothing on Shrink.
    }

    void reserve(isz count) {
        // Expand only.
        if (count > capacity()) {
            reserve_exact(count);       
        }
        // Do nothing on Shrink.
    }

    void shrink_to_fit() { 
        resize_exact(size()); 
    }   

    void assign_data(const T* src, isz src_len) {
        resize(src_len);
        sdf::vec_copy(&m_data[0], &src[0], size());
    }

    //---------------------
    //void assign(const vector& src) { assign_data(src.data(), src.size()); }
    //vector(const vector& src) { assign(src); }
    //vector& operator=(const vector& src) { return vector(src); }


    void push_back(const T& element) {
        const isz required_size = size()+1;
        if (is_reserve_needed(required_size)) {
            reserve_growth(required_size);
        }
        //sdf::element_construct(&m_data[m_size]); m_data[m_size] = element;
        sdf::element_copy_construct(&m_data[m_size], element);
        ++m_size;             
    }

    void pop_back() {
        if (!empty()) {
            sdf::element_destruct(&m_data[m_size-1]);
            --m_size;
        }
    }

    sdf::optional<isz> find_index(const T& element) {
        return sdf::vec_find_index(data(), size(), element);
    }    


    void insert_pos(isz pos_index, const T& element) {
        // Extra space = size()+N
        const isz required_size = size()+1;         
        if (pos_index <= size()) {
            if (is_reserve_needed(required_size)) {
                reserve_growth(required_size);
            }
            // one less than required_size.
            const isz last_pos_index = required_size-1;
            // Construct extra elements at end.
            sdf::element_construct(&m_data[last_pos_index]);
            for (isz i=last_pos_index; i>pos_index; --i) { m_data[i] = m_data[i-1]; }
            // Insert element after shifting.
            m_data[pos_index] = element;
            m_size += 1;
        }        
    }

    void remove_pos(isz pos_index) {
        const isz last_pos_index = size()-1;
        if (pos_index <= size()) {
            for (isz i=pos_index; i<size(); ++i) { m_data[i] = m_data[i+1]; }
            sdf::element_destruct(&m_data[last_pos_index]);
            m_size -= 1;
        }
    }
    
};


}

