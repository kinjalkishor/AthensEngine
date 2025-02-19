#pragma once

#include <stdlib.h>

namespace sdf
{

class sys_allocator {
public:
    void* allocate(size_t size_bytes) { return malloc(size_bytes); }
    void deallocate(void* ptr) { free(ptr); }	
};


//=========================================================
template<class T> inline void element_construct(T* ptr) { new (ptr) T(); }
template<class T> inline void element_copy_construct(T* ptr, const T& value) { new (ptr) T(value); }
template<class T> inline void element_destruct(T* ptr) { ptr->~T(); }

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


}



