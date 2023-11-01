#pragma once

// CHECK:
// Allocates memory & store the pointer in vector, which is all freed when program exits.
class small_memory_vallocator {
public:
	std::vector<char*> mem_vector;

	small_memory_vallocator() {		
		// 8 KB
		mem_vector.reserve(1024);
	}

	~small_memory_vallocator() {
		for_range (i, 0, mem_vector.size()) {
			free(mem_vector[i]);
			mem_vector[i] = nullptr;
		}
	}

	void* allocate(size_t bytes) {
		char* result = scast<char*>(malloc(bytes));
		mem_vector.push_back(result);
		return result;
	}
};
//extern small_memory_vallocator g_smva;
small_memory_vallocator g_smva;