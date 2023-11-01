#pragma once

//#include <cstdint>
#include <iostream>

#include "base_types.h"

//========================================================================
// ARENA
//========================================================================

// Machine word size. Depending on the architecture, can be 4 or 8 bytes.
using word_t = intptr_t;

// Allocated block of memory. Contains the object header structure,
// and the actual payload pointer.
struct Block { 
	// -------------------------------------
	// 1. Object header 

	// Block size.
	size_t size; 
	// Whether this block is currently used.
	bool used; 
	// Next block in the list.
	Block *next;
 
	// -------------------------------------
	// 2. User data 

	// Payload pointer.
	word_t data[1]; 
};


//========================================================================
// POOL
//========================================================================

struct Chunk {
	// When a chunk is free, the `next` contains the address of the next chunk in a list.
	// When it's allocated, this space is used by the user.
	Chunk *next;
};



// The allocator class.
// Features:
// - Parametrized by number of chunks per block
// - Keeps track of the allocation pointer
// - Bump-allocates chunks
// - Requests a new larger block when needed 
class PoolAllocator {
public:
	PoolAllocator(size_t chunksPerBlock)
	: mChunksPerBlock(chunksPerBlock) 
	{}
 
	void *allocate(size_t size) {
		// No chunks left in the current block, or no any block
		// exists yet. Allocate a new one, passing the chunk size: 
		if (mAlloc == nullptr) {
			mAlloc = allocateBlock(size);
		}
	}
	void deallocate(void *ptr, size_t size);
 
private:
	// Number of chunks per larger block.
	size_t mChunksPerBlock;
	// Allocation pointer.
	Chunk *mAlloc = nullptr; 


	// Allocates a larger block (pool) for chunks.
	// Allocates a new block from OS.
	// Returns a Chunk pointer set to the beginning of the block.
	Chunk *allocateBlock(size_t chunkSize) {
		std::cout << "\nAllocating block (" << mChunksPerBlock << " chunks):\n\n";
 
		size_t blockSize = mChunksPerBlock * chunkSize;
 
		// The first chunk of the new block.
		Chunk *blockBegin = rcast<Chunk *>(malloc(blockSize));
 
		// Once the block is allocated, we need to chain all
		// the chunks in this block:
 
		Chunk *chunk = blockBegin;
 
		for (int i = 0; i < mChunksPerBlock - 1; ++i) {
			chunk->next = rcast<Chunk *>(rcast<char *>(chunk) + chunkSize);
			chunk = chunk->next;
		}
 
		chunk->next = nullptr;
 
		return blockBegin;
	}

};