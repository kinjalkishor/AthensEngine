#pragma once

#include <stdint.h>

namespace sdf 
{

template<class T, intmax_t N>
class vector_st {
public:
    intmax_t m_size = 0;
    T m_data[N] = {};

    intmax_t size() const { return m_size; }
	intmax_t capacity() const { return N; }	

    intmax_t& size_ref() { return m_size; }

};


//-----------------------------------------
//-----------------------------------------
template<class T, intmax_t N>
class basic_string_st {
public:
    intmax_t m_size = 0;
    // CHANGED from vector_st
    // Allocate 1 more for null char
    T m_data[N+1] = {};

    intmax_t size() const { return m_size; }
    intmax_t capacity() const { return N; }	

    intmax_t& size_ref() { return m_size; }

};


}