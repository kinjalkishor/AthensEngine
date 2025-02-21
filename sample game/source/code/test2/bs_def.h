#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>

#include <optional>

#define fm_msg_box_ok(msg)	MessageBoxW(nullptr, L##msg, L"Error", MB_OK)

//#define ARRAYSIZE(A) (sizeof(A)/sizeof((A)[0]))

template<class T> inline void com_release(T*& t) { if(t) { t->Release(); t = nullptr; } }	

template<class T> inline void safe_delete(T*& t) { if(t) { delete t; t = nullptr; } }
template<class T> inline void safe_delete_arr(T*& t) { if(t) { delete[] t; t = nullptr; } }


namespace sdf
{

template <class T, size_t N>
inline constexpr size_t size(const T (&)[N]) noexcept { return N; }
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t arr_cap(const T (&)[N]) noexcept { return N; }
// For null terminated char arrays, returns size without null char.
template <class T, ptrdiff_t N>
inline constexpr ptrdiff_t strz_cap(const T (&)[N]) noexcept { return N-1; }

template<class T> 
inline ptrdiff_t size_bytes(ptrdiff_t count) { return (count * sizeof(T)); }


template<class T> inline T tmin(const T a, const T b) { return (a < b) ? a : b; }
template<class T> inline T tmax(const T a, const T b) { return (a > b) ? a : b; }

// returns x in [low, high].
template<class T>
inline T clamp(const T& x, const T& low, const T& high) {
    if (x < low) { return low; }
    if (x > high) { return high; }
    return x;       
}

// Use std::swap or member swap for movable types.
template <class T>
inline void swap(T& a, T& b) {
    T temp(a);
    a = b;
    b = temp;
}


//====================
// size, Memory
//====================
// size to memset in bytes: count*sizeof(=size in bytes of type)
template<class T>
void mem_zero(T* dest, size_t count) { memset(dest, 0, count*sizeof(T)); }
//memcpy(&dst[dstIdx], &src[srcIdx], numElementsToCopy * sizeof(Element));
template<class T>
inline void mem_copy(T* dest, const T* src, size_t count) { memcpy(dest, src, count*sizeof(T)); }

template<class T>
inline void vec_copy(T* dest, const T* src, ptrdiff_t count) { for (ptrdiff_t i=0; i<count; ++i) { dest[i] = src[i]; } }



//==========================================
inline constexpr float k_aspect_16_9 = 1.77777777777777777778;
inline float get_aspect_ratio(float width, float height) { 
    // return 1:1 if height is zero.
    //1:1-1.0, 4:3-1.33, 16:9-1.77, 21:9-2.33
    return (height < 0.0001f) ? 1.0f : (width/height); 
}


//==========================================
// STRING
//==========================================
inline ptrdiff_t strz_len(const char* src) { return strlen(src); }
inline ptrdiff_t strz_len(const wchar_t* src) { return wcslen(src); }

inline void strz_to_lower(char* src) { for(ptrdiff_t i = 0; src[i] != '\0'; ++i) { src[i] = tolower(src[i]); } }
inline void strz_to_upper(char* src) { for(ptrdiff_t i = 0; src[i] != '\0'; ++i) { src[i] = tolower(src[i]); } }

inline void str_to_lower(char* src, ptrdiff_t src_len) { for(ptrdiff_t i = 0; i < src_len; ++i) { src[i] = tolower(src[i]); } }
inline void str_to_upper(char* src, ptrdiff_t src_len) { for(ptrdiff_t i = 0; i < src_len; ++i) { src[i] = toupper(src[i]); } }

inline bool strz_equals(const char* str1, const char* str2) { return !(strcmp(str1, str2)); }
inline bool strz_ci_equals(const char* str1, const char* str2) { return !(stricmp(str1, str2)); }
inline bool strz_equals(const wchar_t* str1, const wchar_t* str2) { return !(wcscmp(str1, str2)); }
inline bool strz_ci_equals(const wchar_t* str1, const wchar_t* str2) { return !(wcsicmp(str1, str2)); }

inline bool str_equals(const char* str1, ptrdiff_t str1_len, const char* str2, ptrdiff_t str2_len) { 
    if (str1_len != str2_len) { return false; }
    for (ptrdiff_t i = 0; i < str1_len; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
        return true;
    }
}

inline bool str_ci_equals(const char* str1, ptrdiff_t str1_len, const char* str2, ptrdiff_t str2_len) { 
    if (str1_len != str2_len) { return false; }
    for (ptrdiff_t i = 0; i < str1_len; ++i) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return false;
        }
        return true;
    }
}

//==========================================
// len and capacity are excluding null char at end of char string.
inline ptrdiff_t str_assign(char* dest, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
    ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
    memcpy(&dest[0], &src[0], copy_len*sizeof(char));
    dest[copy_len] = '\0';
    return copy_len;
}

inline ptrdiff_t str_append(char* dest, ptrdiff_t dest_len, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
    ptrdiff_t total_len = dest_len + src_len;  
    if (total_len > dest_capacity) { total_len = dest_capacity; }
    ptrdiff_t append_len = total_len - dest_len;
    memcpy(&dest[dest_len], &src[0], append_len*sizeof(char));
    dest[total_len] = '\0';
    return total_len;
}

inline ptrdiff_t str_assign(wchar_t* dest, ptrdiff_t dest_capacity, const wchar_t* src, ptrdiff_t src_len) {
    ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
    memcpy(&dest[0], &src[0], copy_len*sizeof(wchar_t));
    dest[copy_len] = L'\0';
    return copy_len;
}

inline ptrdiff_t str_append(wchar_t* dest, ptrdiff_t dest_len, ptrdiff_t dest_capacity, const wchar_t* src, ptrdiff_t src_len) {
    ptrdiff_t total_len = dest_len + src_len;  
    if (total_len > dest_capacity) { total_len = dest_capacity; }
    ptrdiff_t append_len = total_len - dest_len;
    memcpy(&dest[dest_len], &src[0], append_len*sizeof(wchar_t));
    dest[total_len] = L'\0';
    return total_len;
}

//==========================================
inline ptrdiff_t wstr_assign_ansi(wchar_t* dest, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
    ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
	const int dest_cap_with_null_char = dest_capacity+1;
	int result = MultiByteToWideChar(CP_UTF8, 0, src, copy_len, dest, dest_cap_with_null_char);
    if (!result) { return 0; }
	dest[copy_len] = L'\0';
	return copy_len;
}


//------------------------------------------------
inline ptrdiff_t mbstrz_len(const char* src) {
    int byte_size_with_nullchar = MultiByteToWideChar(CP_UTF8, 0, src, -1, nullptr, 0);
    if (!byte_size_with_nullchar) {
        return 0;
    } else {
        return byte_size_with_nullchar-1;
    }
}

// src contains terminating null char
inline wchar_t* wstrz_assign_mbsz_alloc(const char* src) {
    wchar_t* dest = nullptr;
    int count_with_null_char = MultiByteToWideChar(CP_UTF8, 0, src, -1, nullptr, 0);
    if (!count_with_null_char) {
        printf("Failed to convert string from UTF-8\n");
        return nullptr;
    }

    dest = static_cast<wchar_t*>(malloc(count_with_null_char*sizeof(wchar_t)));
    int result = MultiByteToWideChar(CP_UTF8, 0, src, -1, dest, count_with_null_char);
    if (!result) {
        printf("Failed to convert string from UTF-8\n");
        free(dest);
        return nullptr;
    }
    return dest;
}

// dest for return pointer must be mbstr.
inline char* mbstrz_assign_wcsz_alloc(const wchar_t* src) {
    char* dest = nullptr;
    int count_with_null_char = WideCharToMultiByte(CP_UTF8, 0, src, -1, nullptr, 0, nullptr, nullptr);
    if (!count_with_null_char) {
        printf("Failed to convert string to UTF-8\n");
        return nullptr;
    }

    dest = static_cast<char*>(malloc(count_with_null_char*sizeof(char)));
    int result = WideCharToMultiByte(CP_UTF8, 0, src, -1, dest, count_with_null_char, nullptr, nullptr);
    if (!result) {
        printf("Failed to convert string to UTF-8\n");
        free(dest);
        return nullptr;
    }
    return dest;
}


//==========================================
// STACK VECTOR
template<class T, ptrdiff_t N>
class vector_st {
private:
    template<class T> inline void element_construct(T* ptr) { new (ptr) T(); }
    template<class T> inline void element_copy_construct(T* ptr, const T& value) { new (ptr) T(value); }
    template<class T> inline void element_destruct(T* ptr) { ptr->~T(); }

    bool is_reserve_needed(ptrdiff_t required_size) { return (required_size > capacity()); }
public:
    T m_data[N] = {};
    ptrdiff_t m_size = 0;

    ptrdiff_t size() const { return m_size; }
    ptrdiff_t capacity() const { return N; }
    bool empty() { return (size() == 0); }

    const T* data() const { return m_data; }
	T* data() { return m_data; }    

    const T& operator [](ptrdiff_t i) const { return m_data[i]; }
	T& operator [](ptrdiff_t i) { return m_data[i]; } 

    void clear() {
        for (ptrdiff_t i=0; i < size(); ++i) { element_destruct(&m_data[i]); }
        m_size = 0;        
    }

    
    void resize(ptrdiff_t count) {
        if (count == size()) { return; }

        if (count > size()) {
            // Expand.
            if (count > capacity()) {                
                // Memory not available, reallocate.                
                //allocate_new_block(count, geometric_growth);
                // Cannot reallocate fixed size, truncate.               
                count = capacity();
            }           
            // Memory available.
            // Construct extra elements.
            for (ptrdiff_t i=size(); i < count; ++i) { element_construct(&m_data[i]); }
            m_size = count;
        } else {
            // Shrink. 
            // Memory not deallocated.
            // Destruct extra elements.
            for (ptrdiff_t i=count; i < size(); ++i) { element_destruct(&m_data[i]); }
            m_size = count;
        }        
    }
 

    void push_back(const T& element) {
        const ptrdiff_t required_size = size()+1;
        if (is_reserve_needed(required_size)) {
            //allocate_new_block(required_size, true);
            // Cannot reallocate fixed size. Do nothing and exit.
            return;
        }
        element_copy_construct(&m_data[m_size], element);
        m_size += 1;             
    }

    void pop_back() {
        if (!empty()) {
            element_destruct(&m_data[m_size-1]);
            m_size -= 1;
        }
    }
};


// STACK STRING
template<class T, ptrdiff_t N>
class basic_string_st {
private:
    bool is_reserve_needed(ptrdiff_t required_size) { return (required_size > capacity()); }

    template<class T> inline constexpr T k_null_char();
    template <> inline constexpr char k_null_char<char>() { return '\0'; }
    template <> inline constexpr wchar_t k_null_char<wchar_t>() { return L'\0'; }

    template<class T> inline constexpr T k_default_char();
    template <> inline constexpr char k_default_char<char>() { return '-'; }
    template <> inline constexpr wchar_t k_default_char<wchar_t>() { return L'-'; }

    inline ptrdiff_t strz_len(const char* src) { return strlen(src); }
    inline ptrdiff_t strz_len(const wchar_t* src) { return wcslen(src); }

public:
    // CHANGED from vector_st
    // Allocate 1 more for null char
    T m_data[N+1] = {};
    ptrdiff_t m_size = 0;

    ptrdiff_t size() const { return m_size; }
    ptrdiff_t capacity() const { return N; }
    bool empty() { return (size() == 0); }

    const T* data() const { return m_data; }
    T* data() { return m_data; }    
    const T* c_str() const { return m_data; }  

    const T& operator [](ptrdiff_t i) const { return m_data[i]; }
    T& operator [](ptrdiff_t i) { return m_data[i]; } 


    void clear() {
        m_size = 0;    
        if (capacity() > 0) { m_data[0] = k_null_char<T>(); }
    }


    void resize(ptrdiff_t count) {
        if (count == size()) { return; }

        if (count > size()) {
            // Expand.
            if (count > capacity()) {                
                // Memory not available, reallocate.                
                //allocate_new_block(count, geometric_growth);
                // Cannot reallocate fixed size, truncate.               
                count = capacity();
            }           
            // Memory available.
            // Set elements to default char so that no element is null in expanded memory.
            for (ptrdiff_t i=size(); i < count; ++i) { m_data[i] = k_default_char<T>(); }
            m_size = count;
            m_data[m_size] = k_null_char<T>();
        } else {
            // Shrink.
            // Memory not deallocated.
            m_size = count;
            m_data[m_size] = k_null_char<T>();
        }        
    }


    void assign_data(const T* src, ptrdiff_t src_len) {
        //m_size = sdf::str_assign(m_data, capacity(), src, src_len);
        ptrdiff_t copy_len = (src_len > capacity()) ? capacity() : src_len;
        memcpy(&m_data[0], &src[0], copy_len*sizeof(T));
        m_data[copy_len] = k_null_char<T>();
        m_size = copy_len;
    }
    void assign(const T* src) { assign_data(src, strz_len(src)); }

    void append_data(const T* src, ptrdiff_t src_len) {
        //m_size = sdf::str_append(m_data, m_size, capacity(), src, src_len);
        ptrdiff_t total_len = dest_len + src_len;  
        if (total_len > capacity()) { total_len = capacity(); }
        ptrdiff_t append_len = total_len - dest_len;
        memcpy(&m_data[dest_len], &src[0], append_len*sizeof(T));
        m_data[total_len] = k_null_char<T>();
        m_size = total_len;
    }
    void append(const T* src) { append_data(src, strz_len(src)); }
};
template<int N> using string_st = basic_string_st<char, N>;
template<int N> using wstring_st = basic_string_st<wchar_t, N>;


//==========================================
// Linear search
template<class T>
inline std::optional<ptrdiff_t> vec_find_index(const T* data, ptrdiff_t count, const T& element) {
    for (ptrdiff_t i=0; i<count; ++i) {
        if (data[i] == element) { return i; }
    }
    return std::nullopt;
}




}