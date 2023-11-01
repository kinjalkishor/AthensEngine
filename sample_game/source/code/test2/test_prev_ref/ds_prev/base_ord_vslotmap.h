#pragma once

#include "base_types.h"
#include "base_io.h"

#include <vector>
#include <string>
#include <optional>

#include "base_ext_unord_map.h"
//#include <unordered_map>

//-------
// check for find function to return pointer so value can be changed from returned pointer, 
// but after erase pointers to value inside ord_vslotmap will be invalidated

namespace sdf
{

template <class Key,
          class T>
class ord_vslotmap {
private:
	void insert_pos(const sdr::string& key_pos, const sdr::string& key, const T& elem) {
		size_t pos = key_index_map.find(key_pos)->second;		
		size_t pos_to_add = pos + 1;
		auto it_pos = data_vec.begin() + (pos_to_add);
		data_vec.insert(it_pos, std::pair(key, elem));
		key_index_map.insert({key, pos_to_add});
		// update key_index_map for shifted values
		for (size_t i = pos_to_add; i<data_vec.size(); ++i) {
			key_index_map.find(data_vec[i].first)->second = i;			
		}
	}

public:
	ank::unordered_dense::map<sdr::string, size_t> key_index_map;
	//sdr::unordered_map<sdr::string, size_t> key_index_map;
	// vector is again storing strings. Using more memory.
	sdr::vector<std::pair<sdr::string, T>> data_vec;

	void reserve(size_t new_capacity) {
		key_index_map.reserve(new_capacity);
		data_vec.reserve(new_capacity);
	}

	std::optional<T> find(const sdr::string& key) {
		auto it = key_index_map.find(key);
		if (it != key_index_map.end()) {
			size_t pos = it->second;
			return data_vec[pos].second;
		}
		else {
			eprintln("{} NOT FOUND", key);
			return std::nullopt;
		}
	}

	//std::optional<T>
	T& get(const sdr::string& key) {
		auto it = key_index_map.find(key);
		if (it != key_index_map.end()) {
			size_t pos = it->second;
			return data_vec[pos].second;
		}
		else {
			eprintln("{} NOT FOUND", key);
		}
	}

	void insert(const sdr::string& key, const T& elem) {
		// Do not insert empty keys
		if (!key.empty()) {
			data_vec.push_back(std::pair(key, elem));
			key_index_map.insert({key, data_vec.size()-1});
		}
	}
	

	void erase(const sdr::string& key) {
		size_t pos = key_index_map.find(key)->second;	
		key_index_map.erase({key});
		auto it_pos = data_vec.begin() + (pos);
		//vector.erase( vector.begin() + 3 ) //4th elem
		data_vec.erase(it_pos);		
		// update key_index_map for shifted values
		for (size_t i = pos; i<data_vec.size(); ++i) {
			key_index_map.find(data_vec[i].first)->second = i;			
		}
	}

	// add/remove element: 
	// add/remove from vector, shift elements.
	// -1/n index, add element +1/index
};
}


#if 0
	sdf::ord_vslotmap<dvar> a;
	a.push_back("zero", dvar(0));
	a.push_back("one", dvar(11));
	a.push_back("two", dvar(22));
	a.push_back("three", dvar(33));
	a.push_back("four", dvar(44));

	a.insert("one", "one_add", dvar(55));
	a.erase("one");

	for (auto const &k: a.key_index_map) {
		println("{}, {}", k.first, k.second);
		uint i = k.second;
		println("{}, {}", a.data_vec[i].first, a.data_vec[i].second.ival);
	}	
    for (auto const &k: a.data_vec) {
		println("{}, {}", k.first, k.second.ival);
	}

	//int b = a.find("two").value_or(dvar::k_error()).ival;
	//println("{}", b);

	a.get("two").set_int(999);
	float c = a.get("two").get_int();
	println("{}", c);
#endif