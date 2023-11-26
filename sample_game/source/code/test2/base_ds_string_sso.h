#pragma once

#pragma once

#include "base_def.h"
#include "base_print.h"
#include "base_ds_algorithm.h"

#include "base_ds_iterators.h"

#include <initializer_list>


namespace sdf
{


template<class T>
class basic_string {
private:
    sys_allocator* m_allocator = nullptr; 
    isz m_size = 0;
	//isz m_capacity = 0;      
    T* m_data = sbuffer; 

    static const isz sso_cap = 31;
    union {
        isz m_capacity = 0;      
        T sbuffer[sso_cap+1];
    };
    bool m_allocated = false;

    bool is_sso() const { return (!m_allocated); }

    

	T* allocate(size_t cnt) {
        if (m_allocator) {
            return static_cast<T*>(m_allocator->allocate(sizeof(T)*cnt));
        } else {
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
		// if requested_size is pow_of_2 return (next_pow_of_2 - 1), to make space for null_char.
        isz result = sdf::next_power2_ceil(requested_size);
        if (result == requested_size) {
            result = sdf::next_power2_ceil(requested_size+1);
        }
        // allocate count+1, making allocation pow_of_2 with space for null_char. 
        return result-1;
	}

    bool is_reserve_needed(isz required_size) { return (required_size > capacity()); }

public:

	basic_string() {}
    virtual ~basic_string() { clear_memory(); }

    void clear_memory() {
        if (!is_sso()) {
            if (m_data) {            
                deallocate(m_data);            
                m_data = nullptr;
            }
		    m_capacity = 0;
            m_allocated = false;
        }
        m_size = 0;        
    }
    
	void clear() {
        if (!is_sso()) {
		    m_capacity = 0;
        }
        m_size = 0;        
    }

    basic_string(isz count) {
        resize(count);
    }


    void create_new_object(T*& dest_ptr, const T* src_ptr, isz count, isz copy_size) {
		// Allocate new memory block
        // Different from vector, allocating one char extra for terminating null char.
        println("allocated: {}", count + 1);
        dest_ptr = allocate(count + 1);        
        sdf::mem_copy(&dest_ptr[0], &src_ptr[0], copy_size);
        dest_ptr[copy_size] = sdf::k_null_char<T>();        
	}
	void destroy_old_memory_block(isz old_size) {
        if (!is_sso()) {
		    // Dellocate old memory block
		    if (m_data) {
                println("HI, {}", m_allocated);
                deallocate(m_data);   
            }
        }
	}
	void set_to_new_memory_block(T*& dest_ptr, T*& src_ptr) {
		// Point data to new memory block
        dest_ptr = src_ptr;
        src_ptr = nullptr;
        m_allocated = true;
	}

	void copy_from_other(const T* src, isz src_len, isz src_capacity) {        
        if ((src_len > sso_cap) || m_allocated) {
            println("alloc copy_from_other: {}, {}", src_len, src_capacity);
		    T* new_data = nullptr;
		    create_new_object(new_data, src, src_capacity, src_len);
		    destroy_old_memory_block(m_size);      
		    set_to_new_memory_block(m_data, new_data);

		    m_capacity = src_capacity;
        } else {
            println("sso copy_from_other: {}, {}", src_len, src_capacity);
            sdf::mem_copy(&sbuffer[0], &src[0], src_len);
            sbuffer[src_len] = sdf::k_null_char<T>();
            m_data = sbuffer;
        }
        m_size = src_len;        
    }    


    // Copy constructor
    basic_string(const basic_string& other) {
        copy_from_other(other.data(), other.size(), other.capacity());
    }

    basic_string(const T* src, isz src_len) {
        copy_from_other(src, src_len, src_len);
    }
    basic_string& assign_data(const T* src, isz src_len) {
        copy_from_other(src, src_len, src_len); 
        return *this;
    }

    void swap(basic_string& other) noexcept {
        if (!is_sso()) {
            sdf::swap(m_data, other.m_data);
		    sdf::swap(m_capacity, other.m_capacity);
        } else {
            sdf::mem_copy(&m_data[0], &other.m_data[0], other.m_size);
            m_data[other.m_size] = sdf::k_null_char<T>();
        }
        sdf::swap(m_size, other.m_size);        
    }

    // Assignement operator
    // Copy Swap idiom
    basic_string& operator =(const basic_string& other) {
        // check for self assignment.
        if (this != &other) {
            basic_string temp(other); // Copy-constructor -- RAII
            temp.swap(*this); // Non-throwing swap
            // or
            //basic_string(other).swap(*this); //Copy-constructor and non-throwing swap
        }      
        // Old resources are released with the destruction of the temporary above
        return *this;
    }

    void copy_on_move(basic_string& other) noexcept {
        if (!is_sso() && !other.is_sso()) {
            m_data = other.m_data;
		    m_capacity = other.m_capacity;
        } else {
            sdf::mem_copy(&m_data[0], &other.m_data[0], other.m_size);
            m_data[other.m_size] = sdf::k_null_char<T>();
        }
        m_size = other.m_size;        
    }

    void reset_on_move() noexcept {
        if (!is_sso()) {
            m_data = nullptr;
		    m_capacity = 0;
        }
        m_size = 0;        
    }

    // Move constructor.
    basic_string(basic_string&& other) noexcept {
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
    basic_string& operator =(basic_string&& other) noexcept {
        //printf("Move assignment called.\n");
        // Do not move the object into itself.
        if (this != &other) {
            clear_memory(); 
            copy_on_move(other);
            other.reset_on_move();
        }
        return *this;
    }    

    constexpr basic_string(::std::initializer_list<T> ilist) {
        //_Construct_n(_Convert_size<size_type>(_Ilist.size()), _Ilist.begin(), _Ilist.end());
        const isz list_size = ilist.end() - ilist.begin();
        resize(list_size);
        for (isz i=0; i<list_size; ++i) { m_data[i] = *(ilist.begin()+i); }
		m_data[list_size] = sdf::k_null_char<T>();
    }

    isz size() const { return m_size; }
	isz capacity() const { return ((!is_sso()) ? m_capacity : sso_cap); }	
    bool empty() const { return (size() == 0); }
	isz max_size() const { return ISZ_MAX; }

    const T* data() const { return m_data; }
	T* data() { return m_data; }

    const T& operator [](isz i) const { return m_data[i]; }
	T& operator [](isz i) { return m_data[i]; } 

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

    void sbuffer_recopy() {
        sdf::mem_copy(&sbuffer[0], &m_data[0], m_size);
        sbuffer[m_size] = sdf::k_null_char<T>();
        println("deallocated");
        deallocate(m_data);            
        m_data = sbuffer;
    }

    void reserve_exact(isz count) {
        if (count == capacity()) { return; }
        // Do not reallocate on shrink.
        if (count <= size()) { return; }

        if ((count > sso_cap) || m_allocated) {
            T* new_data = nullptr;
            create_new_object(new_data, m_data, count, m_size);
            destroy_old_memory_block(m_size);    
            set_to_new_memory_block(m_data, new_data);

            m_capacity = count;
        } else {
            sbuffer_recopy();
        }
    }

    void resize_exact(isz count, bool reserve_growth) {
        if (count == size()) { return; }

        // Expand.
        isz copy_size = size();
        // Shrink.
        if (count < size()) { copy_size = count; }

        if ((count > sso_cap) || m_allocated) {
            isz final_count = count;
            if (reserve_growth) { final_count = next_capacity(count); }

            T* new_data = nullptr;
            create_new_object(new_data, m_data, final_count, copy_size);        
            destroy_old_memory_block(m_size);    
            set_to_new_memory_block(m_data, new_data);

            // Expand.
            // No elemnt construction required for string.

            m_capacity = count;
        } else {
            sbuffer_recopy();
        }
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
                m_size = count;                
            }
        } else {
            // Shrink.
            // Destruct extra elements.
            // Memory not deallocated.            
            m_size = count;            
        }        
		m_data[m_size] = sdf::k_null_char<T>();
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


    //---------------------
    void push_back(const T& element) {
        const isz required_size = size()+1;
        if ((required_size > sso_cap) || m_allocated) {
            if (is_reserve_needed(required_size)) {
                reserve_growth(required_size);
            }
        }
        m_data[m_size] = element;
        m_size += 1;         
        m_data[m_size] = sdf::k_null_char<T>();
    }

    void pop_back() {
        if (!empty()) {            
            m_size -= 1;
            m_data[m_size] = sdf::k_null_char<T>();
            //if (!(m_size > sso_cap)) { sbuffer_recopy(); }
        }
    }    


    void insert_pos(isz pos_index, const T& element) {
        // Extra space = size()+N
        const isz required_size = size()+1;         
        if (pos_index <= size()) {
            if ((required_size > sso_cap) || m_allocated) {
                if (is_reserve_needed(required_size)) {
                    reserve_growth(required_size);
                }
            }
            // one less than required_size.
            const isz last_pos_index = required_size-1;
            // Construct extra elements at end.            
            for (isz i=last_pos_index; i>pos_index; --i) { m_data[i] = m_data[i-1]; }
            // Insert element after shifting.
            m_data[pos_index] = element;
            m_size += 1;
            m_data[m_size] = sdf::k_null_char<T>();
        }        
    }

    void remove_pos(isz pos_index) {
        const isz last_pos_index = size()-1;
        if (pos_index <= size()) {
            for (isz i=pos_index; i<size(); ++i) { m_data[i] = m_data[i+1]; }            
            m_size -= 1;
            m_data[m_size] = sdf::k_null_char<T>();
            //if (!(m_size > sso_cap)) { sbuffer_recopy(); }
        }
    }
    
	sdf::optional<isz> find_index(const T& element) {
        return sdf::vec_find_index(data(), size(), element);
    }    
	
    //=========================================================
    using value_type      = T;
    using pointer         = T*;
    using const_pointer   = const T*;
    using reference       = T&;
    using const_reference = const T&;
    using size_type       = isz;
    using difference_type = isz;

    using const_iterator = vector_const_iterator<basic_string<T>>;
    using iterator = vector_iterator<basic_string<T>>;
    

    const_iterator begin() const noexcept { return const_iterator(m_data); }
    const_iterator end() const noexcept { return const_iterator(m_data + m_size); }

    iterator begin() noexcept { return iterator(m_data); }
    iterator end() noexcept { return iterator(m_data + m_size); }    


    //=========================================================
    const T* c_str() const { return m_data; }

    basic_string& assign(const T* src) { return assign_data(src, sdf::strfz_len(src)); }
	basic_string& assign(const basic_string& src) { return assign_data(src.data(), src.size()); }

    basic_string(const T* src) { assign_data(src, sdf::strfz_len(src)); }

	basic_string& operator =(const T* src) { return assign_data(src, sdf::strfz_len(src)); }

    basic_string& append_data(const T* src, isz src_len) {
        isz old_size = size();
        isz total_len = old_size + src_len;
        resize(total_len);
        sdf::mem_copy(&m_data[old_size], &src[0], src_len);
        m_data[m_size] = sdf::k_null_char<T>();
        return *this;        
    }	

    basic_string& append(const T* src) { return append_data(src, sdf::strfz_len(src)); }
    basic_string& append(const basic_string& src) { return append_data(src.data(), src.size()); }

    bool operator ==(const T* src) { return sdf::strfz_equals(m_data, src); }
    bool operator ==(const basic_string& src) { return sdf::strfz_equals(m_data, src.c_str()); }
};


using string = basic_string<char>;
using wstring = basic_string<wchar_t>;


// resize only copy_len since sdf::string reserves space for null char surely.
inline void str_wcs_from_mbs(wstring& dest, const char* src, isz src_len) {
    const isz copy_len = src_len;
    if (copy_len > dest.size()) { dest.resize(copy_len); }
	sdf::mb_wcs_from_mbs(dest.data(), dest.size(), src, copy_len);
	dest[copy_len] = sdf::k_null_char<wchar_t>();
}
inline void str_mbs_from_wcs(string& dest, const wchar_t* src, isz src_len) {
	const isz copy_len = src_len;
    if (copy_len > dest.size()) { dest.resize(copy_len); }
	sdf::mb_mbs_from_wcs(dest.data(), dest.size(), src, copy_len);
	dest[copy_len] = sdf::k_null_char<char>();
}

inline void strz_wcs_from_mbs(wstring& dest, const char* src) {
    str_wcs_from_mbs(dest, src, sdf::strfz_len(src));
}
inline void strz_mbs_from_wcs(string& dest, const wchar_t* src) {
    str_mbs_from_wcs(dest, src, sdf::strfz_len(src));
}

inline void str_wcs_from_mbs(wstring& dest, const string& src) {
    str_wcs_from_mbs(dest, src.data(), src.size());
}
inline void str_mbs_from_wcs(string& dest, const wstring& src) {
	str_mbs_from_wcs(dest, src.data(), src.size());
}

}