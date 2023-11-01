#pragma once

#include "base_types.h"
#include "base_def.h"
#include "base_print.h"

#include "base_ds_algorithm.h"

////#include "base_io.h"
////#include <iostream>

#include "base_ds_iterators.h"

//------------------------------------

//#include <string.h>
//#include <stdlib.h>
//#include <type_traits>
//#include <initializer_list>


// std::vector resize & reserve to exact size, push_back increases by algorithm
// std::string resize & reserve, push_back to next_power2_ceil

//=====================================


namespace sdf 
{

template<class T>
class vector {
private:

    sys_allocator* m_allocator = nullptr; 
    isz m_size = 0;
	isz m_capacity = 0;      
    T* m_data = nullptr; 

	T* allocate(size_t cnt) {
        if (m_allocator) {
            return static_cast<T*>(m_allocator->allocate(sizeof(T)*cnt));
        } else {
            //println("DEFAULT ALLOC CALLED");
            return static_cast<T*>(malloc(sizeof(T)*cnt));
        }
    }
    void deallocate(T* ptr) { 
        if (m_allocator) {
            m_allocator->deallocate(ptr); 
        } else {
            free(ptr);
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
    virtual ~vector() { clear_memory(); }

    void clear_memory() {
        if (m_data) {
            for_range (i, 0, size()) { sdf::element_destruct(&m_data[i]); }
            deallocate(m_data);            
            m_data = nullptr;
        }
        m_size = 0;
        m_capacity = 0;
    }
    

    vector(isz count) {
        resize(count);
    }


    void create_new_object(T*& dest_ptr, const T* src_ptr, isz count, isz copy_size) {
		// Allocate new memory block
        dest_ptr = allocate(count);
        for_range (i, 0, copy_size) { sdf::element_copy_construct(&dest_ptr[i], src_ptr[i]); }
	}
	void destroy_old_memory_block(isz old_size) {
		// Dellocate old memory block
		if (m_data) {
            for_range (i, 0, old_size) { sdf::element_destruct(&m_data[i]); }
            deallocate(m_data);   
        }
	}
	void set_to_new_memory_block(T*& dest_ptr, T*& src_ptr) {
		// Point data to new memory block
        dest_ptr = src_ptr;
        src_ptr = nullptr;
	}

	void copy_from_other(const T* src, isz src_len, isz src_capacity) {
		T* new_data = nullptr;
		create_new_object(new_data, src, src_capacity, src_len);
		destroy_old_memory_block(m_size);      
		set_to_new_memory_block(m_data, new_data);

        m_size = src_len;
        m_capacity = src_capacity;
    }
    


    // Copy constructor
    vector(const vector& other) {
        copy_from_other(other.data(), other.size(), other.capacity());
    }

    vector(const T* src, isz src_len) {
        copy_from_other(src, src_len, src_len);
    }
    void assign_data(const T* src, isz src_len) {
        copy_from_other(src, src_len, src_len);
    }

    void swap(vector& other) noexcept {
        sdf::swap(m_data, other.m_data);
        sdf::swap(m_size, other.m_size);
        sdf::swap(m_capacity, other.m_capacity);
    }

    // Assignement operator
    // Copy Swap idiom
    vector& operator=(const vector& other) {
        // check for self assignment.
        if (this != &other) {
            vector temp(other); // Copy-constructor -- RAII
            temp.swap(*this); // Non-throwing swap
            // or
            //vector(other).swap(*this); //Copy-constructor and non-throwing swap
        }      
        // Old resources are released with the destruction of the temporary above
        return *this;
    }

    void copy_on_move(vector& other) noexcept {
        m_data = other.m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
    }

    void reset_on_move() noexcept {
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }

    // Move constructor.
    vector(vector&& other) noexcept {
        //printf("Move constructor called.\n");
        // Free original data.
        clear_memory();
        // Copy the source object data pointer & fields into this object.
        copy_on_move(other);
        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other.reset_on_move();        
    }

    // Move assignment.
    vector& operator=(vector&& other) noexcept {
        //printf("Move assignment called.\n");
        // Do not move the object into itself.
        if (this != &other) {
            clear_memory(); 
            copy_on_move(other);
            other.reset_on_move();
        }
        return *this;
    }    

    //constexpr vector(std::initializer_list<T> ilist) {
    //    //_Construct_n(_Convert_size<size_type>(_Ilist.size()), _Ilist.begin(), _Ilist.end());
    //    const isz list_size = ilist.end() - ilist.begin();
    //    resize(list_size);
    //    for (isz i=0; i<list_size; ++i) { m_data[i] = *(ilist.begin()+i); }
    //}

    isz size() const { return m_size; }
	isz capacity() const { return m_capacity; }	
    bool empty() const { return (size() == 0); }
	isz max_size() const { return ISZ_MAX; }

    const T* data() const { return m_data; }
	T* data() { return m_data; }

    const T& operator[] (isz i) const { return m_data[i]; }
	T& operator[] (isz i) { return m_data[i]; } 

    /*const T& at(isz i) const { 
		if (i >= 0 && i < size()) {
			return m_data[i]; 
		} else {
		}
	}
	T& at(isz i) { 
		if (i >= 0 && i < size()) {
			return m_data[i]; 
		} else {
		}
	} */

	const T& front() const { return m_data[0]; }
	T& front() { return m_data[0]; }
	const T& back() const { return m_data[m_size-1]; }
	T& back() { return m_data[m_size-1]; }


    void reserve_exact(isz count) {
        if (count == capacity()) { return; }
        // Do not reallocate on shrink.
        if (count <= size()) { return; }

        T* new_data = nullptr;
        create_new_object(new_data, m_data, count, m_size);
        destroy_old_memory_block(m_size);    
        set_to_new_memory_block(m_data, new_data);

        m_capacity = count;
    }

    void resize_exact(isz count, bool reserve_growth) {
        if (count == size()) { return; }

        // Expand.
        isz copy_size = size();
        // Shrink.
        if (count < size()) { copy_size = count; }

        isz final_count = count;
        if (reserve_growth) { final_count = next_capacity(count); }

        T* new_data = nullptr;
        create_new_object(new_data, m_data, final_count, copy_size);        
        destroy_old_memory_block(m_size);    
        set_to_new_memory_block(m_data, new_data);

        // Expand.
        if (count > size()) {
            for_range (i, size(), count) { sdf::element_construct(&m_data[i]); }
        }

        m_capacity = count;
        m_size = count;
    }

    //---------------------
    void resize(isz count) { 
        if (count > size()) {
            if (count > capacity()) {
                // Expand.
                // Memory not available, reallocate.
                resize_exact(count, false);
            } else {
                // Construct extra elements.
                // Memory available.
                for_range (i, size(), count) { sdf::element_construct(&m_data[i]); }
                m_size = count;
            }
        } else {
            // Shrink.
            // Destruct extra elements.
            // Memory not deallocated.
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
    
    void clear() {
        if (m_data) {
            for_range (i, 0, size()) { sdf::element_destruct(&m_data[i]); }            
        }
        m_size = 0;
        m_capacity = 0;
    }


    //---------------------
    void push_back(const T& element) {
        const isz required_size = size()+1;
        if (is_reserve_needed(required_size)) {
            reserve_growth(required_size);
        }
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
    

    //=========================================================
    using value_type = T;
    using const_iterator = vector_const_iterator<vector<T>>;
    using iterator = vector_iterator<vector<T>>;
    

    const_iterator begin() const noexcept { return const_iterator(m_data); }
    const_iterator end() const noexcept { return const_iterator(m_data + m_size); }

    iterator begin() noexcept { return iterator(m_data); }
    iterator end() noexcept { return iterator(m_data + m_size); }    
};



template<class T>
inline void vec_clear_memory(sdf::vector<T>& v) {
	v.clear_memory();
}

template<class T>
inline isz vec_size_bytes(const sdf::vector<T>& v) {
	return (sizeof(T) * v.size());
}


}



