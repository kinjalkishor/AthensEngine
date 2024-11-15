#pragma once

#include <stdint.h>
#include <stdlib.h>

namespace sdf
{

class base_allocator {
public:
	void* allocate(size_t size_bytes) {
		return malloc(size_bytes);
	}

	void deallocate(void* ptr) {
		free(ptr);
	}
};


}