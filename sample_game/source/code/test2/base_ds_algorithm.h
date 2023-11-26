#pragma once

#include "base_def.h"

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


}