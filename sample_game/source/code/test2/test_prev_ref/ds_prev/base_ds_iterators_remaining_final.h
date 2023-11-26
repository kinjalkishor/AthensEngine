//#include <vector>
//#include <list>
//#include <forward_list>
//#include <deque>
//#include <array>
//#include <string>
//#include <map>



//=========================================================================


//================================================
// LIST ITERATOR
//================================================
template <class Tlist>
class list_unchecked_const_iterator {
public:
    using iterator_category = bidirectional_iterator_tag;

    using nodeptr         = typename Tlist::nodeptr;
    using value_type      = typename Tlist::value_type;
    using difference_type = typename Tlist::difference_type;
    using pointer         = typename Tlist::const_pointer;
    using reference       = const value_type&;

    list_unchecked_const_iterator() noexcept : m_ptr() {}

    list_unchecked_const_iterator(nodeptr _Pnode, const Tlist* _Plist) noexcept : m_ptr(_Pnode) {
        this->_Adopt(_Plist);
    }

    reference operator*() const noexcept {
        return m_ptr->_Myval;
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    list_unchecked_const_iterator& operator++() noexcept {
        m_ptr = m_ptr->next;
        return *this;
    }

    list_unchecked_const_iterator operator++(int) noexcept {
        list_unchecked_const_iterator temp = *this;
        m_ptr                                = m_ptr->next;
        return temp;
    }

    list_unchecked_const_iterator& operator--() noexcept {
        m_ptr = m_ptr->_Prev;
        return *this;
    }

    list_unchecked_const_iterator operator--(int) noexcept {
        list_unchecked_const_iterator temp = *this;
        m_ptr                                = m_ptr->_Prev;
        return temp;
    }

    bool operator==(const list_unchecked_const_iterator& right) const noexcept {
        return m_ptr == right.m_ptr;
    }


    bool operator!=(const list_unchecked_const_iterator& right) const noexcept {
        return !(*this == right);
    }


    nodeptr m_ptr; // pointer to node
};

template <class Tlist>
class list_unchecked_iterator : public list_unchecked_const_iterator<Tlist> {
public:
    using my_base           = list_unchecked_const_iterator<Tlist>;
    using iterator_category = bidirectional_iterator_tag;

    using nodeptr         = typename Tlist::nodeptr;
    using value_type      = typename Tlist::value_type;
    using difference_type = typename Tlist::difference_type;
    using pointer         = typename Tlist::pointer;
    using reference       = value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    list_unchecked_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    list_unchecked_iterator operator++(int) noexcept {
        list_unchecked_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    list_unchecked_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    list_unchecked_iterator operator--(int) noexcept {
        list_unchecked_iterator temp = *this;
        my_base::operator--();
        return temp;
    }
};

template <class Tlist>
class list_const_iterator : public list_unchecked_const_iterator<Tlist> {
public:
    using my_base           = list_unchecked_const_iterator<Tlist>;
    using iterator_category = bidirectional_iterator_tag;

    using nodeptr         = typename Tlist::nodeptr;
    using value_type      = typename Tlist::value_type;
    using difference_type = typename Tlist::difference_type;
    using pointer         = typename Tlist::const_pointer;
    using reference       = const value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return this->m_ptr->_Myval;
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    list_const_iterator& operator++() noexcept {
        this->m_ptr = this->m_ptr->next;
        return *this;
    }

    list_const_iterator operator++(int) noexcept {
        list_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    list_const_iterator& operator--() noexcept {
        const auto _New_ptr = this->m_ptr->_Prev;
        this->m_ptr = _New_ptr;
        return *this;
    }

    list_const_iterator operator--(int) noexcept {
        list_const_iterator temp = *this;
        --*this;
        return temp;
    }

    bool operator==(const list_const_iterator& right) const noexcept {
        return this->m_ptr == right.m_ptr;
    }


    bool operator!=(const list_const_iterator& right) const noexcept {
        return !(*this == right);
    }
};

template <class Tlist>
class list_iterator : public list_const_iterator<Tlist> {
public:
    using my_base           = list_const_iterator<Tlist>;
    using iterator_category = bidirectional_iterator_tag;

    using nodeptr         = typename Tlist::nodeptr;
    using value_type      = typename Tlist::value_type;
    using difference_type = typename Tlist::difference_type;
    using pointer         = typename Tlist::pointer;
    using reference       = value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
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


//================================================
// FORWARD_LIST ITERATOR
//================================================


template <class Tlist>
class flist_unchecked_const_iterator {
public:
    using iterator_category = forward_iterator_tag;

    using nodeptr         = typename Tlist::nodeptr;
    using value_type      = typename Tlist::value_type;
    using difference_type = typename Tlist::difference_type;
    using pointer         = typename Tlist::const_pointer;
    using reference       = const value_type&;

    flist_unchecked_const_iterator() noexcept : m_ptr() {}

    flist_unchecked_const_iterator(nodeptr _Pnode, const Tlist* _Plist) noexcept : m_ptr(_Pnode) {
        this->_Adopt(_Plist);
    }

    reference operator*() const noexcept {
        return m_ptr->_Myval;
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    flist_unchecked_const_iterator& operator++() noexcept {
        m_ptr = m_ptr->next;
        return *this;
    }

    flist_unchecked_const_iterator operator++(int) noexcept {
        flist_unchecked_const_iterator temp = *this;
        m_ptr                                 = m_ptr->next;
        return temp;
    }

    bool operator==(const flist_unchecked_const_iterator& right) const noexcept {
        return m_ptr == right.m_ptr;
    }


    bool operator!=(const flist_unchecked_const_iterator& right) const noexcept {
        return !(*this == right);
    }


    bool operator==(_Default_sentinel) const noexcept {
        return m_ptr == nullptr;
    }


    bool operator!=(_Default_sentinel) const noexcept {
        return m_ptr != nullptr;
    }


    nodeptr m_ptr; // pointer to node
};

template <class Tlist>
class flist_unchecked_iterator : public flist_unchecked_const_iterator<Tlist> {
public:
    using my_base           = flist_unchecked_const_iterator<Tlist>;
    using iterator_category = forward_iterator_tag;

    using nodeptr         = typename Tlist::nodeptr;
    using value_type      = typename Tlist::value_type;
    using difference_type = typename Tlist::difference_type;
    using pointer         = typename Tlist::pointer;
    using reference       = value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    flist_unchecked_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    flist_unchecked_iterator operator++(int) noexcept {
        flist_unchecked_iterator temp = *this;
        my_base::operator++();
        return temp;
    }
};

template <class Tlist>
class flist_const_iterator : public flist_unchecked_const_iterator<Tlist> {
public:
    using my_base           = flist_unchecked_const_iterator<Tlist>;
    using iterator_category = forward_iterator_tag;

    using nodeptr         = typename Tlist::nodeptr;
    using value_type      = typename Tlist::value_type;
    using difference_type = typename Tlist::difference_type;
    using pointer         = typename Tlist::const_pointer;
    using reference       = const value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return this->m_ptr->_Myval;
    }

    flist_const_iterator& operator++() noexcept {
        this->m_ptr = this->m_ptr->next;
        return *this;
    }

    flist_const_iterator operator++(int) noexcept {
        flist_const_iterator temp = *this;
        this->m_ptr                 = this->m_ptr->next;
        return temp;
    }

    bool operator==(const flist_const_iterator& right) const noexcept {
        return this->m_ptr == right.m_ptr;
    }


    bool operator!=(const flist_const_iterator& right) const noexcept {
        return !(*this == right);
    }
};

template <class Tlist>
class flist_iterator : public flist_const_iterator<Tlist> {
public:
    using my_base           = flist_const_iterator<Tlist>;
    using iterator_category = forward_iterator_tag;

    using nodeptr         = typename Tlist::nodeptr;
    using value_type      = typename Tlist::value_type;
    using difference_type = typename Tlist::difference_type;
    using pointer         = typename Tlist::pointer;
    using reference       = value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
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


//================================================
// DEQUE ITERATOR
//================================================
template <class Tdeque>
class deque_const_iterator {
private:
    using size_type = typename Tdeque::size_type;

    static constexpr int _Block_size = Tdeque::_Block_size;

public:
    using iterator_category = random_access_iterator_tag;

    using value_type      = typename Tdeque::value_type;
    using difference_type = typename Tdeque::difference_type;
    using pointer         = typename Tdeque::const_pointer;
    using reference       = const value_type&;

    using _Mydeque_t = Tdeque; // helper for expression evaluator
    enum { _EEN_DS = _Block_size }; // helper for expression evaluator
    deque_const_iterator() noexcept : _Myoff(0) {
        _Setcont(nullptr);
    }

    deque_const_iterator(size_type offset, const _Container_base12* _Pdeque) noexcept : _Myoff(offset) {
        _Setcont(static_cast<const Tdeque*>(_Pdeque));
    }

    reference operator*() const noexcept {
        const auto _Mycont = static_cast<const Tdeque*>(this->_Getcont());
        size_type _Block = _Mycont->_Getblock(_Myoff);
        size_type offset   = _Myoff % _Block_size;
        return _Mycont->_Map[_Block][offset];
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    deque_const_iterator& operator++() noexcept {
        ++_Myoff;
        return *this;
    }

    deque_const_iterator operator++(int) noexcept {
        deque_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    deque_const_iterator& operator--() noexcept {
        --_Myoff;
        return *this;
    }

    deque_const_iterator operator--(int) noexcept {
        deque_const_iterator temp = *this;
        --*this;
        return temp;
    }

    deque_const_iterator& operator+=(const difference_type offset) noexcept {
        _Myoff += offset;
        return *this;
    }

    deque_const_iterator operator+(const difference_type offset) const noexcept {
        deque_const_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend deque_const_iterator operator+(
        const difference_type offset, deque_const_iterator next) noexcept {
        next += offset;
        return next;
    }

    deque_const_iterator& operator-=(const difference_type offset) noexcept {
        return *this += -offset;
    }

    deque_const_iterator operator-(const difference_type offset) const noexcept {
        deque_const_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    difference_type operator-(const deque_const_iterator& right) const noexcept {
        return static_cast<difference_type>(this->_Myoff - right._Myoff);
    }

    reference operator[](const difference_type offset) const noexcept {
        return *(*this + offset);
    }

    bool operator==(const deque_const_iterator& right) const noexcept {
        return this->_Myoff == right._Myoff;
    }


    bool operator!=(const deque_const_iterator& right) const noexcept {
        return !(*this == right);
    }

    bool operator<(const deque_const_iterator& right) const noexcept {
        return this->_Myoff < right._Myoff;
    }

    bool operator>(const deque_const_iterator& right) const noexcept {
        return right < *this;
    }

    bool operator<=(const deque_const_iterator& right) const noexcept {
        return !(right < *this);
    }

    bool operator>=(const deque_const_iterator& right) const noexcept {
        return !(*this < right);
    }

    size_type _Myoff; // offset of element in deque
};

template <class Tdeque>
class deque_iterator : public deque_const_iterator<Tdeque> {
private:
    using size_type = typename Tdeque::size_type;
    using my_base    = deque_const_iterator<Tdeque>;

public:
    using iterator_category = random_access_iterator_tag;

    using value_type      = typename Tdeque::value_type;
    using difference_type = typename Tdeque::difference_type;
    using pointer         = typename Tdeque::pointer;
    using reference       = value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    deque_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    deque_iterator operator++(int) noexcept {
        deque_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    deque_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    deque_iterator operator--(int) noexcept {
        deque_iterator temp = *this;
        my_base::operator--();
        return temp;
    }

    deque_iterator& operator+=(const difference_type offset) noexcept {
        my_base::operator+=(offset);
        return *this;
    }

    deque_iterator operator+(const difference_type offset) const noexcept {
        deque_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend deque_iterator operator+(const difference_type offset, deque_iterator next) noexcept {
        next += offset;
        return next;
    }

    deque_iterator& operator-=(const difference_type offset) noexcept {
        my_base::operator-=(offset);
        return *this;
    }

    using my_base::operator-;

    deque_iterator operator-(const difference_type offset) const noexcept {
        deque_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    reference operator[](const difference_type offset) const noexcept {
        return const_cast<reference>(my_base::operator[](offset));
    }
};



//================================================
// ARRAY ITERATOR
//================================================
template <class T, size_t Tsize>
class array_const_iterator {
public:

    using iterator_category = random_access_iterator_tag;
    using value_type        = T;
    using difference_type   = ptrdiff_t;
    using pointer           = const T*;
    using reference         = const T&;

    enum { _EEN_SIZE = Tsize }; // helper for expression evaluator


    constexpr array_const_iterator() noexcept : m_ptr() {}

    constexpr explicit array_const_iterator(pointer _Parg, size_t offset = 0) noexcept : m_ptr(_Parg + offset) {}

    constexpr reference operator*() const noexcept {
        return *m_ptr;
    }

    constexpr pointer operator->() const noexcept {
        return m_ptr;
    }

    constexpr array_const_iterator& operator++() noexcept {
        ++m_ptr;
        return *this;
    }

    constexpr array_const_iterator operator++(int) noexcept {
        array_const_iterator temp = *this;
        ++m_ptr;
        return temp;
    }

    constexpr array_const_iterator& operator--() noexcept {
        --m_ptr;
        return *this;
    }

    constexpr array_const_iterator operator--(int) noexcept {
        array_const_iterator temp = *this;
        --m_ptr;
        return temp;
    }

    constexpr array_const_iterator& operator+=(const ptrdiff_t offset) noexcept {
        m_ptr += offset;
        return *this;
    }

    constexpr array_const_iterator& operator-=(const ptrdiff_t offset) noexcept {
        m_ptr -= offset;
        return *this;
    }

    constexpr ptrdiff_t operator-(const array_const_iterator& right) const noexcept {
        return m_ptr - right.m_ptr;
    }

    constexpr reference operator[](const ptrdiff_t offset) const noexcept {
        return m_ptr[offset];
    }

    constexpr bool operator==(const array_const_iterator& right) const noexcept {
        return m_ptr == right.m_ptr;
    }


    constexpr bool operator<(const array_const_iterator& right) const noexcept {
        return m_ptr < right.m_ptr;
    }


private:
    pointer m_ptr; // beginning of array



public:
    constexpr array_const_iterator operator+(const ptrdiff_t offset) const noexcept {
        array_const_iterator temp = *this;
        temp += offset;
        return temp;
    }

    constexpr array_const_iterator operator-(const ptrdiff_t offset) const noexcept {
        array_const_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    friend constexpr array_const_iterator operator+(
        const ptrdiff_t offset, array_const_iterator next) noexcept {
        next += offset;
        return next;
    }


    constexpr bool operator!=(const array_const_iterator& right) const noexcept {
        return !(*this == right);
    }

    constexpr bool operator>(const array_const_iterator& right) const noexcept {
        return right < *this;
    }

    constexpr bool operator<=(const array_const_iterator& right) const noexcept {
        return !(right < *this);
    }

    constexpr bool operator>=(const array_const_iterator& right) const noexcept {
        return !(*this < right);
    }

};

template <class T, size_t Tsize>
class array_iterator : public array_const_iterator<T, Tsize> {
public:
    using my_base = array_const_iterator<T, Tsize>;

    using iterator_category = random_access_iterator_tag;
    using value_type        = T;
    using difference_type   = ptrdiff_t;
    using pointer           = T*;
    using reference         = T&;

    enum { _EEN_SIZE = Tsize }; // helper for expression evaluator

    constexpr array_iterator() noexcept {}

    constexpr explicit array_iterator(pointer _Parg, size_t offset = 0) noexcept : my_base(_Parg, offset) {}

    constexpr reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    constexpr pointer operator->() const noexcept {
        return const_cast<pointer>(my_base::operator->());
    }

    constexpr array_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    constexpr array_iterator operator++(int) noexcept {
        array_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    constexpr array_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    constexpr array_iterator operator--(int) noexcept {
        array_iterator temp = *this;
        my_base::operator--();
        return temp;
    }

    constexpr array_iterator& operator+=(const ptrdiff_t offset) noexcept {
        my_base::operator+=(offset);
        return *this;
    }

    constexpr array_iterator operator+(const ptrdiff_t offset) const noexcept {
        array_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend constexpr array_iterator operator+(const ptrdiff_t offset, array_iterator next) noexcept {
        next += offset;
        return next;
    }

    constexpr array_iterator& operator-=(const ptrdiff_t offset) noexcept {
        my_base::operator-=(offset);
        return *this;
    }

    using my_base::operator-;

    constexpr array_iterator operator-(const ptrdiff_t offset) const noexcept {
        array_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    constexpr reference operator[](const ptrdiff_t offset) const noexcept {
        return const_cast<reference>(my_base::operator[](offset));
    }
};


//================================================
// TREE ITERATOR
//================================================

template <class Ttree>
class tree_unchecked_const_iterator {
public:
    using iterator_category = bidirectional_iterator_tag;

    using nodeptr         = typename Ttree::nodeptr;
    using value_type      = typename Ttree::value_type;
    using difference_type = typename Ttree::difference_type;
    using pointer         = typename Ttree::const_pointer;
    using reference       = const value_type&;

    tree_unchecked_const_iterator() noexcept : m_ptr() {}

    tree_unchecked_const_iterator(nodeptr _Pnode, const Ttree* _Plist) noexcept : m_ptr(_Pnode) {
        this->_Adopt(_Plist);
    }

    reference operator*() const noexcept {
        return m_ptr->_Myval;
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    tree_unchecked_const_iterator& operator++() noexcept {
        if (m_ptr->right->_Isnil) { // climb looking for right subtree
            nodeptr _Pnode;
            while (!(_Pnode = m_ptr->_Parent)->_Isnil && m_ptr == _Pnode->right) {
                m_ptr = _Pnode; // ==> parent while right subtree
            }

            m_ptr = _Pnode; // ==> parent (head if end())
        } else {
            m_ptr = Ttree::_Min(m_ptr->right); // ==> smallest of right subtree
        }

        return *this;
    }

    tree_unchecked_const_iterator operator++(int) noexcept {
        tree_unchecked_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    tree_unchecked_const_iterator& operator--() noexcept {
        if (m_ptr->_Isnil) {
            m_ptr = m_ptr->right; // end() ==> rightmost
        } else if (m_ptr->_Left->_Isnil) { // climb looking for left subtree
            nodeptr _Pnode;
            while (!(_Pnode = m_ptr->_Parent)->_Isnil && m_ptr == _Pnode->_Left) {
                m_ptr = _Pnode; // ==> parent while left subtree
            }

            if (!m_ptr->_Isnil) { // decrement non-begin()
                m_ptr = _Pnode; // ==> parent if not head
            }
        } else {
            m_ptr = Ttree::_Max(m_ptr->_Left); // ==> largest of left subtree
        }

        return *this;
    }

    tree_unchecked_const_iterator operator--(int) noexcept {
        tree_unchecked_const_iterator temp = *this;
        --*this;
        return temp;
    }

    bool operator==(const tree_unchecked_const_iterator& right) const noexcept {
        return m_ptr == right.m_ptr;
    }


    bool operator!=(const tree_unchecked_const_iterator& right) const noexcept {
        return !(*this == right);
    }


    bool operator==(_Default_sentinel) const noexcept {
        return !!m_ptr->_Isnil; // TRANSITION, avoid warning C4800:
                               // "Implicit conversion from 'char' to bool. Possible information loss" (/Wall)
    }


    bool operator!=(_Default_sentinel) const noexcept {
        return !m_ptr->_Isnil;
    }


    nodeptr m_ptr; // pointer to node
};

template <class Ttree>
class tree_unchecked_iterator : public tree_unchecked_const_iterator<Ttree> {
public:
    using my_base           = tree_unchecked_const_iterator<Ttree>;
    using iterator_category = bidirectional_iterator_tag;

    using nodeptr         = typename Ttree::nodeptr;
    using value_type      = typename Ttree::value_type;
    using difference_type = typename Ttree::difference_type;
    using pointer         = typename Ttree::pointer;
    using reference       = value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    tree_unchecked_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    tree_unchecked_iterator operator++(int) noexcept {
        tree_unchecked_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    tree_unchecked_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    tree_unchecked_iterator operator--(int) noexcept {
        tree_unchecked_iterator temp = *this;
        my_base::operator--();
        return temp;
    }
};

template <class Ttree>
class tree_const_iterator : public tree_unchecked_const_iterator<Ttree, _Iterator_base> {
public:
    using my_base           = tree_unchecked_const_iterator<Ttree, _Iterator_base>;
    using iterator_category = bidirectional_iterator_tag;

    using nodeptr         = typename Ttree::nodeptr;
    using value_type      = typename Ttree::value_type;
    using difference_type = typename Ttree::difference_type;
    using pointer         = typename Ttree::const_pointer;
    using reference       = const value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return this->m_ptr->_Myval;
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    tree_const_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    tree_const_iterator operator++(int) noexcept {
        tree_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    tree_const_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    tree_const_iterator operator--(int) noexcept {
        tree_const_iterator temp = *this;
        --*this;
        return temp;
    }

    bool operator==(const tree_const_iterator& right) const noexcept {
        return this->m_ptr == right.m_ptr;
    }


    bool operator!=(const tree_const_iterator& right) const noexcept {
        return !(*this == right);
    }
};

template <class Ttree>
class tree_iterator : public tree_const_iterator<Ttree> {
public:
    using my_base           = tree_const_iterator<Ttree>;
    using iterator_category = bidirectional_iterator_tag;

    using nodeptr         = typename Ttree::nodeptr;
    using value_type      = typename Ttree::value_type;
    using difference_type = typename Ttree::difference_type;

    using pointer   = typename Ttree::pointer;
    using reference = value_type&;

    using my_base::my_base;

    reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    tree_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    tree_iterator operator++(int) noexcept {
        tree_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    tree_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    tree_iterator operator--(int) noexcept {
        tree_iterator temp = *this;
        my_base::operator--();
        return temp;
    }
};

//==============================================================

// USE vector_iterator as it is same

//================================================
// STRING ITERATOR
//================================================
template <class Tstr>
class string_const_iterator {
public:

    using iterator_category = random_access_iterator_tag;
    using value_type        = typename Tstr::value_type;
    using difference_type   = typename Tstr::difference_type;
    using pointer           = typename Tstr::const_pointer;
    using reference         = const value_type&;

    constexpr string_const_iterator() noexcept : m_ptr() {}

    constexpr string_const_iterator(pointer parg) noexcept : m_ptr(parg) {}

    constexpr reference operator*() const noexcept {
        return *m_ptr;
    }

    constexpr pointer operator->() const noexcept {
        //return pointer_traits<pointer>::pointer_to(**this);
        return m_ptr;
    }

    constexpr string_const_iterator& operator++() noexcept {
        ++m_ptr;
        return *this;
    }

    constexpr string_const_iterator operator++(int) noexcept {
        string_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    constexpr string_const_iterator& operator--() noexcept {
        --m_ptr;
        return *this;
    }

    constexpr string_const_iterator operator--(int) noexcept {
        string_const_iterator temp = *this;
        --*this;
        return temp;
    }


    constexpr string_const_iterator& operator+=(const difference_type offset) noexcept {
        m_ptr += offset;
        return *this;
    }

    constexpr string_const_iterator operator+(const difference_type offset) const noexcept {
        string_const_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend constexpr string_const_iterator operator+(
        const difference_type offset, string_const_iterator next) noexcept {
        next += offset;
        return next;
    }

    constexpr string_const_iterator& operator-=(const difference_type offset) noexcept {
        return *this += -offset;
    }

    constexpr string_const_iterator operator-(const difference_type offset) const noexcept {
        string_const_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    constexpr difference_type operator-(const string_const_iterator& right) const noexcept {
        return m_ptr - right.m_ptr;
    }

    constexpr reference operator[](const difference_type offset) const noexcept {
        return *(*this + offset);
    }

    constexpr bool operator==(const string_const_iterator& right) const noexcept {
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

    pointer m_ptr; // pointer to element in string
};


template <class Tstr>
class string_iterator : public string_const_iterator<Tstr> {
public:
    using my_base = string_const_iterator<Tstr>;

    using iterator_category = random_access_iterator_tag;
    using value_type        = typename Tstr::value_type;
    using difference_type   = typename Tstr::difference_type;
    using pointer           = typename Tstr::pointer;
    using reference         = value_type&;

    using my_base::my_base;

    constexpr reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    constexpr pointer operator->() const noexcept {
        //return pointer_traits<pointer>::pointer_to(**this);
        return m_ptr;
    }

    constexpr string_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    constexpr string_iterator operator++(int) noexcept {
        string_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    constexpr string_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    constexpr string_iterator operator--(int) noexcept {
        string_iterator temp = *this;
        my_base::operator--();
        return temp;
    }

    constexpr string_iterator& operator+=(const difference_type offset) noexcept {
        my_base::operator+=(offset);
        return *this;
    }

    constexpr string_iterator operator+(const difference_type offset) const noexcept {
        string_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend constexpr string_iterator operator+(
        const difference_type offset, string_iterator next) noexcept {
        next += offset;
        return next;
    }

    constexpr string_iterator& operator-=(const difference_type offset) noexcept {
        my_base::operator-=(offset);
        return *this;
    }

    using my_base::operator-;

    constexpr string_iterator operator-(const difference_type offset) const noexcept {
        string_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    constexpr reference operator[](const difference_type offset) const noexcept {
        return const_cast<reference>(my_base::operator[](offset));
    }
};
