#pragma once

#include "base_types.h"
#include <vector>
#include <list>
#include <string>

// like std::unordered_map
//===========================================
/*
// Linear probing, open addressing (location or address of item is not determined by its hash value. 
void insert(string s) {
    //Compute the index using the hash function
    int index = hashFunc(s);
    //Search for an unused slot and if the index will exceed the hashTableSize then roll back
    while(hashTable[index] != "")
        index = (index + 1) % hashTableSize;
    hashTable[index] = s;
}
void search(string s) {
    //Compute the index using the hash function
    int index = hashFunc(s);
        //Search for an unused slot and if the index will exceed the hashTableSize then roll back
    while(hashTable[index] != s and hashTable[index] != "")
        index = (index + 1) % hashTableSize;
    //Check if the element is present in the hash table
    if(hashTable[index] == s)
        cout << s << " is found!" << endl;
    else
        cout << s << " is not found!" << endl;
}
*/
// simple hash function for illustrating hash collisions that just adds int values of char.
// abc, bca, cba all will have same hash.
unsigned long hash_function(const char *str, isz cap) {
    unsigned long i = 0;
    for (int j = 0; str[j]; j++) {
        i += str[j];
    }
    // Return a number within the bounds of the capacity of the hash table. Otherwise, it may access an unbound memory location
    return i % cap;
}

template<class T>
class hash_table_sc_oh {
public:
	std::vector<std::list<std::pair<std::string, T>>> m_item;
	isz m_size = 0;
	isz m_capacity = 10; //prime number?

	hash_table_sc_oh() {
		m_item.resize(m_capacity);
	}
	~hash_table_sc_oh() {}

	void insert(const std::string& key, T value) {
		isz index = hash_function(key.c_str(), m_capacity);
		// Inserting duplicates also for now
		m_item[index].push_back(value);
	}

	void find(const std::string& key) {
		isz index = hash_function(key.c_str(), m_capacity);
		auto it = m_item[index].find(key);

		/*
		for(int i = 0;i < hashTable[index].size();i++) {
            if(hashTable[index][i] == s) {
                cout << s << " is found!" << endl;
                return;
            }
        }
        cout << s << " is not found!" << endl;
		*/
	}
};