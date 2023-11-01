#pragma once

#include "base_types.h"
#include "base_def.h"
#include "base_print.h"

#include "base_ds_algorithm.h"


namespace sdf
{

template<class T>
class basic_string {
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
        // if requested_size is pow_of_2 return (next_pow_of_2 - 1), to make space for null_char.
        isz result = sdf::next_power2_ceil(requested_size);
        if (result == requested_size) {
            result = sdf::next_power2_ceil(requested_size+1);
        }
        // allocate count+1, making allocation pow_of_2 with space for null_char. 
        return result-1;

        //return sdf::vec_calculate_growth(requested_size, capacity());
		//return sdf::str_calculate_growth<T>(requested_size, capacity());
		//return requested_size;
	}

    bool is_reserve_needed(isz required_size) { return (required_size > capacity()); }

public:

    basic_string() {}


    void clear_memory() {
        if (m_data) {
            deallocate(m_data);            
            m_data = nullptr;
        }
        m_size = 0;
        m_capacity = 0;
    }

    virtual ~basic_string() { clear_memory(); }

    basic_string(isz count) {
        resize(count);
    }

    isz size() const { return m_size; }
	isz capacity() const { return m_capacity; }	
    bool empty() { return (size() == 0); }

    const T* data() const { return m_data; }
	T* data() { return m_data; }

    const T& operator[] (isz i) const { return m_data[i]; }
	T& operator[] (isz i) { return m_data[i]; }

    const T* c_str() const { return m_data; }

    void reserve_allocate(isz count, isz copy_size, isz old_size) {
        // Allocate new memory block
        // Different from vector, allocating one char extra for terminating null char.
        T* new_data = allocate(count + 1);
        //for_range (i, 0, copy_size) { sdf::element_construct(&new_data[i]); }
        // Copy old elements
        //for_range (i, 0, copy_size) { new_data[i] = m_data[i]; }
        //for_range (i, 0, copy_size) { sdf::element_copy_construct(&new_data[i], m_data[i]); }
        sdf::mem_copy(&new_data[0], &m_data[0], copy_size);

        // Dellocate old memory block
        //for_range (i, 0, old_size) { sdf::element_destruct(&m_data[i]); }
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

        m_data[m_size] = sdf::k_null_char<T>();
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

        m_data[m_size] = sdf::k_null_char<T>();
    }


    //---------------------
    // Different from vector, resize & reserve to next_power2_ceil
    void resize(isz count) { 
        if (count > size()) {
            if (count > capacity()) {
                // Expand.
                resize_exact(count, true);
            } else {
                // Construct extra elements.
                //for_range (i, size(), count) { sdf::element_construct(&m_data[i]); }
                m_size = count;
                m_data[m_size] = sdf::k_null_char<T>();
            }
        } else {
            // Shrink.
            // Destruct extra elements.
            //for_range (i, count, size()) { sdf::element_destruct(&m_data[i]); }
            m_size = count;
            m_data[m_size] = sdf::k_null_char<T>();
        }        
    }

    void reserve(isz count) {
        // Expand only.
        if (count > capacity()) {
            //reserve_exact(count);
            isz next_count = next_capacity(count);
            reserve_exact(next_count);            
        }
        // Do nothing on Shrink.
    }


    void shrink_to_fit() { 
        resize_exact(size()); 
    }   

    void assign_data(const T* src, isz src_len) {
        resize(src_len);
        sdf::mem_copy(&m_data[0], &src[0], size());
        m_data[m_size] = sdf::k_null_char<T>();
    }

    //---------------------

    void assign(const T* src) { assign_data(src, sdf::strfz_len(src)); }
	void assign(const basic_string& src) { assign_data(src.data(), src.size()); }

    basic_string(const T* src) { assign(src); }
    basic_string(const basic_string& src) { assign(src); }

	basic_string& operator=(const T* src) { return basic_string(src); }
	basic_string& operator=(const basic_string& src) { return basic_string(src); }


    basic_string& append_data(const T* src, isz src_len) {
        isz old_size = size();
        isz total_len = old_size + src_len;
        resize(total_len);
        sdf::mem_copy(&m_data[old_size], &src[0], src_len);
        m_data[m_size] = sdf::k_null_char<T>();
        return *this;        
    }	

    basic_string& append(const T* src) { return append_data(src, strz_len(src)); }
    basic_string& append(const basic_string& src) { return append_data(src.data(), src.size()); }
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
    isz src_len = sdf::strfz_len(src);
    str_wcs_from_mbs(dest, src, src_len);
}
inline void strz_mbs_from_wcs(string& dest, const wchar_t* src) {
    isz src_len = sdf::strfz_len(src);
    str_mbs_from_wcs(dest, src, src_len);
}

inline void str_wcs_from_mbs(wstring& dest, const string& src) {
    str_wcs_from_mbs(dest, src.data(), src.size());
}
inline void str_mbs_from_wcs(string& dest, const wstring& src) {
	str_mbs_from_wcs(dest, src.data(), src.size());
}

}