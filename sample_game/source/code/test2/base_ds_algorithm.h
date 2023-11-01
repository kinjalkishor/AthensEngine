#pragma once

#include "base_def.h"

#include <limits>

namespace sdf 
{

class sys_allocator {
public:
    void* allocate(size_t size_bytes) { return malloc(size_bytes); }
    void deallocate(void* ptr) { free(ptr); }	
};

}

namespace sdf
{

//====================
// Optional
//====================
// no-value state indicator
struct tag_nullopt { 
    struct tag_f {};
    constexpr explicit tag_nullopt(tag_f) {}
};
inline constexpr tag_nullopt nullopt{tag_nullopt::tag_f{}};

template<class T>
class optional {
public:
    bool success = false;
    T val;

    optional() {}
    ~optional() {}

    // Success case
    optional(const T& value) : success(true), val(value) {}

    // Error case
	optional(const tag_nullopt) : success(false) {}

    explicit operator bool() const { return success; }

    const T value() const {
        return val;
    }

    T value() {
        return val;
    }

    const T value_or(const T& default_val) const {
        if (success) { 
            return val; 
        } else { 
            return default_val; 
        } 
    }

    T value_or(const T& default_val) {
        if (success) { 
            return val; 
        } else { 
            return default_val; 
        } 
    }
};
//=========================================================

inline size_t next_power2_floor(size_t x) {
    int power = 1;
	while (x >>= 1) { power <<= 1; }
    return power;
}
inline size_t next_power2_ceil(size_t x) {
	if (x <= 1) { return 1; }
    int power = 2;
    x--;
	while (x >>= 1) { power <<= 1; }
    return power;
}
// std::has_single_bit in <bit> header
inline bool is_power2(size_t x) {
    return (x != 0 && (x & (x - 1)) == 0);
}

//=========================================================
template<class T>
inline bool is_pod() { return (std::is_trivial<T>::value && std::is_standard_layout<T>::value); }

template<class T>
inline void copy_a(T* dest, const T* src, isz num) {
    if (sdf::is_pod<T>()) { 
        sdf::mem_copy(&dest[0], &src[0], num); 
    } else { 
        sdf::vec_copy(&dest[0], &src[0], num);  
    }
}

// Linear search
//indexof
template<class T>
inline sdf::optional<isz> vec_find_index(const T* data, isz size, const T& element) {
    for (isz i=0; i<size; ++i) {
        if (data[i] == element) { return i; }
    }
    //eprintfln("Element not found");
    return sdf::nullopt;
}


//==============================================================================
#if 0

// MSVC size claculation
template<class value_type>
inline constexpr isz SDF_STR_ALLOC_MASK     = sizeof(value_type) <= 1 ? 15
                                            : sizeof(value_type) <= 2 ? 7
                                            : sizeof(value_type) <= 4 ? 3
                                            : sizeof(value_type) <= 8 ? 1
                                            : 0;
template<class value_type>
inline isz str_calculate_growth(const isz requested_size, const isz old_capacity) { //, const isz max_limit) {
    const isz max_limit = std::numeric_limits<isz>::max(); //max_size();

    const size_t masked_size = requested_size | SDF_STR_ALLOC_MASK<value_type>;
    if (masked_size > max_limit) { // the mask overflows, settle for max_size()
        return max_limit;
    }

    if (old_capacity > max_limit - old_capacity / 2) { // similarly, geometric overflows
        return max_limit;
    }

    return sdf::tmax(scast<isz>(masked_size), old_capacity + old_capacity / 2);
}

inline isz vec_calculate_growth(isz requested_size, isz old_capacity) {
    // given old_capacity and requested_size, calculate geometric growth
    //const isz old_capacity = capacity;
    const isz max_limit = std::numeric_limits<isz>::max(); //max_size();

    if (old_capacity > max_limit - old_capacity / 2) {
        return max_limit; // geometric growth would overflow
    }

    const isz geometric = old_capacity + old_capacity / 2;

    if (geometric < requested_size) {
        return requested_size; // geometric growth would be insufficient
    }

    return geometric; // geometric growth is sufficient
}

#endif


}