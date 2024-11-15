#pragma once

namespace sdf
{

template<class T>
class unique_ptr {
public:
	T* m_ptr;

	unique_ptr() {}
	~unique_ptr() { delete m_ptr; }

	void operator=(T* ptr) { m_ptr = ptr; }

	T* operator*() { return m_ptr; }

	T* operator*() const {
        return *m_ptr;
    }

    T* operator->() const {
        return m_ptr;
    }

	template<class U>
	T* make_unique() { m_ptr = new U; return static_cast<T*>(m_ptr); }
};


template<class T>
class optional {
public:
	T m_data = {};
	bool m_success = true;
};


//===============================================================
}