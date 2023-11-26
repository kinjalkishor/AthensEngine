#pragma once

namespace sdf
{

//----------------------------
// Iterator helpers
//----------------------------

template <class T_container>
auto begin(T_container& cont) -> decltype(cont.begin()) {
    return cont.begin();
}
template <class T_container>
auto begin(const T_container& cont) -> decltype(cont.begin()) {
    return cont.begin();
}
template <class T_container>
auto end(T_container& cont) -> decltype(cont.end()) {
    return cont.end();
}
template <class T_container>
auto end(const T_container& cont) -> decltype(cont.end()) {
    return cont.end();
}

template <class T, isz T_size>
constexpr T* begin(T (&array_a)[T_size]) {
    return array_a;
}
template <class T, isz T_size>
constexpr T* end(T (&array_a)[T_size]) {
    return array_a + T_size;
}

//----------------------------
// Iterators
//----------------------------
template <class T_vec>
class vector_const_iterator {
public:
    //using iterator_category = random_access_iterator_tag;
    using value_type        = typename T_vec::value_type;
    using difference_type   = isz;
    using pointer           = const value_type*;
    using reference         = const value_type&;


    value_type* m_ptr; // pointer to element in vector
    isz m_index = 0; // for getting count index i

    virtual ~vector_const_iterator() { m_index = 0; }

    vector_const_iterator() noexcept : m_ptr() {}

    vector_const_iterator(value_type* ptr) : m_ptr(ptr) {}

    reference operator*() const noexcept {
        return *m_ptr;
    }

    pointer operator->() const noexcept {
        return m_ptr;
    }

    vector_const_iterator& operator++() noexcept {
        ++m_index;
        ++m_ptr;
        return *this;
    }

    vector_const_iterator operator++(int) noexcept {
        ++m_index;
        vector_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    vector_const_iterator& operator--() noexcept {
        --m_index;
        --m_ptr;
        return *this;
    }

    vector_const_iterator operator--(int) noexcept {
        --m_index;
        vector_const_iterator temp = *this;
        --*this;
        return temp;
    }



    vector_const_iterator& operator+=(const difference_type offset) noexcept {
        m_index += offset;
        m_ptr += offset;
        return *this;
    }

    vector_const_iterator operator+(const difference_type offset) const noexcept {
        m_index += offset;
        vector_const_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend vector_const_iterator operator+(const difference_type offset, vector_const_iterator next) noexcept {
        m_index += offset;
        next += offset;
        return next;
    }

    vector_const_iterator& operator-=(const difference_type offset) noexcept {
        m_index -= offset;
        return *this += -offset;
    }

    vector_const_iterator operator-(const difference_type offset) const noexcept {
        m_index -= offset;
        vector_const_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    difference_type operator-(const vector_const_iterator& right) const noexcept {
        return m_ptr - right.m_ptr;
    }

    reference operator[](const difference_type offset) const noexcept {
        return *(*this + offset);
    }

    bool operator==(const vector_const_iterator& right) const noexcept {
        return m_ptr == right.m_ptr;
    }


    bool operator!=(const vector_const_iterator& right) const noexcept {
        return !(*this == right);
    }	

    bool operator<(const vector_const_iterator& right) const noexcept {
        return m_ptr < right.m_ptr;
    }

    bool operator>(const vector_const_iterator& right) const noexcept {
        return right < *this;
    }

    bool operator<=(const vector_const_iterator& right) const noexcept {
        return !(right < *this);
    }

    bool operator>=(const vector_const_iterator& right) const noexcept {
        return !(*this < right);
    }
};

template <class T_vec>
class vector_iterator : public vector_const_iterator<T_vec> {
public:
    using my_base = vector_const_iterator<T_vec>;

    //using iterator_category = random_access_iterator_tag;
    using value_type        = typename T_vec::value_type;
    using difference_type   = isz;
    using pointer           = value_type*;
    using reference         = value_type&;


    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return const_cast<pointer>(my_base::operator->());
    }

    vector_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    vector_iterator operator++(int) noexcept {
        vector_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    vector_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    vector_iterator operator--(int) noexcept {
        vector_iterator temp = *this;
        my_base::operator--();
        return temp;
    }

    vector_iterator& operator+=(const difference_type offset) noexcept {
        my_base::operator+=(offset);
        return *this;
    }

    vector_iterator operator+(const difference_type offset) const noexcept {
        my_base::m_index += offset;
        vector_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend vector_iterator operator+(const difference_type offset, vector_iterator next) noexcept {
        my_base::m_index += offset;
        next += offset;
        return next;
    }

    vector_iterator& operator-=(const difference_type offset) noexcept {
        my_base::operator-=(offset);
        return *this;
    }

    using my_base::operator-;

    vector_iterator operator-(const difference_type offset) const noexcept {
        my_base::m_index -= offset;
        vector_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    reference operator[](const difference_type offset) const noexcept {
        return const_cast<reference>(my_base::operator[](offset));
    }
};




template <class T_str>
class string_const_iterator {
public:

    //using iterator_category = random_access_iterator_tag;
    using value_type        = typename T_str::value_type;
    using difference_type   = isz;
    using pointer           = const value_type*;
    using reference         = const value_type&;

    //pointer m_ptr; // pointer to element in string //const
    value_type* m_ptr; // pointer to element in string
    isz m_index = 0;

    virtual ~string_const_iterator() { m_index = 0; }

    string_const_iterator() noexcept : m_ptr() {}

    string_const_iterator(value_type* ptr) : m_ptr(ptr) {}

    //string_const_iterator(pointer _Parg, const _Container_base* _Pstring) noexcept : m_ptr(_Parg) {
    //    this->_Adopt(_Pstring);
    //}

    isz index() const { return m_index; }    
	const value_type& value() const { return *m_ptr; }	

    reference operator*() const noexcept {
        return *m_ptr;
    }

    pointer operator->() const noexcept {
        return m_ptr;
    }

    string_const_iterator& operator++() noexcept {
        ++m_index;
        ++m_ptr;
        return *this;
    }

    string_const_iterator operator++(int) noexcept {
        ++m_index;
        string_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    string_const_iterator& operator--() noexcept {
        --m_index;
        --m_ptr;
        return *this;
    }

    string_const_iterator operator--(int) noexcept {
        --m_index;
        string_const_iterator temp = *this;
        --*this;
        return temp;
    }


    string_const_iterator& operator+=(const difference_type offset) noexcept {
        m_index += offset;
        m_ptr += offset;
        return *this;
    }

    string_const_iterator operator+(const difference_type offset) const noexcept {
        m_index += offset;
        string_const_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend string_const_iterator operator+(const difference_type offset, string_const_iterator next) noexcept {
        m_index += offset;
        next += offset;
        return next;
    }

    string_const_iterator& operator-=(const difference_type offset) noexcept {
        m_index -= offset;
        return *this += -offset;
    }

    string_const_iterator operator-(const difference_type offset) const noexcept {
        m_index -= offset;
        string_const_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    difference_type operator-(const string_const_iterator& right) const noexcept {
        return m_ptr - right.m_ptr;
    }

    reference operator[](const difference_type offset) const noexcept {
        return *(*this + offset);
    }

    bool operator==(const string_const_iterator& right) const noexcept {
        return m_ptr == right.m_ptr;
    }


    bool operator!=(const string_const_iterator& right) const noexcept {
        return !(*this == right);
    }

    bool operator<(const string_const_iterator& right) const noexcept {
        return m_ptr < right.m_ptr;
    }

    bool operator>(const string_const_iterator& right) const noexcept {
        return right < *this;
    }

    bool operator<=(const string_const_iterator& right) const noexcept {
        return !(right < *this);
    }

    bool operator>=(const string_const_iterator& right) const noexcept {
        return !(*this < right);
    }    
};

template <class T_str>
class string_iterator : public string_const_iterator<T_str> {
public:
    using my_base = string_const_iterator<T_str>;

    //using iterator_category = random_access_iterator_tag;
    using value_type        = typename T_str::value_type;
    using difference_type   = isz;
    using pointer           = value_type*;
    using reference         = value_type&;

    value_type& value() { return *my_base::m_ptr; }

    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        //return pointer_traits<pointer>::pointer_to(**this);
        return const_cast<pointer>(my_base::operator->());
    }

    string_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    string_iterator operator++(int) noexcept {
        string_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    string_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    string_iterator operator--(int) noexcept {
        string_iterator temp = *this;
        my_base::operator--();
        return temp;
    }

    string_iterator& operator+=(const difference_type offset) noexcept {
        my_base::operator+=(offset);
        return *this;
    }

    string_iterator operator+(const difference_type offset) const noexcept {
        my_base::m_index += offset;
        string_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend string_iterator operator+(const difference_type offset, string_iterator next) noexcept {
        my_base::m_index += offset;
        next += offset;
        return next;
    }

    string_iterator& operator-=(const difference_type offset) noexcept {
        my_base::operator-=(offset);
        return *this;
    }

    using my_base::operator-;

    string_iterator operator-(const difference_type offset) const noexcept {
        my_base::m_index -= offset;
        string_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    reference operator[](const difference_type offset) const noexcept {
        return const_cast<reference>(my_base::operator[](offset));
    }
};

//==============================


//==============================
template <class T_list>
class flist_const_iterator {
public:

    //using iterator_category = forward_iterator_tag;

    using node_type        = typename T_list::node_type;
    using value_type      = typename T_list::value_type;
    using difference_type = isz;
    using pointer         = const value_type*;
    using reference       = const value_type&;

    node_type* m_ptr = nullptr; 
    isz m_index = 0;    

    flist_const_iterator() {}
    virtual ~flist_const_iterator() { m_index = 0; }

    reference operator*() const noexcept {
        return m_ptr->m_data;
    }

    pointer operator->() const noexcept {
        return &(m_ptr->m_data);
    }

    flist_const_iterator& operator++() noexcept {
        ++m_index;
        m_ptr = m_ptr->next;
        return *this;
    }

    flist_const_iterator operator++(int) noexcept {
        ++m_index;
        flist_const_iterator temp = *this;
        m_ptr = m_ptr->next;
        return temp;
    }

    bool operator==(const flist_const_iterator& right) const noexcept {
        return m_ptr == right.m_ptr;
    }


    bool operator!=(const flist_const_iterator& right) const noexcept {
        return !(*this == right);
    }
};

template <class T_list>
class flist_iterator : public flist_const_iterator<T_list> {
public:
    using my_base           = flist_const_iterator<T_list>;
    //using iterator_category = forward_iterator_tag;

    using node_type        = typename T_list::node_type;
    using value_type      = typename T_list::value_type;
    using difference_type = isz;
    using pointer         = value_type*;
    using reference       = value_type&;


    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return const_cast<pointer>(my_base::operator->());
    }

    flist_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    flist_iterator operator++(int) noexcept {
        flist_iterator temp = *this;
        my_base::operator++();
        return temp;
    }
};


//==============================
template <class T_list>
class list_const_iterator {
public:

    //using iterator_category = bidirectional_iterator_tag;

    using node_type        = typename T_list::node_type;
    using value_type      = typename T_list::value_type;
    using difference_type = typename isz;
    using pointer         = const value_type*;
    using reference       = const value_type&;

    node_type* m_ptr = nullptr; 
    isz m_index = 0;    

    list_const_iterator() {}
    virtual ~list_const_iterator() { m_index = 0; }

    reference operator*() const noexcept {
        return m_ptr->m_data;
    }

    pointer operator->() const noexcept {
        return &(m_ptr->m_data);
    }

    list_const_iterator& operator++() noexcept {
        ++m_index;
        m_ptr = m_ptr->next;
        return *this;
    }

    list_const_iterator operator++(int) noexcept {
        ++m_index;
        list_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    list_const_iterator& operator--() noexcept {
        --m_index;
        const auto _New_ptr = m_ptr->_Prev;
        m_ptr = _New_ptr;
        return *this;
    }

    list_const_iterator operator--(int) noexcept {
        --m_index;
        list_const_iterator temp = *this;
        --*this;
        return temp;
    }

    bool operator==(const list_const_iterator& right) const noexcept {
        return m_ptr == right.m_ptr;
    }


    bool operator!=(const list_const_iterator& right) const noexcept {
        return !(*this == right);
    }
};

template <class T_list>
class list_iterator : public list_const_iterator<T_list> {
public:
    using my_base           = list_const_iterator<T_list>;
    //using iterator_category = bidirectional_iterator_tag;

    using node_type        = typename T_list::node_type;
    using value_type      = typename T_list::value_type;
    using difference_type = isz;
    using pointer         = value_type*;
    using reference       = value_type&;


    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return const_cast<pointer>(my_base::operator->());
    }

    list_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    list_iterator operator++(int) noexcept {
        list_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    list_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    list_iterator operator--(int) noexcept {
        list_iterator temp = *this;
        my_base::operator--();
        return temp;
    }
};


}