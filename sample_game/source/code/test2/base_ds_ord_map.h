#pragma once

//#include <string>
#include <vector>
#include <optional>

//#include <unordered_map>
#include "ds/martinus/unordered_dense.h"


namespace sdf
{

template <class Tcont>
class generic_const_iterator {
public:
    using value_type        = typename Tcont::value_type;
    using difference_type   = isz;
    using pointer           = const value_type*;
    using reference         = const value_type&;

    value_type* m_ptr = nullptr; // pointer to element in vector

    generic_const_iterator() {}
    generic_const_iterator(value_type* ptr) : m_ptr(ptr) {}
    virtual ~generic_const_iterator() {}

    reference operator*() const noexcept { return *m_ptr; }
    pointer operator->() const noexcept { return m_ptr; }

	generic_const_iterator& operator++() noexcept { ++m_ptr; return *this; }

	bool operator==(const generic_const_iterator& right) const noexcept { return m_ptr == right.m_ptr; }
    bool operator!=(const generic_const_iterator& right) const noexcept { return !(*this == right); }
};
template <class Tcont>
class generic_iterator : public generic_const_iterator<Tcont> {
public:
    using my_base = generic_const_iterator<Tcont>;

    using value_type        = typename Tcont::value_type;
    using difference_type   = isz;
    using pointer           = value_type*;
    using reference         = value_type&;

    generic_iterator() {}
    generic_iterator(value_type* ptr) : my_base(ptr) {}
    virtual ~generic_iterator() {}

	generic_iterator& operator++() noexcept { my_base::operator++(); return *this; }

    reference operator*() const noexcept { return const_cast<reference>(my_base::operator*()); }
    pointer operator->() const noexcept { return const_cast<pointer>(my_base::operator->()); }
};

template <class K, class T, 
	//class map_cont = std::pmr::unordered_map<K, size_t>,
	class map_cont = ankerl::unordered_dense::pmr::map<K, size_t>, 
	class data_cont = std::pmr::vector<T>>
class ord_map {
public:
	map_cont key_index_map;
	data_cont data_vec;


	using value_type = T;
    using const_iterator = generic_const_iterator<ord_map<K, T>>;
    using iterator = generic_iterator<ord_map<K, T>>;

	const_iterator begin() const noexcept { return const_iterator(&(*data_vec.begin())); }
    const_iterator end() const noexcept { return const_iterator(&(*data_vec.end())); }
    iterator begin() noexcept { return iterator(&(*data_vec.begin())); }
    iterator end() noexcept { return iterator(&(*data_vec.end())); }	
	

	void insert(const std::pair<K, T>& value) {
		data_vec.push_back(value.second);
		key_index_map.insert({value.first, data_vec.size()-1});
	}
	
	iterator find(const K& key) {
		auto it = key_index_map.find(key);
		if (it != key_index_map.end()) {
			size_t pos = it->second;
			return &data_vec[pos];
		} else {
			return end();
		}
	}
	const_iterator find(const K& key) const {
		return find(key);
	}

	//T get(const K& key, const T& value_or) const {
	//	auto temp = find(var_name);
	//	if (temp.m_ptr) {
	//		return *temp;
	//	} else {
	//		return value_or;
	//	}
	//}

	void set(const K& key, const T& value) {
		auto it = key_index_map.find(key);
		if (it != key_index_map.end()) {
			size_t pos = it->second;
			data_vec[pos] = value;
		}
	}

	void insert_at(const sdr::string& key_pos, const std::pair<K, T>& value) {
		auto it_pos = key_index_map.find(key_pos);		
		if (it_pos != key_index_map.end()) {
			size_t pos = it_pos->second;
			auto it_pos = data_vec.begin() + pos;
			data_vec.insert(it_pos, value.second);
			// Update indexes by +1 for addition of one element.
			for (auto& elem : key_index_map) {
				if (elem.second >= pos) {
					elem.second += 1;
				}			
			}
			// Insert value & update index at position.
			key_index_map.insert({value.first, pos});
		}
	}

	void erase(const sdr::string& key_pos) {
		auto it_pos = key_index_map.find(key_pos);		
		if (it_pos != key_index_map.end()) {
			size_t pos = it_pos->second;
			auto it_pos = data_vec.begin() + pos;
			data_vec.erase(it_pos);			
			// Update indexes by -1 for removal of one element.
			for (auto& elem : key_index_map) {
				if (elem.second >= pos) {
					elem.second -= 1;
				}			
			}
			key_index_map.erase(key_pos);
		}
	}

	void reserve(size_t new_capacity) {
		key_index_map.reserve(new_capacity);
		data_vec.reserve(new_capacity);
	}
};


}
