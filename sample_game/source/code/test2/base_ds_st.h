#pragma once

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

    const T& operator [](isz i) const { return m_data[i]; }
	T& operator [](isz i) { return m_data[i]; }    

    const T* begin() const { return &m_data[0]; }
    const T* end() const { return &m_data[m_size]; }

    bool empty() { return (size() == 0); }


    void clear() { 
		if (m_size > 0) { for_range (i, 0, size()) { sdf::element_destruct(&m_data[i]); } }        
        m_size = 0;
	}

    void resize(isz count) { 
        if (count > size()) {
            if (count > capacity()) {
                // Expand.
                // Memory not available, reallocate.
                // Only this if part changed from growable vector.                
                // Cannot reallocate fixed size, truncate.               
                count = capacity();
                if (count > size()) {
                    for_range (i, size(), count) { sdf::element_construct(&m_data[i]); }
                }
                // Cannot change capacity.
                m_size = count;
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


    void push_back(const T& element) {
        const isz required_size = size()+1;
        if (required_size > capacity()) {
            // Do nothing and exit.         
            return;
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

    void insert_pos(isz pos_index, const T& element) {
        // Extra space = size()+N
        const isz required_size = size()+1;         
        if (pos_index <= size()) {
            if (required_size > capacity()) {
                // Do nothing and exit.      
                return;
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

    void clear() { m_size = 0; }

    isz size() const { return m_size; }
    isz& size() { return m_size; }
	isz capacity() const { return N; }	

    const T* data() const { return m_data; }
	T* data() { return m_data; }
    const T* c_str() const { return m_data; }

    const T& operator [](isz i) const { return m_data[i]; }
	T& operator [](isz i) { return m_data[i]; }

    bool empty() { return (size() == 0); }


    basic_string_st& assign_data(const T* src, isz src_len) {
        m_size = sdf::strf_assign(m_data, capacity(), src, src_len); return *this;
    }
    basic_string_st& assign(const T* src) { return assign_data(src, sdf::strfz_len(src)); }

    basic_string_st& append_data(const T* src, isz src_len) {
        m_size = sdf::strf_append(m_data, m_size, capacity(), src, src_len); return *this;
    }
    basic_string_st& append(const T* src) { return append_data(src, sdf::strfz_len(src)); }

    basic_string_st& operator =(const T* src) { return assign_data(src, sdf::strfz_len(src)); }  
    bool operator ==(const T* src) { return sdf::strfz_equals(m_data, src); }
};

template<int N>
using string_st = basic_string_st<char, N>;
template<int N>
using wstring_st = basic_string_st<wchar_t, N>;

template<int N>
void string_st_wcs_from_mbs(wstring_st<N>& dest, const char* src, isz src_len) {
    dest.size() = sdf::strf_assign_mbs(dest.data(), dest.capacity(), src, src_len);
}
template<int N>
void string_st_mbs_from_wcs(string_st<N>& dest, const wchar_t* src, isz src_len) {
    dest.size() = sdf::strf_assign_wcs(dest.data(), dest.capacity(), src, src_len);
}

template<int N>
void string_stz_wcs_from_mbs(wstring_st<N>& dest, const char* src) {
    string_st_wcs_from_mbs(dest.data(), dest.capacity(), src, sdf::strfz_len(src));
}
template<int N>
void string_stz_mbs_from_wcs(string_st<N>& dest, const wchar_t* src) {
    string_st_mbs_from_wcs(dest.data(), dest.capacity(), src, sdf::strfz_len(src));
}



}