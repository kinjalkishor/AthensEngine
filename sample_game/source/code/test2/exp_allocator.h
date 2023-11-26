#pragma once

class pool_allocator1 {
public:
	char* head_block;

	char* head_8;
	char* head_16;

	void add_block(int new_size) {
		if (new_size >= 0 && new_size < 8) {

		} else (new_size >= 8 && new_size < 16) {
		}
	}
};