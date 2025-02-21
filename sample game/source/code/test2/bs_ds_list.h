#pragma once

#include "bs_ds_util.h"

#include <stdint.h>
#include <stdlib.h>
#include <initializer_list>

namespace sdf 
{


template<class T>
class list {
private:
    struct node {
	    T m_data;     	
	    node* prev;  	
	    node* next; 	
    };

    node* head = nullptr;  	
	node* tail = nullptr;   	
    ptrdiff_t m_size = 0;
	sys_allocator* m_allocator = nullptr; 


	T* allocate(size_t count) {
        if (m_allocator) {
            return static_cast<T*>(m_allocator->allocate(count*sizeof(T)));
        } else {
            return static_cast<T*>(malloc(count*sizeof(T)));
        }
    }
    void deallocate(T* ptr) { 
        if (m_allocator) {
            m_allocator->deallocate(ptr); 
        } else {
            free(ptr);
        }
    }	

public:




};


}