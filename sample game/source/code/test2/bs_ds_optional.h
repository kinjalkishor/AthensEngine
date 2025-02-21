#pragma once

namespace sdf 
{

// CHECK:
// OPTIONAL
struct tag_nullopt { 
    struct tag_f {};
    constexpr explicit tag_nullopt(tag_f) {}
};
inline constexpr tag_nullopt nullopt{tag_nullopt::tag_f{}};

template<class T>
class optional {
public:
    bool has_value = false;    
    T val;

    // Success case
    optional(const T& value) : has_value(true), val(value) {}
    // Error case	
    optional(const tag_nullopt) : has_value(false), val(T{}) {}

    optional(const optional& other) {
        if (other.has_value) { val = other.val; }
        has_value = other.has_value;
    }
    optional& operator=(const optional& other) {
        if (other.has_value) { val = other.val; }
        has_value = other.has_value;
    }

    explicit operator bool() const { return has_value; }

    const T value() const { return val; }
    T value() { return val; }

    const T value_or(const T& default_val) const { return (has_value ? val : default_val); }
    T value_or(const T& default_val) { return (has_value ? val : default_val); }

};


//-----------------------------------
// CHECK:
// SPAN
template<class T>
class span {
public:
    T* m_data = nullptr;
    intmax_t m_size = 0;     
};

template <class T>
class basic_string_view { 
public:
    const T* m_data = nullptr;
    intmax_t m_size = 0;    
};

using string_view = basic_string_view<char>;
using wstring_view = basic_string_view<wchar_t>;


//-----------------------------------
// CHECK:
// UNIQUE_PTR
template<class T>
class unique_ptr {
public:
	T* m_ptr;

	unique_ptr() {}
	~unique_ptr() { delete m_ptr; }

	void operator=(T* ptr) { m_ptr = ptr; }

	T* operator*() { return m_ptr; }

	T* operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

	template<class U>
	T* make_unique() { m_ptr = new U; return static_cast<T*>(m_ptr); }
};


}