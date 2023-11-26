#pragma once

#include "base_ds_algorithm.h"

namespace sdf 
{

template<class T>
class data_node {
public:
	T m_data;
	data_node<T>* prev;
	data_node<T>* next;
};

template<class T>
class list {
public:
	sys_allocator* m_allocator = nullptr; 

	data_node<T>* head = nullptr;
	data_node<T>* tail = nullptr;


	data_node<T>* allocate(size_t cnt) {
        if (m_allocator) {
            return static_cast<data_node<T>*>(m_allocator->allocate(sizeof(data_node<T>)*cnt));
        } else {
            //println("DEFAULT ALLOC CALLED");
            return static_cast<data_node<T>*>(malloc(sizeof(data_node<T>)*cnt));
        }
    }
    void deallocate(data_node<T>* ptr) { 
        if (m_allocator) {
            m_allocator->deallocate(ptr); 
        } else {
            free(ptr);
        }
    }

	

};


}
