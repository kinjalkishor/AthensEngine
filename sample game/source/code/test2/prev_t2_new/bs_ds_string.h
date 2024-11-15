#pragma once

#include <stdint.h>
#include "bs_ds_base.h"
#include "bs_allocator.h"

namespace sdf
{

template<class T>
class string {
public:
	T* m_data = nullptr;
	intmax_t size = 0;
	intmax_t m_capacity = 0;
	base_allocator* m_allocator = nullptr;


	string() {
		m_allocator = new base_allocator;
	}
	~string() {

	}
};


//=======================================
}