
namespace sdf
{

template <class Tcont>
class vector_const_iterator {
public:
    using value_type        = typename Tcont::value_type;
    using difference_type   = isz;
    using pointer           = const value_type*;
    using reference         = const value_type&;

    value_type* m_ptr = nullptr; // pointer to element in vector

    vector_const_iterator() {}
    vector_const_iterator(value_type* ptr) : m_ptr(ptr) {}
    virtual ~vector_const_iterator() {}

    reference operator*() const noexcept { return *m_ptr; }
    pointer operator->() const noexcept { return m_ptr; }

    vector_const_iterator& operator++() noexcept { ++m_ptr; return *this; }

    vector_const_iterator operator++(int) noexcept {
        vector_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    vector_const_iterator& operator--() noexcept { --m_ptr; return *this; }

    vector_const_iterator operator--(int) noexcept {
        vector_const_iterator temp = *this;
        --*this;
        return temp;
    }


    vector_const_iterator& operator+=(const difference_type offset) noexcept { m_ptr += offset; return *this; }

    vector_const_iterator operator+(const difference_type offset) const noexcept {
        vector_const_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend vector_const_iterator operator+(const difference_type offset, vector_const_iterator next) noexcept {
        next += offset;
        return next;
    }

    vector_const_iterator& operator-=(const difference_type offset) noexcept { return *this += -offset; }

    vector_const_iterator operator-(const difference_type offset) const noexcept {
        vector_const_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    difference_type operator-(const vector_const_iterator& right) const noexcept { return m_ptr - right.m_ptr; }

    reference operator[](const difference_type offset) const noexcept { return *(*this + offset); }

    bool operator==(const vector_const_iterator& right) const noexcept { return m_ptr == right.m_ptr; }
    bool operator!=(const vector_const_iterator& right) const noexcept { return !(*this == right); }

    bool operator<(const vector_const_iterator& right) const noexcept { return m_ptr < right.m_ptr; }
    bool operator>(const vector_const_iterator& right) const noexcept { return right < *this; }
    bool operator<=(const vector_const_iterator& right) const noexcept { return !(right < *this); }
    bool operator>=(const vector_const_iterator& right) const noexcept { return !(*this < right); }
};

template <class Tcont>
class vector_iterator : public vector_const_iterator<Tcont> {
public:
    using my_base = vector_const_iterator<Tcont>;

    using value_type        = typename Tcont::value_type;
    using difference_type   = isz;
    using pointer           = value_type*;
    using reference         = value_type&;

    vector_iterator() {}
    vector_iterator(value_type* ptr) : my_base(ptr) {}
    virtual ~vector_iterator() {}

    reference operator*() const noexcept { return const_cast<reference>(my_base::operator*()); }
    pointer operator->() const noexcept { return const_cast<pointer>(my_base::operator->()); }

    vector_iterator& operator++() noexcept { my_base::operator++(); return *this; }

    vector_iterator operator++(int) noexcept {
        vector_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    vector_iterator& operator--() noexcept { my_base::operator--(); return *this; }

    vector_iterator operator--(int) noexcept {
        vector_iterator temp = *this;
        my_base::operator--();
        return temp;
    }

    vector_iterator& operator+=(const difference_type offset) noexcept { my_base::operator+=(offset); return *this; }

    vector_iterator operator+(const difference_type offset) const noexcept {
        vector_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend vector_iterator operator+(const difference_type offset, vector_iterator next) noexcept {
        next += offset;
        return next;
    }

    vector_iterator& operator-=(const difference_type offset) noexcept { my_base::operator-=(offset); return *this; }

    using my_base::operator-;

    vector_iterator operator-(const difference_type offset) const noexcept {
        vector_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    reference operator[](const difference_type offset) const noexcept { return const_cast<reference>(my_base::operator[](offset)); }
};


}

