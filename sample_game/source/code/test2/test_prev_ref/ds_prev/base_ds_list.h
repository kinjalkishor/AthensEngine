#pragma once

#include "base_types.h"
#include "base_def.h"
#include "base_print.h"
#include "base_ds_iterators.h"

#include <type_traits>
#include <initializer_list>

namespace sdf 
{



//---------------------------------------------

template<class T>
class list {
private:
    struct node {
	    T m_data;     	
	    node* prev;  	
	    node* next; 	
    };

    sys_allocator<node>* m_allocator = nullptr; 
    node* head = nullptr;  	
	node* tail = nullptr;   	
    isz m_size = 0;


    using value_type = T;
    using node_type = list<T>::node;
    using iterator = list_iterator<list<T>>;
    using const_iterator = list_const_iterator<list<T>>;

    node* allocate(size_t cnt) {
        if (m_allocator) {
            return m_allocator->allocate(cnt);
        } else {
            return sdf::sys_allocate<node>(cnt);
        }
    }
    void deallocate(node* ptr) { 
        if (m_allocator) {
            m_allocator->deallocate(ptr); 
        } else {
            sdf::sys_deallocate<node>(ptr);
        }
    }


    void clear_memory() {
        node* trav = head;        
        while(trav != nullptr) { 
            node* trav_curr = trav;
            trav = trav->next;
            free_node(trav_curr);
        }
        head = nullptr;
		tail = nullptr;
        m_size = 0;
    }

    void trav_forward() {
        node* trav = head;        
        printf("[ ");
        // Till end, end node next is nullptr
        while(trav != nullptr) { 
            //print("{}, ", trav->m_data);
            trav = trav->next;
        }
        printfln("]");
    }

    void trav_reverse() {
        node* trav = tail;        
        printf("[ ");
        // Till start, start node prev is nullptr
        while(trav != nullptr) { 
            //print("{}, ", trav->m_data);
            trav = trav->prev;
        }
        printfln("]");
    }

public:

    list() {}
    ~list() { clear_memory(); }

    constexpr list(std::initializer_list<T> ilist) {
         //_Construct_n(_Convert_size<size_type>(_Ilist.size()), _Ilist.begin(), _Ilist.end());
        const isz list_size = ilist.end() - ilist.begin();
        //resize(list_size);
        //for (isz i=0; i<list_size; ++i) { m_data[i] = *(ilist.begin()+i); }
        for (isz i=0; i<list_size; ++i) { push_back(*(ilist.begin()+i)); }
    }

    iterator begin() { return head; }
    iterator end() { return tail->next; } 
    const_iterator begin() { return head; }
    const_iterator end() { return tail->next; } 


    isz size() const { return m_size; }
    isz capacity() const { return m_size; }

    bool empty() { return (head == nullptr); }
    bool is_only_one_node() { return (head->next == nullptr); }

    void print_data() { trav_forward(); }

    node* create_node() {
	    node* new_node = nullptr;
        new_node = allocate(1);
        new_node->prev = nullptr;
        new_node->next = nullptr;
        sdf::element_construct<T>(&(new_node->m_data));
        return new_node;
    }

    void free_node(node* node_ptr) {
        if (node_ptr) {
            sdf::element_destruct<T>(&(node_ptr->m_data));
            node_ptr->prev = nullptr;
            node_ptr->next = nullptr;
            deallocate(node_ptr);
            node_ptr = nullptr;
        }
    }

    void set_first_node(node* curr) {
        head = curr;  
        tail = curr;
        curr->prev = nullptr; //first element
        curr->next = nullptr; //ony one element
    }    

    void push_back(const T& element) {
        node* curr = create_node();
        curr->m_data = element;
        if (empty()) {
            set_first_node(curr);
        }
        else {
            //println("except 1st node");
            // tail is at last node, insert after that
            curr->prev = tail;
            curr->next = nullptr;
            tail->next = curr;	
            // Set tail to new node
            tail = curr;
        }

        ++m_size;
    }

    void push_front(const T& element) {    
        node* curr = create_node();
        curr->m_data = element; 
        if (empty()) {
            set_first_node(curr);
        }
        else {
            // head is at first node, insert before that
            curr->next = head;
            curr->prev = nullptr;
            head->prev = curr;	
            // Set head to new node
	        head = curr;
        }

        ++m_size;
    }    

    void pop_back() {
        if (!empty()) {
            if (is_only_one_node()) {
                free_node(head);
                head = nullptr;
                tail = nullptr;
            } else {
                // If more than one node
			    // Find before_last node
                node* before_last = tail->prev;
			    // Delete last node at tail position
			    free_node(tail);
			    // Make before_last to last node
                before_last->next = nullptr;                
                tail = before_last;
            }

            --m_size;
        }
    }

    void pop_front() {
        if (!empty()) {
            if (is_only_one_node()) {
                free_node(head);
                head = nullptr;
                tail = nullptr;
            } else {        
                // If more than one node
                // Find after_first node
                node* after_first = head->next;
                // Delete first node at head position
                free_node(head);
                // Make after_first to first node
                after_first->prev = nullptr;                
                head = after_first;
            }

            --m_size;
        }
    }


    //sdf::optional<T&> find(const T& element) {
    //    node* trav = head;
    //    while(trav != nullptr) {
    //        if (trav->m_data == element) { return &(trav->m_data); }
    //        trav = trav->next;
    //    }
    //    //eprintfln("Element not found");
    //    return sdf::nullopt;
    //}
    
    //iterator insert(const_iterator _Where, _Ty&& _Val) { // insert _Val at _Where
    //    return emplace(_Where, _STD move(_Val));
    //}
};


}
