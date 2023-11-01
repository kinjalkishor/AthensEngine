#pragma once

#include "base_types.h"
#include "base_def.h"

#include "base_ds_algorithm.h"

namespace sdf
{

template<class T>
class vector_emf {
private:
    isz m_size = 0;
	isz m_capacity = 0;      
    T* m_data = nullptr;  

    virtual T* allocate(size_t cnt) {        
    }
    virtual void deallocate(T* ptr) { 
    }

    void clear_memory() {
        if (m_data) {
            for_range (i, 0, size()) { sdf::element_destruct(&m_data[i]); }
            deallocate(m_data);            
            m_data = nullptr;
        }
        m_size = 0;
        m_capacity = 0;
    }

    bool is_reserve_needed(isz required_size) { return (required_size > capacity()); }

public:

    //vector_emf() {}
    virtual ~vector_emf() { clear_memory(); }

    vector_emf(T* data, isz capacity) {
        m_data = data;
        m_size = 0;
        m_capacity = capacity;
    }

    isz size() const { return m_size; }
	isz capacity() const { return m_capacity; }	
    bool empty() { return (size() == 0); }
    isz size_bytes() const { return (sizeof(T) * size()); }

    const T* data() const { return m_data; }
	T* data() { return m_data; }

    const T& operator[] (isz i) const { return m_data[i]; }
	T& operator[] (isz i) { return m_data[i]; } 

    void resize(isz count) { 
        if (count > size()) {
            if (count > capacity()) {
                // Expand.
                //resize_exact(count, false);
                // CHANGED from resizable vector                
                if (count == size()) { return; }
                // Fixed vector cannot allocate more memory than capacity.
                // Treat count as equal to capacity now since count is more than capacity.
                for_range (i, size(), capacity()) { sdf::element_construct(&m_data[i]); }
                m_size = capacity();
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


    //---------------------
    void assign_data(const T* src, isz src_len) {
        isz copy_size = src_len;        
        sdf::truncate_len_to_capacity(copy_size, capacity());
        resize(copy_size);
        sdf::vec_copy(&m_data[0], &src[0], size());
    }

    void assign(const vector_emf& src) { assign_data(src.data(), src.size()); }
    vector_emf(const vector_emf& src) { assign(src); }
    vector_emf& operator=(const vector_emf& src) { return vector_emf(src); }


    void push_back(const T& element) {
        const isz required_size = size()+1;
        if (required_size <= capacity()) {
            sdf::element_copy_construct(&m_data[m_size], element);
            ++m_size; 
        }        
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
            sdf::truncate_len_to_capacity(required_size, capacity());
            // one less than required_size.
            const isz last_pos_index = required_size-1;
            // Construct extra elements at end.
            sdf::element_construct(&m_data[last_pos_index]);
            for (isz i=last_pos_index; i>pos_index; --i) { m_data[i] = m_data[i-1]; }
            // Insert element after shifting.
            m_data[pos_index] = element;
            m_size += 1;
            sdf::truncate_len_to_capacity(m_size, capacity());
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


//=========================================================================
template<class T>
class basic_string_emf {
private:
    isz m_size = 0;
	isz m_capacity = 0;      
    T* m_data = nullptr; 

    virtual T* allocate(size_t cnt) {        
    }
    virtual void deallocate(T* ptr) { 
    }

    void clear_memory() {
        if (m_data) {
            deallocate(m_data);            
            m_data = nullptr;
        }
        m_size = 0;
        m_capacity = 0;
    } 

    bool is_reserve_needed(isz required_size) { return (required_size > capacity()); }

public:

    //basic_string_emf() {}
    virtual ~basic_string_emf() { clear_memory(); }

    // capacity is capacity without null char, sdf::strz_cap static char array.
    basic_string_emf(T* data, isz capacity) {
        m_data = data;
        m_size = 0;
        m_capacity = capacity;
    }

    isz size() const { return m_size; }
	isz capacity() const { return m_capacity; }	
    bool empty() { return (size() == 0); }

    const T* data() const { return m_data; }
	T* data() { return m_data; }

    const T& operator[] (isz i) const { return m_data[i]; }
	T& operator[] (isz i) { return m_data[i]; }

    const T* c_str() const { return m_data; }
    

    void resize(isz count) { 
        if (count > size()) {
            if (count > capacity()) {
                // Expand.
                //resize_exact(count, true);
                // CHANGED from resizable vector                
                if (count == size()) { return; }
                // Fixed vector cannot allocate more memory than capacity.
                // Treat count as equal to capacity now since count is more than capacity.
                //for_range (i, size(), capacity()) { sdf::element_construct(&m_data[i]); }
                m_size = capacity();
                m_data[m_size] = sdf::k_null_char<T>();
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


    void assign_data(const T* src, isz src_len) {
        isz copy_size = src_len;        
        sdf::truncate_len_to_capacity(copy_size, capacity());
        resize(copy_size);
        sdf::mem_copy(&m_data[0], &src[0], size());
        m_data[m_size] = sdf::k_null_char<T>();
    }


    void assign(const T* src) { assign_data(src, sdf::strz_len(src)); }
	void assign(const basic_string_emf& src) { assign_data(src.data(), src.size()); }

    basic_string_emf(const T* src) { assign(src); }
    basic_string_emf(const basic_string_emf& src) { assign(src); }

	basic_string_emf& operator=(const T* src) { return basic_string_emf(src); }
	basic_string_emf& operator=(const basic_string_emf& src) { return basic_string_emf(src); }	


    basic_string_emf& append_data(const T* src, isz src_len) {
        isz old_size = dest_len;
        isz total_len = 0;
        isz append_len = 0;
        sdf::calculate_append_len_fixed(total_len, append_len, old_size, capacity(), src_len);
        resize(total_len);  
        //println("total_len: {}", total_len);            
        sdf::mem_copy(&m_data[old_size], &src[0], append_len);
        m_data[m_size] = sdf::k_null_char<T>();
        return *this;        
    }	

    basic_string_emf& append(const T* src) { return append_data(src, strz_len(src)); }
    basic_string_emf& append(const basic_string_emf& src) { return append_data(src.data(), src.size()); }
};



using string_emf = basic_string_emf<char>;
using wstring_emf = basic_string_emf<wchar_t>;


inline void str_wcs_from_mbs(wstring_emf& dest, const char* src, isz src_len) {
    tstr_wcs_from_mbs_fixed(dest, src, src_len);
}
inline void str_mbs_from_wcs(string_emf& dest, const wchar_t* src, isz src_len) {
    tstr_mbs_from_wcs_fixed(dest, src, src_len);
}
inline void str_wcs_from_mbs(wstring_emf& dest, const string_emf& src) {
    str_wcs_from_mbs(dest, src.data(), src.size());
}
inline void str_mbs_from_wcs(string_emf& dest, const wstring_emf& src) {
	str_mbs_from_wcs(dest, src.data(), src.size());
}


//char t1_buffer[4] = {};
//sdf::string_emf t1(t1_buffer, sdf::strz_cap(t1_buffer));
//t1.assign("HELLO");
//println("{}", t1.c_str());

//const char* wnd_title = "12345";
//char wstr_wnd_title_buffer[256];
//sdf::wstring_emf wstr_wnd_title(wstr_wnd_title_buffer, sdf::strz_cap(wstr_wnd_title_buffer));
//sdf::string_emf_wcs_from_mbs(wstr_wnd_title, wnd_title, sdf::strz_len(wnd_title));

//int t1_buffer[4] = {};
//sdf::vector_emf<int> t1(t1_buffer, sdf::arr_cap(t1_buffer));
//t1.push_back(1);
//t1.push_back(2);
//t1.push_back(3);
//t1.push_back(4);
//t1.push_back(5);
//for_range(i, 0, t1.size()) { println("{}", t1[i]); }

//==============================================================================
//====================================
// FIXED DYNAMIC CONTAINERS
//====================================
template<class T>
class vector_fixed : public vector_emf<T> {
private:
    sys_allocator<T>* m_allocator = nullptr; 

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

public:
    vector_fixed() {}

    vector_fixed(isz count) {
        m_data = allocate(count);
        m_size = 0;
        m_capacity = count;
    }

    ~vector_fixed() { clear_memory(); }

    vector_fixed(const vector_fixed& src) { assign(src); }
    vector_fixed& operator=(const vector_fixed& src) { return vector_fixed(src); }
};

template<class T>
class basic_string_fixed : public basic_string_emf<T> {
private:
    sys_allocator<T>* m_allocator = nullptr; 

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

public:
    basic_string_fixed() {}

    basic_string_fixed(isz count) {
        m_data = allocate(count);
        m_size = 0;
        m_capacity = count;
    }

    ~basic_string_fixed() { clear_memory(); }

    basic_string_fixed(const T* src) { assign(src); }
    basic_string_fixed(const basic_string_fixed& src) { assign(src); }

	basic_string_fixed& operator=(const T* src) { return basic_string_fixed(src); }
	basic_string_fixed& operator=(const basic_string_fixed& src) { return basic_string_fixed(src); }	
};

using string_fixed = basic_string_fixed<char>;
using wstring_fixed = basic_string_fixed<wchar_t>;

inline void str_wcs_from_mbs(wstring_fixed& dest, const char* src, isz src_len) {
    tstr_wcs_from_mbs_fixed(dest, src, src_len);
}
inline void str_mbs_from_wcs(string_fixed& dest, const wchar_t* src, isz src_len) {
    tstr_mbs_from_wcs_fixed(dest, src, src_len);
}
inline void str_wcs_from_mbs(wstring_fixed& dest, const string_fixed& src) {
    str_wcs_from_mbs(dest, src.data(), src.size());
}
inline void str_mbs_from_wcs(string_fixed& dest, const wstring_fixed& src) {
	str_mbs_from_wcs(dest, src.data(), src.size());
}

}