#pragma once

namespace sdf
{

// ITERATOR TAGS
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};
//======================================================================


//================================================
// VECTOR ITERATOR
//================================================
template <class Tvec>
class vector_const_iterator {
public:

    using iterator_category = random_access_iterator_tag;
    using value_type        = typename Tvec::value_type;
    using difference_type   = typename Tvec::difference_type;
    using pointer           = typename Tvec::const_pointer;
    using reference         = const value_type&;

    using Tptr = typename Tvec::pointer;

    constexpr vector_const_iterator() noexcept : m_ptr() {}

    constexpr vector_const_iterator(Tptr parg) noexcept : m_ptr(parg) {}

    constexpr reference operator*() const noexcept {
        return *m_ptr;
    }

    constexpr pointer operator->() const noexcept {
        return m_ptr;
    }

    constexpr vector_const_iterator& operator++() noexcept {
        ++m_ptr;
        return *this;
    }

    constexpr vector_const_iterator operator++(int) noexcept {
        vector_const_iterator temp = *this;
        ++*this;
        return temp;
    }

    constexpr vector_const_iterator& operator--() noexcept {
        --m_ptr;
        return *this;
    }

    constexpr vector_const_iterator operator--(int) noexcept {
        vector_const_iterator temp = *this;
        --*this;
        return temp;
    }


    constexpr vector_const_iterator& operator+=(const difference_type offset) noexcept {
        m_ptr += offset;
        return *this;
    }

    constexpr vector_const_iterator operator+(const difference_type offset) const noexcept {
        vector_const_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend constexpr vector_const_iterator operator+(
        const difference_type offset, vector_const_iterator next) noexcept {
        next += offset;
        return next;
    }

    constexpr vector_const_iterator& operator-=(const difference_type offset) noexcept {
        return *this += -offset;
    }

    constexpr vector_const_iterator operator-(const difference_type offset) const noexcept {
        vector_const_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    constexpr difference_type operator-(const vector_const_iterator& right) const noexcept {
        return m_ptr - right.m_ptr;
    }

    constexpr reference operator[](const difference_type offset) const noexcept {
        return *(*this + offset);
    }

    constexpr bool operator==(const vector_const_iterator& right) const noexcept {
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

    Tptr m_ptr; // pointer to element in vector
};


template <class Tvec>
class vector_iterator : public vector_const_iterator<Tvec> {
public:
    using my_base = vector_const_iterator<Tvec>;

    using iterator_category = random_access_iterator_tag;
    using value_type        = typename Tvec::value_type;
    using difference_type   = typename Tvec::difference_type;
    using pointer           = typename Tvec::pointer;
    using reference         = value_type&;

    using my_base::my_base;

    constexpr reference operator*() const noexcept {
        return const_cast<reference>(my_base::operator*());
    }

    constexpr pointer operator->() const noexcept {
        return this->m_ptr;
    }

    constexpr vector_iterator& operator++() noexcept {
        my_base::operator++();
        return *this;
    }

    constexpr vector_iterator operator++(int) noexcept {
        vector_iterator temp = *this;
        my_base::operator++();
        return temp;
    }

    constexpr vector_iterator& operator--() noexcept {
        my_base::operator--();
        return *this;
    }

    constexpr vector_iterator operator--(int) noexcept {
        vector_iterator temp = *this;
        my_base::operator--();
        return temp;
    }

    constexpr vector_iterator& operator+=(const difference_type offset) noexcept {
        my_base::operator+=(offset);
        return *this;
    }

    constexpr vector_iterator operator+(const difference_type offset) const noexcept {
        vector_iterator temp = *this;
        temp += offset;
        return temp;
    }

    friend constexpr vector_iterator operator+(
        const difference_type offset, vector_iterator next) noexcept {
        next += offset;
        return next;
    }

    constexpr vector_iterator& operator-=(const difference_type offset) noexcept {
        my_base::operator-=(offset);
        return *this;
    }

    using my_base::operator-;

    constexpr vector_iterator operator-(const difference_type offset) const noexcept {
        vector_iterator temp = *this;
        temp -= offset;
        return temp;
    }

    constexpr reference operator[](const difference_type offset) const noexcept {
        return const_cast<reference>(my_base::operator[](offset));
    }
};

}

