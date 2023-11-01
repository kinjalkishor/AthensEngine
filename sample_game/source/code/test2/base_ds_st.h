#pragma once

#include "base_types.h"
#include "base_def.h"

namespace sdf
{

template<class T, isz N>
class vector_st {
private:
    isz m_size = 0;
    T m_data[N] = {};

public:
    vector_st() {}
    ~vector_st() {}

    isz size() const { return m_size; }
    isz& size() { return m_size; }
	isz capacity() const { return N; }	

    const T* data() const { return m_data; }
	T* data() { return m_data; }

    const T& operator[] (isz i) const { return m_data[i]; }
	T& operator[] (isz i) { return m_data[i]; }    

    bool empty() { return (size() == 0); }

    void clear_memory() { 
        // CHANGED from resizable vector
        // Used only for resetting memory.
        // Not needed in destructor as stack allocated arrays will destruct elements when they go out of scope.
		if (m_size > 0) {
            for (isz i=0; i<size(); ++i) { sdf::element_destruct(&m_data[i]); } 
        }        
        m_size = 0;
	}   

    void resize(isz count) {
        if (count > size()) {
            // Expand
            if (count > capacity()) {
                // count >= size and capacity
                // Memory reallocation needed
                //resize_exact(count); 
                // CHANGED from resizable vector                
                if (count == size()) { return; }
                // Fixed vector cannot allocate more memory than capacity.
                // Treat count as equal to capacity now since count is more than capacity.
                for_range (i, size(), capacity()) { sdf::element_construct(&m_data[i]); }
                m_size = capacity();
            } else {
                // count > size but less than capacity
                // Construct extra elements
                for_range (i, size(), count) { sdf::element_construct(&m_data[i]); }
                m_size = count;
            }
        } else {
            // Shrink
            for_range (i, count, size()) { sdf::element_destruct(&m_data[i]); }
            m_size = count;
        }
    }

    void push_back(const T& element) {
        const isz required_size = size()+1;
        if (is_reserve_needed(required_size)) {
            //reserve_growth(required_size);
            // CHANGED from resizable vector
            // Cannot add element beyond cpacity to fixed vector.
            // Do nothing            
            return;
        }
        //sdf::element_construct(&m_data[m_size]); m_data[m_size] = element;
        sdf::element_copy_construct(&m_data[m_size], element);
        ++m_size;             
    }


    void insert_pos(isz pos_index, const T& element) {
        const isz N = 1;
        const isz old_size = size();
        const isz required_size = size()+N;
        isz last_pos = required_size-1;
        // Insert only if pos inside range
        if (pos_index <= old_size) { 
            if (is_reserve_needed(required_size)) {
                //reserve_growth(required_size);
                // CHANGED from resizable vector
                // Cannot increase capacity.
                // Make last_pos position to last element
                last_pos = capacity()-1;
            }
            // Construct one more element at end
            sdf::element_construct(&m_data[last_pos]);
            for (isz i=last_pos; i>pos_index; --i) { m_data[i] = m_data[i-N]; }
            // Insert element after shifting.
            m_data[pos_index] = element;
            ++m_size;
        }
    }

    void pop_back() {
        if (!empty()) {
            sdf::element_destruct(&m_data[m_size-1]);
            --m_size;
        }
    }

    void remove_pos(isz pos_index) {
        if (pos_index <= size()) {
            for (isz i=pos_index; i<size(); ++i) { m_data[i] = m_data[i+1]; }
            sdf::element_destruct(&m_data[m_size-1]);
            --m_size;
        }
    }
};


//-----------------------------------------
template<class T, isz N>
class basic_string_st {
private:
    isz m_size = 0;
    // CHANGED from vector_st
    // Allocate 1 more for null char
    T m_data[N+1] = {};

public:	
    basic_string_st() {}
    ~basic_string_st() {}
    //basic_string_st(const T* src) { assign(src); }  

    isz size() const { return m_size; }
    isz& size() { return m_size; }
	isz capacity() const { return N; }	

    const T* data() const { return m_data; }
	T* data() { return m_data; }
    const T* c_str() const { return m_data; }

    const T& operator[] (isz i) const { return m_data[i]; }
	T& operator[] (isz i) { return m_data[i]; }

    bool empty() { return (size() == 0); }

    void assign_data(const T* src, isz src_len) {
        m_size = sdf::strf_assign(m_data, capacity(), src, src_len);
    }
    void assign(const T* src) { assign_data(src, sdf::strfz_len(src)); }

    void append_data(const T* src, isz src_len) {
        m_size = sdf::strf_append(m_data, m_size, capacity(), src, src_len);
    }
    void append(const T* src) { append_data(src, sdf::strfz_len(src)); }
};

template<int N>
using string_st = basic_string_st<char, N>;
template<int N>
using wstring_st = basic_string_st<wchar_t, N>;

template<int N>
void string_st_wcs_from_mbs(wstring_st<N>& dest, const char* src, isz src_len) {
    dest.size() = sdf::strf_wcs_from_mbs(dest.data(), dest.capacity(), src, src_len);
}
template<int N>
void string_st_mbs_from_wcs(string_st<N>& dest, const wchar_t* src, isz src_len) {
    dest.size() = sdf::strf_mbs_from_wcs(dest.data(), dest.capacity(), src, src_len);
}

template<int N>
void string_stz_wcs_from_mbs(wstring_st<N>& dest, const char* src) {
    isz src_len = sdf::strfz_len(src);
    dest.size() = sdf::strf_wcs_from_mbs(dest.data(), dest.capacity(), src, src_len);
}
template<int N>
void string_stz_mbs_from_wcs(string_st<N>& dest, const wchar_t* src) {
    isz src_len = sdf::strfz_len(src);
    dest.size() = sdf::strf_mbs_from_wcs(dest.data(), dest.capacity(), src, src_len);
}

}