#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <string>
#include <map>

//======================================================================
_STD_BEGIN
template <class _Myvec>
class _Vector_const_iterator : public _Iterator_base {
public:
#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif // __cpp_lib_concepts
    using iterator_category = random_access_iterator_tag;
    using value_type        = typename _Myvec::value_type;
    using difference_type   = typename _Myvec::difference_type;
    using pointer           = typename _Myvec::const_pointer;
    using reference         = const value_type&;

    using _Tptr = typename _Myvec::pointer;

    _CONSTEXPR20 _Vector_const_iterator() noexcept : _Ptr() {}

    _CONSTEXPR20 _Vector_const_iterator(_Tptr _Parg, const _Container_base* _Pvector) noexcept : _Ptr(_Parg) {
        this->_Adopt(_Pvector);
    }

    _NODISCARD _CONSTEXPR20 reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Ptr, "can't dereference value-initialized vector iterator");
        _STL_VERIFY(_Mycont, "can't dereference invalidated vector iterator");
        _STL_VERIFY(
            _Mycont->_Myfirst <= _Ptr && _Ptr < _Mycont->_Mylast, "can't dereference out of range vector iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return *_Ptr;
    }

    _NODISCARD _CONSTEXPR20 pointer operator->() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Ptr, "can't dereference value-initialized vector iterator");
        _STL_VERIFY(_Mycont, "can't dereference invalidated vector iterator");
        _STL_VERIFY(
            _Mycont->_Myfirst <= _Ptr && _Ptr < _Mycont->_Mylast, "can't dereference out of range vector iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return _Ptr;
    }

    _CONSTEXPR20 _Vector_const_iterator& operator++() noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Ptr, "can't increment value-initialized vector iterator");
        _STL_VERIFY(_Mycont, "can't increment invalidated vector iterator");
        _STL_VERIFY(_Ptr < _Mycont->_Mylast, "can't increment vector iterator past end");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        ++_Ptr;
        return *this;
    }

    _CONSTEXPR20 _Vector_const_iterator operator++(int) noexcept {
        _Vector_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _CONSTEXPR20 _Vector_const_iterator& operator--() noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Ptr, "can't decrement value-initialized vector iterator");
        _STL_VERIFY(_Mycont, "can't decrement invalidated vector iterator");
        _STL_VERIFY(_Mycont->_Myfirst < _Ptr, "can't decrement vector iterator before begin");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        --_Ptr;
        return *this;
    }

    _CONSTEXPR20 _Vector_const_iterator operator--(int) noexcept {
        _Vector_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

    _CONSTEXPR20 void _Verify_offset(const difference_type _Off) const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 0
        (void) _Off;
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 / _ITERATOR_DEBUG_LEVEL != 0 vvv
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(_Off == 0 || _Ptr, "cannot seek value-initialized vector iterator");
        _STL_VERIFY(_Off == 0 || _Mycont, "cannot seek invalidated vector iterator");
        if (_Off < 0) {
            _STL_VERIFY(_Off >= _Mycont->_Myfirst - _Ptr, "cannot seek vector iterator before begin");
        }

        if (_Off > 0) {
            _STL_VERIFY(_Off <= _Mycont->_Mylast - _Ptr, "cannot seek vector iterator after end");
        }
#endif // _ITERATOR_DEBUG_LEVEL == 0
    }

    _CONSTEXPR20 _Vector_const_iterator& operator+=(const difference_type _Off) noexcept {
        _Verify_offset(_Off);
        _Ptr += _Off;
        return *this;
    }

    _NODISCARD _CONSTEXPR20 _Vector_const_iterator operator+(const difference_type _Off) const noexcept {
        _Vector_const_iterator _Tmp = *this;
        _Tmp += _Off;
        return _Tmp;
    }

    _NODISCARD_FRIEND _CONSTEXPR20 _Vector_const_iterator operator+(
        const difference_type _Off, _Vector_const_iterator _Next) noexcept {
        _Next += _Off;
        return _Next;
    }

    _CONSTEXPR20 _Vector_const_iterator& operator-=(const difference_type _Off) noexcept {
        return *this += -_Off;
    }

    _NODISCARD _CONSTEXPR20 _Vector_const_iterator operator-(const difference_type _Off) const noexcept {
        _Vector_const_iterator _Tmp = *this;
        _Tmp -= _Off;
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20 difference_type operator-(const _Vector_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr - _Right._Ptr;
    }

    _NODISCARD _CONSTEXPR20 reference operator[](const difference_type _Off) const noexcept {
        return *(*this + _Off);
    }

    _NODISCARD _CONSTEXPR20 bool operator==(const _Vector_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr == _Right._Ptr;
    }

#if _HAS_CXX20
    _NODISCARD constexpr strong_ordering operator<=>(const _Vector_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Unfancy(_Ptr) <=> _Unfancy(_Right._Ptr);
    }
#else // ^^^ _HAS_CXX20 / !_HAS_CXX20 vvv
    _NODISCARD bool operator!=(const _Vector_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }

    _NODISCARD bool operator<(const _Vector_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr < _Right._Ptr;
    }

    _NODISCARD bool operator>(const _Vector_const_iterator& _Right) const noexcept {
        return _Right < *this;
    }

    _NODISCARD bool operator<=(const _Vector_const_iterator& _Right) const noexcept {
        return !(_Right < *this);
    }

    _NODISCARD bool operator>=(const _Vector_const_iterator& _Right) const noexcept {
        return !(*this < _Right);
    }
#endif // !_HAS_CXX20

    _CONSTEXPR20 void _Compat(const _Vector_const_iterator& _Right) const noexcept {
        // test for compatible iterator pair
#if _ITERATOR_DEBUG_LEVEL == 0
        (void) _Right;
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 / _ITERATOR_DEBUG_LEVEL != 0 vvv
        _STL_VERIFY(this->_Getcont() == _Right._Getcont(), "vector iterators incompatible");
#endif // _ITERATOR_DEBUG_LEVEL == 0
    }

#if _ITERATOR_DEBUG_LEVEL != 0
    friend _CONSTEXPR20 void _Verify_range(
        const _Vector_const_iterator& _First, const _Vector_const_iterator& _Last) noexcept {
        _STL_VERIFY(_First._Getcont() == _Last._Getcont(), "vector iterators in range are from different containers");
        _STL_VERIFY(_First._Ptr <= _Last._Ptr, "vector iterator range transposed");
    }
#endif // _ITERATOR_DEBUG_LEVEL != 0

    using _Prevent_inheriting_unwrap = _Vector_const_iterator;

    _NODISCARD _CONSTEXPR20 const value_type* _Unwrapped() const noexcept {
        return _Unfancy(_Ptr);
    }

    _CONSTEXPR20 void _Seek_to(const value_type* _It) noexcept {
        _Ptr = _Refancy<_Tptr>(const_cast<value_type*>(_It));
    }

    _Tptr _Ptr; // pointer to element in vector
};



template <class _Myvec>
class _Vector_iterator : public _Vector_const_iterator<_Myvec> {
public:
    using _Mybase = _Vector_const_iterator<_Myvec>;

#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif // __cpp_lib_concepts
    using iterator_category = random_access_iterator_tag;
    using value_type        = typename _Myvec::value_type;
    using difference_type   = typename _Myvec::difference_type;
    using pointer           = typename _Myvec::pointer;
    using reference         = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD _CONSTEXPR20 reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD _CONSTEXPR20 pointer operator->() const noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Myvec*>(this->_Getcont());
        _STL_VERIFY(this->_Ptr, "can't dereference value-initialized vector iterator");
        _STL_VERIFY(_Mycont, "can't dereference invalidated vector iterator");
        _STL_VERIFY(_Mycont->_Myfirst <= this->_Ptr && this->_Ptr < _Mycont->_Mylast,
            "can't dereference out of range vector iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        return this->_Ptr;
    }

    _CONSTEXPR20 _Vector_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _CONSTEXPR20 _Vector_iterator operator++(int) noexcept {
        _Vector_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _CONSTEXPR20 _Vector_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _CONSTEXPR20 _Vector_iterator operator--(int) noexcept {
        _Vector_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }

    _CONSTEXPR20 _Vector_iterator& operator+=(const difference_type _Off) noexcept {
        _Mybase::operator+=(_Off);
        return *this;
    }

    _NODISCARD _CONSTEXPR20 _Vector_iterator operator+(const difference_type _Off) const noexcept {
        _Vector_iterator _Tmp = *this;
        _Tmp += _Off;
        return _Tmp;
    }

    _NODISCARD_FRIEND _CONSTEXPR20 _Vector_iterator operator+(
        const difference_type _Off, _Vector_iterator _Next) noexcept {
        _Next += _Off;
        return _Next;
    }

    _CONSTEXPR20 _Vector_iterator& operator-=(const difference_type _Off) noexcept {
        _Mybase::operator-=(_Off);
        return *this;
    }

    using _Mybase::operator-;

    _NODISCARD _CONSTEXPR20 _Vector_iterator operator-(const difference_type _Off) const noexcept {
        _Vector_iterator _Tmp = *this;
        _Tmp -= _Off;
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20 reference operator[](const difference_type _Off) const noexcept {
        return const_cast<reference>(_Mybase::operator[](_Off));
    }

    using _Prevent_inheriting_unwrap = _Vector_iterator;

    _NODISCARD _CONSTEXPR20 value_type* _Unwrapped() const noexcept {
        return _Unfancy(this->_Ptr);
    }
};


//===========================================================

template <class _Mystr>
class _String_const_iterator : public _Iterator_base {
public:
#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif // __cpp_lib_concepts
    using iterator_category = random_access_iterator_tag;
    using value_type        = typename _Mystr::value_type;
    using difference_type   = typename _Mystr::difference_type;
    using pointer           = typename _Mystr::const_pointer;
    using reference         = const value_type&;

    _CONSTEXPR20 _String_const_iterator() noexcept : _Ptr() {}

    _CONSTEXPR20 _String_const_iterator(pointer _Parg, const _Container_base* _Pstring) noexcept : _Ptr(_Parg) {
        this->_Adopt(_Pstring);
    }

    _NODISCARD _CONSTEXPR20 reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL >= 1
        _STL_VERIFY(_Ptr, "cannot dereference value-initialized string iterator");
        const auto _Mycont = static_cast<const _Mystr*>(this->_Getcont());
        _STL_VERIFY(_Mycont, "cannot dereference string iterator because the iterator was"
                             " invalidated (e.g. reallocation occurred, or the string was destroyed)");
        const auto _Contptr = _Mycont->_Myptr();
        const auto _Rawptr  = _Unfancy(_Ptr);
        _STL_VERIFY(_Contptr <= _Rawptr && _Rawptr < _Contptr + _Mycont->_Mysize,
            "cannot dereference string iterator because it is out of range (e.g. an end iterator)");
#endif // _ITERATOR_DEBUG_LEVEL >= 1

        _Analysis_assume_(_Ptr);
        return *_Ptr;
    }

    _NODISCARD _CONSTEXPR20 pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _CONSTEXPR20 _String_const_iterator& operator++() noexcept {
#if _ITERATOR_DEBUG_LEVEL >= 1
        _STL_VERIFY(_Ptr, "cannot increment value-initialized string iterator");
        const auto _Mycont = static_cast<const _Mystr*>(this->_Getcont());
        _STL_VERIFY(_Mycont, "cannot increment string iterator because the iterator was"
                             " invalidated (e.g. reallocation occurred, or the string was destroyed)");
        _STL_VERIFY(_Unfancy(_Ptr) < _Mycont->_Myptr() + _Mycont->_Mysize, "cannot increment string iterator past end");
#endif // _ITERATOR_DEBUG_LEVEL >= 1

        ++_Ptr;
        return *this;
    }

    _CONSTEXPR20 _String_const_iterator operator++(int) noexcept {
        _String_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _CONSTEXPR20 _String_const_iterator& operator--() noexcept {
#if _ITERATOR_DEBUG_LEVEL >= 1
        _STL_VERIFY(_Ptr, "cannot decrement value-initialized string iterator");
        const auto _Mycont = static_cast<const _Mystr*>(this->_Getcont());
        _STL_VERIFY(_Mycont, "cannot decrement string iterator because the iterator was"
                             " invalidated (e.g. reallocation occurred, or the string was destroyed)");
        _STL_VERIFY(_Mycont->_Myptr() < _Unfancy(_Ptr), "cannot decrement string iterator before begin");
#endif // _ITERATOR_DEBUG_LEVEL >= 1

        --_Ptr;
        return *this;
    }

    _CONSTEXPR20 _String_const_iterator operator--(int) noexcept {
        _String_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

    _CONSTEXPR20 void _Verify_offset(const difference_type _Off) const noexcept {
#if _ITERATOR_DEBUG_LEVEL >= 1
        if (_Off == 0) {
            return;
        }

        _STL_ASSERT(_Ptr, "cannot seek value-initialized string iterator");
        const auto _Mycont = static_cast<const _Mystr*>(this->_Getcont());
        _STL_ASSERT(_Mycont, "cannot seek string iterator because the iterator was"
                             " invalidated (e.g. reallocation occurred, or the string was destroyed)");
        const auto _Contptr = _Mycont->_Myptr();
        const auto _Rawptr  = _Unfancy(_Ptr);

        if (_Off < 0) {
            _STL_VERIFY(_Contptr - _Rawptr <= _Off, "cannot seek string iterator before begin");
        }

        if (_Off > 0) {
            using _Size_type = typename _Mystr::size_type;
            const auto _Left = _Mycont->_Mysize - static_cast<_Size_type>(_Rawptr - _Contptr);
            _STL_VERIFY(static_cast<_Size_type>(_Off) <= _Left, "cannot seek string iterator after end");
        }
#else // ^^^ _ITERATOR_DEBUG_LEVEL >= 1 / _ITERATOR_DEBUG_LEVEL == 0 vvv
        (void) _Off;
#endif // _ITERATOR_DEBUG_LEVEL >= 1
    }

    _CONSTEXPR20 _String_const_iterator& operator+=(const difference_type _Off) noexcept {
#if _ITERATOR_DEBUG_LEVEL >= 1
        _Verify_offset(_Off);
#endif // _ITERATOR_DEBUG_LEVEL >= 1
        _Ptr += _Off;
        return *this;
    }

    _NODISCARD _CONSTEXPR20 _String_const_iterator operator+(const difference_type _Off) const noexcept {
        _String_const_iterator _Tmp = *this;
        _Tmp += _Off;
        return _Tmp;
    }

    _NODISCARD_FRIEND _CONSTEXPR20 _String_const_iterator operator+(
        const difference_type _Off, _String_const_iterator _Next) noexcept {
        _Next += _Off;
        return _Next;
    }

    _CONSTEXPR20 _String_const_iterator& operator-=(const difference_type _Off) noexcept {
        return *this += -_Off;
    }

    _NODISCARD _CONSTEXPR20 _String_const_iterator operator-(const difference_type _Off) const noexcept {
        _String_const_iterator _Tmp = *this;
        _Tmp -= _Off;
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20 difference_type operator-(const _String_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr - _Right._Ptr;
    }

    _NODISCARD _CONSTEXPR20 reference operator[](const difference_type _Off) const noexcept {
        return *(*this + _Off);
    }

    _NODISCARD _CONSTEXPR20 bool operator==(const _String_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr == _Right._Ptr;
    }

#if _HAS_CXX20
    _NODISCARD constexpr strong_ordering operator<=>(const _String_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Unfancy(_Ptr) <=> _Unfancy(_Right._Ptr);
    }
#else // ^^^ _HAS_CXX20 / !_HAS_CXX20 vvv
    _NODISCARD bool operator!=(const _String_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }

    _NODISCARD bool operator<(const _String_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Ptr < _Right._Ptr;
    }

    _NODISCARD bool operator>(const _String_const_iterator& _Right) const noexcept {
        return _Right < *this;
    }

    _NODISCARD bool operator<=(const _String_const_iterator& _Right) const noexcept {
        return !(_Right < *this);
    }

    _NODISCARD bool operator>=(const _String_const_iterator& _Right) const noexcept {
        return !(*this < _Right);
    }
#endif // !_HAS_CXX20

    _CONSTEXPR20 void _Compat(const _String_const_iterator& _Right) const noexcept {
        // test for compatible iterator pair
#if _ITERATOR_DEBUG_LEVEL >= 1
        _STL_VERIFY(this->_Getcont() == _Right._Getcont(), "string iterators incompatible (e.g."
                                                           " point to different string instances)");
#else // ^^^ _ITERATOR_DEBUG_LEVEL >= 1 / _ITERATOR_DEBUG_LEVEL == 0 vvv
        (void) _Right;
#endif // _ITERATOR_DEBUG_LEVEL
    }

#if _ITERATOR_DEBUG_LEVEL >= 1
    friend _CONSTEXPR20 void _Verify_range(
        const _String_const_iterator& _First, const _String_const_iterator& _Last) noexcept {
        _STL_VERIFY(_First._Getcont() == _Last._Getcont(), "string iterators in range are from different containers");
        _STL_VERIFY(_First._Ptr <= _Last._Ptr, "string iterator range transposed");
    }
#endif // _ITERATOR_DEBUG_LEVEL >= 1

    using _Prevent_inheriting_unwrap = _String_const_iterator;

    _NODISCARD _CONSTEXPR20 const value_type* _Unwrapped() const noexcept {
        return _Unfancy(_Ptr);
    }

    _CONSTEXPR20 void _Seek_to(const value_type* _It) noexcept {
        _Ptr = _Refancy<pointer>(const_cast<value_type*>(_It));
    }

    pointer _Ptr; // pointer to element in string
};

template <class _Mystr>
class _String_iterator : public _String_const_iterator<_Mystr> {
public:
    using _Mybase = _String_const_iterator<_Mystr>;

#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif // __cpp_lib_concepts
    using iterator_category = random_access_iterator_tag;
    using value_type        = typename _Mystr::value_type;
    using difference_type   = typename _Mystr::difference_type;
    using pointer           = typename _Mystr::pointer;
    using reference         = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD _CONSTEXPR20 reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD _CONSTEXPR20 pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _CONSTEXPR20 _String_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _CONSTEXPR20 _String_iterator operator++(int) noexcept {
        _String_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _CONSTEXPR20 _String_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _CONSTEXPR20 _String_iterator operator--(int) noexcept {
        _String_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }

    _CONSTEXPR20 _String_iterator& operator+=(const difference_type _Off) noexcept {
        _Mybase::operator+=(_Off);
        return *this;
    }

    _NODISCARD _CONSTEXPR20 _String_iterator operator+(const difference_type _Off) const noexcept {
        _String_iterator _Tmp = *this;
        _Tmp += _Off;
        return _Tmp;
    }

    _NODISCARD_FRIEND _CONSTEXPR20 _String_iterator operator+(
        const difference_type _Off, _String_iterator _Next) noexcept {
        _Next += _Off;
        return _Next;
    }

    _CONSTEXPR20 _String_iterator& operator-=(const difference_type _Off) noexcept {
        _Mybase::operator-=(_Off);
        return *this;
    }

    using _Mybase::operator-;

    _NODISCARD _CONSTEXPR20 _String_iterator operator-(const difference_type _Off) const noexcept {
        _String_iterator _Tmp = *this;
        _Tmp -= _Off;
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR20 reference operator[](const difference_type _Off) const noexcept {
        return const_cast<reference>(_Mybase::operator[](_Off));
    }

    using _Prevent_inheriting_unwrap = _String_iterator;

    _NODISCARD _CONSTEXPR20 value_type* _Unwrapped() const noexcept {
        return const_cast<value_type*>(_Unfancy(this->_Ptr));
    }
};

//==================================================

_STD_BEGIN
template <class _Mylist, class _Base = _Iterator_base0>
class _List_unchecked_const_iterator : public _Base {
public:
    using iterator_category = bidirectional_iterator_tag;

    using _Nodeptr        = typename _Mylist::_Nodeptr;
    using value_type      = typename _Mylist::value_type;
    using difference_type = typename _Mylist::difference_type;
    using pointer         = typename _Mylist::const_pointer;
    using reference       = const value_type&;

    _List_unchecked_const_iterator() noexcept : _Ptr() {}

    _List_unchecked_const_iterator(_Nodeptr _Pnode, const _Mylist* _Plist) noexcept : _Ptr(_Pnode) {
        this->_Adopt(_Plist);
    }

    _NODISCARD reference operator*() const noexcept {
        return _Ptr->_Myval;
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _List_unchecked_const_iterator& operator++() noexcept {
        _Ptr = _Ptr->_Next;
        return *this;
    }

    _List_unchecked_const_iterator operator++(int) noexcept {
        _List_unchecked_const_iterator _Tmp = *this;
        _Ptr                                = _Ptr->_Next;
        return _Tmp;
    }

    _List_unchecked_const_iterator& operator--() noexcept {
        _Ptr = _Ptr->_Prev;
        return *this;
    }

    _List_unchecked_const_iterator operator--(int) noexcept {
        _List_unchecked_const_iterator _Tmp = *this;
        _Ptr                                = _Ptr->_Prev;
        return _Tmp;
    }

    _NODISCARD bool operator==(const _List_unchecked_const_iterator& _Right) const noexcept {
        return _Ptr == _Right._Ptr;
    }

#if !_HAS_CXX20
    _NODISCARD bool operator!=(const _List_unchecked_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }
#endif // !_HAS_CXX20

    _Nodeptr _Ptr; // pointer to node
};

template <class _Mylist>
class _List_unchecked_iterator : public _List_unchecked_const_iterator<_Mylist> {
public:
    using _Mybase           = _List_unchecked_const_iterator<_Mylist>;
    using iterator_category = bidirectional_iterator_tag;

    using _Nodeptr        = typename _Mylist::_Nodeptr;
    using value_type      = typename _Mylist::value_type;
    using difference_type = typename _Mylist::difference_type;
    using pointer         = typename _Mylist::pointer;
    using reference       = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _List_unchecked_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _List_unchecked_iterator operator++(int) noexcept {
        _List_unchecked_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _List_unchecked_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _List_unchecked_iterator operator--(int) noexcept {
        _List_unchecked_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }
};

template <class _Mylist>
class _List_const_iterator : public _List_unchecked_const_iterator<_Mylist, _Iterator_base> {
public:
    using _Mybase           = _List_unchecked_const_iterator<_Mylist, _Iterator_base>;
    using iterator_category = bidirectional_iterator_tag;

    using _Nodeptr        = typename _Mylist::_Nodeptr;
    using value_type      = typename _Mylist::value_type;
    using difference_type = typename _Mylist::difference_type;
    using pointer         = typename _Mylist::const_pointer;
    using reference       = const value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        const auto _Mycont = static_cast<const _Mylist*>(this->_Getcont());
        _STL_ASSERT(_Mycont, "cannot dereference value-initialized list iterator");
        _STL_VERIFY(this->_Ptr != _Mycont->_Myhead, "cannot dereference end list iterator");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        return this->_Ptr->_Myval;
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _List_const_iterator& operator++() noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        const auto _Mycont = static_cast<const _Mylist*>(this->_Getcont());
        _STL_ASSERT(_Mycont, "cannot increment value-initialized list iterator");
        _STL_VERIFY(this->_Ptr != _Mycont->_Myhead, "cannot increment end list iterator");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        this->_Ptr = this->_Ptr->_Next;
        return *this;
    }

    _List_const_iterator operator++(int) noexcept {
        _List_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _List_const_iterator& operator--() noexcept {
        const auto _New_ptr = this->_Ptr->_Prev;
#if _ITERATOR_DEBUG_LEVEL == 2
        const auto _Mycont = static_cast<const _Mylist*>(this->_Getcont());
        _STL_ASSERT(_Mycont, "cannot decrement value-initialized list iterator");
        _STL_VERIFY(_New_ptr != _Mycont->_Myhead, "cannot decrement begin list iterator");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        this->_Ptr = _New_ptr;
        return *this;
    }

    _List_const_iterator operator--(int) noexcept {
        _List_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

    _NODISCARD bool operator==(const _List_const_iterator& _Right) const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(this->_Getcont() == _Right._Getcont(), "list iterators incompatible");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        return this->_Ptr == _Right._Ptr;
    }

#if !_HAS_CXX20
    _NODISCARD bool operator!=(const _List_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }
#endif // !_HAS_CXX20

#if _ITERATOR_DEBUG_LEVEL == 2
    friend void _Verify_range(const _List_const_iterator& _First, const _List_const_iterator& _Last) noexcept {
        _STL_VERIFY(_First._Getcont() == _Last._Getcont(), "list iterators in range are from different containers");
    }
#endif // _ITERATOR_DEBUG_LEVEL == 2

    using _Prevent_inheriting_unwrap = _List_const_iterator;

    _NODISCARD _List_unchecked_const_iterator<_Mylist> _Unwrapped() const noexcept {
        return _List_unchecked_const_iterator<_Mylist>(this->_Ptr, static_cast<const _Mylist*>(this->_Getcont()));
    }

    void _Seek_to(const _List_unchecked_const_iterator<_Mylist> _It) noexcept {
        this->_Ptr = _It._Ptr;
    }
};

template <class _Mylist>
class _List_iterator : public _List_const_iterator<_Mylist> {
public:
    using _Mybase           = _List_const_iterator<_Mylist>;
    using iterator_category = bidirectional_iterator_tag;

    using _Nodeptr        = typename _Mylist::_Nodeptr;
    using value_type      = typename _Mylist::value_type;
    using difference_type = typename _Mylist::difference_type;
    using pointer         = typename _Mylist::pointer;
    using reference       = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _List_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _List_iterator operator++(int) noexcept {
        _List_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _List_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _List_iterator operator--(int) noexcept {
        _List_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }

    using _Prevent_inheriting_unwrap = _List_iterator;

    _NODISCARD _List_unchecked_iterator<_Mylist> _Unwrapped() const noexcept {
        return _List_unchecked_iterator<_Mylist>(this->_Ptr, static_cast<const _Mylist*>(this->_Getcont()));
    }
};

//==========================================

_STD_BEGIN
template <class _Mylist, class _Base = _Iterator_base0>
class _Flist_unchecked_const_iterator : public _Base {
public:
    using iterator_category = forward_iterator_tag;

    using _Nodeptr        = typename _Mylist::_Nodeptr;
    using value_type      = typename _Mylist::value_type;
    using difference_type = typename _Mylist::difference_type;
    using pointer         = typename _Mylist::const_pointer;
    using reference       = const value_type&;

    _Flist_unchecked_const_iterator() noexcept : _Ptr() {}

    _Flist_unchecked_const_iterator(_Nodeptr _Pnode, const _Mylist* _Plist) noexcept : _Ptr(_Pnode) {
        this->_Adopt(_Plist);
    }

    _NODISCARD reference operator*() const noexcept {
        return _Ptr->_Myval;
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Flist_unchecked_const_iterator& operator++() noexcept {
        _Ptr = _Ptr->_Next;
        return *this;
    }

    _Flist_unchecked_const_iterator operator++(int) noexcept {
        _Flist_unchecked_const_iterator _Tmp = *this;
        _Ptr                                 = _Ptr->_Next;
        return _Tmp;
    }

    _NODISCARD bool operator==(const _Flist_unchecked_const_iterator& _Right) const noexcept {
        return _Ptr == _Right._Ptr;
    }

#if !_HAS_CXX20
    _NODISCARD bool operator!=(const _Flist_unchecked_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }
#endif // !_HAS_CXX20

    _NODISCARD bool operator==(_Default_sentinel) const noexcept {
        return _Ptr == nullptr;
    }

#if !_HAS_CXX20
    _NODISCARD bool operator!=(_Default_sentinel) const noexcept {
        return _Ptr != nullptr;
    }
#endif // !_HAS_CXX20

    _Nodeptr _Ptr; // pointer to node
};

template <class _Mylist>
class _Flist_unchecked_iterator : public _Flist_unchecked_const_iterator<_Mylist> {
public:
    using _Mybase           = _Flist_unchecked_const_iterator<_Mylist>;
    using iterator_category = forward_iterator_tag;

    using _Nodeptr        = typename _Mylist::_Nodeptr;
    using value_type      = typename _Mylist::value_type;
    using difference_type = typename _Mylist::difference_type;
    using pointer         = typename _Mylist::pointer;
    using reference       = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Flist_unchecked_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _Flist_unchecked_iterator operator++(int) noexcept {
        _Flist_unchecked_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }
};

template <class _Mylist>
class _Flist_const_iterator : public _Flist_unchecked_const_iterator<_Mylist, _Iterator_base> {
public:
    using _Mybase           = _Flist_unchecked_const_iterator<_Mylist, _Iterator_base>;
    using iterator_category = forward_iterator_tag;

    using _Nodeptr        = typename _Mylist::_Nodeptr;
    using value_type      = typename _Mylist::value_type;
    using difference_type = typename _Mylist::difference_type;
    using pointer         = typename _Mylist::const_pointer;
    using reference       = const value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        const auto _Mycont = static_cast<const _Mylist*>(this->_Getcont());
        _STL_ASSERT(_Mycont, "cannot dereference value-initialized forward_list iterator");
        _STL_VERIFY(this->_Ptr != _Mycont->_Before_head(), "cannot dereference forward_list before_begin");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        return this->_Ptr->_Myval;
    }

    _Flist_const_iterator& operator++() noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(this->_Getcont(), "forward_list iterator not incrementable");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        this->_Ptr = this->_Ptr->_Next;
        return *this;
    }

    _Flist_const_iterator operator++(int) noexcept {
        _Flist_const_iterator _Tmp = *this;
        this->_Ptr                 = this->_Ptr->_Next;
        return _Tmp;
    }

    _NODISCARD bool operator==(const _Flist_const_iterator& _Right) const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(this->_Getcont() == _Right._Getcont(), "forward_list iterators incompatible");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        return this->_Ptr == _Right._Ptr;
    }

#if !_HAS_CXX20
    _NODISCARD bool operator!=(const _Flist_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }
#endif // !_HAS_CXX20

#if _ITERATOR_DEBUG_LEVEL == 2
    friend void _Verify_range(const _Flist_const_iterator& _First, const _Flist_const_iterator& _Last) noexcept {
        _STL_VERIFY(
            _First._Getcont() == _Last._Getcont(), "forward_list iterators in range are from different containers");
    }
#endif // _ITERATOR_DEBUG_LEVEL == 2

    using _Prevent_inheriting_unwrap = _Flist_const_iterator;

    _NODISCARD _Flist_unchecked_const_iterator<_Mylist> _Unwrapped() const noexcept {
        return _Flist_unchecked_const_iterator<_Mylist>(this->_Ptr, static_cast<const _Mylist*>(this->_Getcont()));
    }

    void _Seek_to(const _Flist_unchecked_const_iterator<_Mylist> _It) noexcept {
        this->_Ptr = _It._Ptr;
    }
};

template <class _Mylist>
class _Flist_iterator : public _Flist_const_iterator<_Mylist> {
public:
    using _Mybase           = _Flist_const_iterator<_Mylist>;
    using iterator_category = forward_iterator_tag;

    using _Nodeptr        = typename _Mylist::_Nodeptr;
    using value_type      = typename _Mylist::value_type;
    using difference_type = typename _Mylist::difference_type;
    using pointer         = typename _Mylist::pointer;
    using reference       = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Flist_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _Flist_iterator operator++(int) noexcept {
        _Flist_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    using _Prevent_inheriting_unwrap = _Flist_iterator;

    _NODISCARD _Flist_unchecked_iterator<_Mylist> _Unwrapped() const noexcept {
        return _Flist_unchecked_iterator<_Mylist>(this->_Ptr, static_cast<const _Mylist*>(this->_Getcont()));
    }
};


//===========================================
template <class _Mydeque>
class _Deque_const_iterator : public _Iterator_base12 {
private:
    using _Size_type = typename _Mydeque::size_type;

    static constexpr int _Block_size = _Mydeque::_Block_size;

public:
    using iterator_category = random_access_iterator_tag;

    using value_type      = typename _Mydeque::value_type;
    using difference_type = typename _Mydeque::difference_type;
    using pointer         = typename _Mydeque::const_pointer;
    using reference       = const value_type&;

    using _Mydeque_t = _Mydeque; // helper for expression evaluator
    enum { _EEN_DS = _Block_size }; // helper for expression evaluator
    _Deque_const_iterator() noexcept : _Myoff(0) {
        _Setcont(nullptr);
    }

    _Deque_const_iterator(_Size_type _Off, const _Container_base12* _Pdeque) noexcept : _Myoff(_Off) {
        _Setcont(static_cast<const _Mydeque*>(_Pdeque));
    }

    _NODISCARD reference operator*() const noexcept {
        const auto _Mycont = static_cast<const _Mydeque*>(this->_Getcont());
#if _ITERATOR_DEBUG_LEVEL != 0
        _STL_VERIFY(_Mycont, "cannot dereference value-initialized deque iterator");
        _STL_VERIFY(_Mycont->_Myoff <= this->_Myoff && this->_Myoff < _Mycont->_Myoff + _Mycont->_Mysize,
            "cannot deference out of range deque iterator");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        _Size_type _Block = _Mycont->_Getblock(_Myoff);
        _Size_type _Off   = _Myoff % _Block_size;
        return _Mycont->_Map[_Block][_Off];
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Deque_const_iterator& operator++() noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Mydeque*>(this->_Getcont());
        _STL_VERIFY(_Mycont, "cannot increment value-initialized deque iterator");
        _STL_VERIFY(this->_Myoff < _Mycont->_Myoff + _Mycont->_Mysize, "cannot increment deque iterator past end");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        ++_Myoff;
        return *this;
    }

    _Deque_const_iterator operator++(int) noexcept {
        _Deque_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _Deque_const_iterator& operator--() noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        const auto _Mycont = static_cast<const _Mydeque*>(this->_Getcont());
        _STL_VERIFY(_Mycont, "cannot decrement value-initialized deque iterator");
        _STL_VERIFY(_Mycont->_Myoff < this->_Myoff, "cannot decrement deque iterator before begin");
#endif // _ITERATOR_DEBUG_LEVEL != 0

        --_Myoff;
        return *this;
    }

    _Deque_const_iterator operator--(int) noexcept {
        _Deque_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

    _Deque_const_iterator& operator+=(const difference_type _Off) noexcept {
#if _ITERATOR_DEBUG_LEVEL != 0
        if (_Off != 0) {
            const auto _Mycont = static_cast<const _Mydeque*>(this->_Getcont());
            _STL_VERIFY(_Mycont, "cannot seek value-initialized deque iterator");
            _STL_VERIFY(
                _Mycont->_Myoff <= this->_Myoff + _Off && this->_Myoff + _Off <= _Mycont->_Myoff + _Mycont->_Mysize,
                "cannot seek deque iterator out of range");
        }
#endif // _ITERATOR_DEBUG_LEVEL != 0

        _Myoff += _Off;
        return *this;
    }

    _NODISCARD _Deque_const_iterator operator+(const difference_type _Off) const noexcept {
        _Deque_const_iterator _Tmp = *this;
        _Tmp += _Off;
        return _Tmp;
    }

    _NODISCARD_FRIEND _Deque_const_iterator operator+(
        const difference_type _Off, _Deque_const_iterator _Next) noexcept {
        _Next += _Off;
        return _Next;
    }

    _Deque_const_iterator& operator-=(const difference_type _Off) noexcept {
        return *this += -_Off;
    }

    _NODISCARD _Deque_const_iterator operator-(const difference_type _Off) const noexcept {
        _Deque_const_iterator _Tmp = *this;
        _Tmp -= _Off;
        return _Tmp;
    }

    _NODISCARD difference_type operator-(const _Deque_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return static_cast<difference_type>(this->_Myoff - _Right._Myoff);
    }

    _NODISCARD reference operator[](const difference_type _Off) const noexcept {
        return *(*this + _Off);
    }

    _NODISCARD bool operator==(const _Deque_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return this->_Myoff == _Right._Myoff;
    }

#if _HAS_CXX20
    _NODISCARD strong_ordering operator<=>(const _Deque_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return this->_Myoff <=> _Right._Myoff;
    }
#else // ^^^ _HAS_CXX20 / !_HAS_CXX20 vvv
    _NODISCARD bool operator!=(const _Deque_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }

    _NODISCARD bool operator<(const _Deque_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return this->_Myoff < _Right._Myoff;
    }

    _NODISCARD bool operator>(const _Deque_const_iterator& _Right) const noexcept {
        return _Right < *this;
    }

    _NODISCARD bool operator<=(const _Deque_const_iterator& _Right) const noexcept {
        return !(_Right < *this);
    }

    _NODISCARD bool operator>=(const _Deque_const_iterator& _Right) const noexcept {
        return !(*this < _Right);
    }
#endif // !_HAS_CXX20

    void _Compat(const _Deque_const_iterator& _Right) const noexcept { // test for compatible iterator pair
#if _ITERATOR_DEBUG_LEVEL == 0
        (void) _Right;
#else // _ITERATOR_DEBUG_LEVEL == 0
        _STL_VERIFY(this->_Getcont() == _Right._Getcont(), "deque iterators incompatible");
#endif // _ITERATOR_DEBUG_LEVEL == 0
    }

    void _Setcont(const _Mydeque* _Pdeque) noexcept { // set container pointer
        this->_Adopt(_Pdeque);
    }

    using _Prevent_inheriting_unwrap = _Deque_const_iterator;

    _NODISCARD _Deque_unchecked_const_iterator<_Mydeque> _Unwrapped() const noexcept {
        return {this->_Myoff, this->_Getcont()};
    }

    void _Verify_offset(const difference_type _Off) const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 0
        (void) _Off;
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 / _ITERATOR_DEBUG_LEVEL != 0 vvv
        if (_Off != 0) {
            const auto _Mycont = static_cast<const _Mydeque*>(this->_Getcont());
            _STL_VERIFY(_Mycont, "cannot use value-initialized deque iterator");
            _STL_VERIFY(
                _Mycont->_Myoff <= this->_Myoff + _Off && this->_Myoff + _Off <= _Mycont->_Myoff + _Mycont->_Mysize,
                "cannot seek deque iterator out of range");
        }
#endif // _ITERATOR_DEBUG_LEVEL == 0
    }

#if _ITERATOR_DEBUG_LEVEL != 0
    friend void _Verify_range(const _Deque_const_iterator& _First, const _Deque_const_iterator& _Last) noexcept {
        // note _Compat check inside operator<=
        _STL_VERIFY(_First <= _Last, "deque iterators transposed");
    }
#endif // _ITERATOR_DEBUG_LEVEL != 0

    void _Seek_to(const _Deque_unchecked_const_iterator<_Mydeque>& _UIt) noexcept {
        _Myoff = _UIt._Myoff;
    }

    _Size_type _Myoff; // offset of element in deque
};

template <class _Mydeque>
class _Deque_iterator : public _Deque_const_iterator<_Mydeque> {
private:
    using _Size_type = typename _Mydeque::size_type;
    using _Mybase    = _Deque_const_iterator<_Mydeque>;

public:
    using iterator_category = random_access_iterator_tag;

    using value_type      = typename _Mydeque::value_type;
    using difference_type = typename _Mydeque::difference_type;
    using pointer         = typename _Mydeque::pointer;
    using reference       = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Deque_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _Deque_iterator operator++(int) noexcept {
        _Deque_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _Deque_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _Deque_iterator operator--(int) noexcept {
        _Deque_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }

    _Deque_iterator& operator+=(const difference_type _Off) noexcept {
        _Mybase::operator+=(_Off);
        return *this;
    }

    _NODISCARD _Deque_iterator operator+(const difference_type _Off) const noexcept {
        _Deque_iterator _Tmp = *this;
        _Tmp += _Off;
        return _Tmp;
    }

    _NODISCARD_FRIEND _Deque_iterator operator+(const difference_type _Off, _Deque_iterator _Next) noexcept {
        _Next += _Off;
        return _Next;
    }

    _Deque_iterator& operator-=(const difference_type _Off) noexcept {
        _Mybase::operator-=(_Off);
        return *this;
    }

    using _Mybase::operator-;

    _NODISCARD _Deque_iterator operator-(const difference_type _Off) const noexcept {
        _Deque_iterator _Tmp = *this;
        _Tmp -= _Off;
        return _Tmp;
    }

    _NODISCARD reference operator[](const difference_type _Off) const noexcept {
        return const_cast<reference>(_Mybase::operator[](_Off));
    }

    using _Prevent_inheriting_unwrap = _Deque_iterator;

    _NODISCARD _Deque_unchecked_iterator<_Mydeque> _Unwrapped() const noexcept {
        return {this->_Myoff, this->_Getcont()};
    }
};



//==========================================================
template <class _Ty, size_t _Size>
class _Array_const_iterator
#if _ITERATOR_DEBUG_LEVEL != 0
    : private _Iterator_base12_compatible
#endif // _ITERATOR_DEBUG_LEVEL != 0
{
public:
#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif // __cpp_lib_concepts
    using iterator_category = random_access_iterator_tag;
    using value_type        = _Ty;
    using difference_type   = ptrdiff_t;
    using pointer           = const _Ty*;
    using reference         = const _Ty&;

    enum { _EEN_SIZE = _Size }; // helper for expression evaluator

#if _ITERATOR_DEBUG_LEVEL == 0
    _CONSTEXPR17 _Array_const_iterator() noexcept : _Ptr() {}

    _CONSTEXPR17 explicit _Array_const_iterator(pointer _Parg, size_t _Off = 0) noexcept : _Ptr(_Parg + _Off) {}

    _NODISCARD _CONSTEXPR17 reference operator*() const noexcept {
        return *_Ptr;
    }

    _NODISCARD _CONSTEXPR17 pointer operator->() const noexcept {
        return _Ptr;
    }

    _CONSTEXPR17 _Array_const_iterator& operator++() noexcept {
        ++_Ptr;
        return *this;
    }

    _CONSTEXPR17 _Array_const_iterator operator++(int) noexcept {
        _Array_const_iterator _Tmp = *this;
        ++_Ptr;
        return _Tmp;
    }

    _CONSTEXPR17 _Array_const_iterator& operator--() noexcept {
        --_Ptr;
        return *this;
    }

    _CONSTEXPR17 _Array_const_iterator operator--(int) noexcept {
        _Array_const_iterator _Tmp = *this;
        --_Ptr;
        return _Tmp;
    }

    _CONSTEXPR17 _Array_const_iterator& operator+=(const ptrdiff_t _Off) noexcept {
        _Ptr += _Off;
        return *this;
    }

    _CONSTEXPR17 _Array_const_iterator& operator-=(const ptrdiff_t _Off) noexcept {
        _Ptr -= _Off;
        return *this;
    }

    _NODISCARD _CONSTEXPR17 ptrdiff_t operator-(const _Array_const_iterator& _Right) const noexcept {
        return _Ptr - _Right._Ptr;
    }

    _NODISCARD _CONSTEXPR17 reference operator[](const ptrdiff_t _Off) const noexcept {
        return _Ptr[_Off];
    }

    _NODISCARD _CONSTEXPR17 bool operator==(const _Array_const_iterator& _Right) const noexcept {
        return _Ptr == _Right._Ptr;
    }

#if _HAS_CXX20
    _NODISCARD constexpr strong_ordering operator<=>(const _Array_const_iterator& _Right) const noexcept {
        return _Ptr <=> _Right._Ptr;
    }
#else // ^^^ _HAS_CXX20 / !_HAS_CXX20 vvv
    _NODISCARD _CONSTEXPR17 bool operator<(const _Array_const_iterator& _Right) const noexcept {
        return _Ptr < _Right._Ptr;
    }
#endif // !_HAS_CXX20

    using _Prevent_inheriting_unwrap = _Array_const_iterator;

    _NODISCARD constexpr pointer _Unwrapped() const noexcept {
        return _Ptr;
    }

    static constexpr bool _Unwrap_when_unverified = true;

    constexpr void _Seek_to(pointer _It) noexcept {
        _Ptr = _It;
    }

private:
    pointer _Ptr; // beginning of array

#else // ^^^ _ITERATOR_DEBUG_LEVEL == 0 / _ITERATOR_DEBUG_LEVEL != 0 vvv
    _CONSTEXPR17 _Array_const_iterator() noexcept : _Ptr(), _Idx(0) {}

    _CONSTEXPR17 explicit _Array_const_iterator(pointer _Parg, size_t _Off = 0) noexcept : _Ptr(_Parg), _Idx(_Off) {}

    _NODISCARD _CONSTEXPR17 reference operator*() const noexcept {
        return *operator->();
    }

    _NODISCARD _CONSTEXPR17 pointer operator->() const noexcept {
        _STL_VERIFY(_Ptr, "cannot dereference value-initialized array iterator");
        _STL_VERIFY(_Idx < _Size, "cannot dereference out of range array iterator");
        return _Ptr + _Idx;
    }

    _CONSTEXPR17 _Array_const_iterator& operator++() noexcept {
        _STL_VERIFY(_Ptr, "cannot increment value-initialized array iterator");
        _STL_VERIFY(_Idx < _Size, "cannot increment array iterator past end");
        ++_Idx;
        return *this;
    }

    _CONSTEXPR17 _Array_const_iterator operator++(int) noexcept {
        _Array_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _CONSTEXPR17 _Array_const_iterator& operator--() noexcept {
        _STL_VERIFY(_Ptr, "cannot decrement value-initialized array iterator");
        _STL_VERIFY(_Idx != 0, "cannot decrement array iterator before begin");
        --_Idx;
        return *this;
    }

    _CONSTEXPR17 _Array_const_iterator operator--(int) noexcept {
        _Array_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

    constexpr void _Verify_offset(const ptrdiff_t _Off) const noexcept {
        if (_Off != 0) {
            _STL_VERIFY(_Ptr, "cannot seek value-initialized array iterator");
        }

        if (_Off < 0) {
            _STL_VERIFY(_Idx >= size_t{0} - static_cast<size_t>(_Off), "cannot seek array iterator before begin");
        }

        if (_Off > 0) {
            _STL_VERIFY(_Size - _Idx >= static_cast<size_t>(_Off), "cannot seek array iterator after end");
        }
    }

    _CONSTEXPR17 _Array_const_iterator& operator+=(const ptrdiff_t _Off) noexcept {
        _Verify_offset(_Off);
        _Idx += static_cast<size_t>(_Off);
        return *this;
    }

    _CONSTEXPR17 _Array_const_iterator& operator-=(const ptrdiff_t _Off) noexcept {
        return *this += -_Off;
    }

    _NODISCARD _CONSTEXPR17 ptrdiff_t operator-(const _Array_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return static_cast<ptrdiff_t>(_Idx - _Right._Idx);
    }

    _NODISCARD _CONSTEXPR17 reference operator[](const ptrdiff_t _Off) const noexcept {
        return *(*this + _Off);
    }

    _NODISCARD _CONSTEXPR17 bool operator==(const _Array_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Idx == _Right._Idx;
    }

#if _HAS_CXX20
    _NODISCARD constexpr strong_ordering operator<=>(const _Array_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Idx <=> _Right._Idx;
    }
#else // ^^^ _HAS_CXX20 / !_HAS_CXX20 vvv
    _NODISCARD _CONSTEXPR17 bool operator<(const _Array_const_iterator& _Right) const noexcept {
        _Compat(_Right);
        return _Idx < _Right._Idx;
    }
#endif // !_HAS_CXX20

    _CONSTEXPR17 void _Compat(const _Array_const_iterator& _Right) const noexcept { // test for compatible iterator pair
        _STL_VERIFY(_Ptr == _Right._Ptr, "array iterators incompatible");
    }

    using _Prevent_inheriting_unwrap = _Array_const_iterator;

    _NODISCARD constexpr pointer _Unwrapped() const noexcept {
        return _Ptr + _Idx;
    }

    constexpr void _Verify_with(const _Array_const_iterator& _Last) const noexcept {
        // note _Compat check inside operator<=
        _STL_VERIFY(*this <= _Last, "array iterator range transposed");
    }

    constexpr void _Seek_to(pointer _It) noexcept {
        _Idx = static_cast<size_t>(_It - _Ptr);
    }

private:
    pointer _Ptr; // beginning of array
    size_t _Idx; // offset into array
#endif // _ITERATOR_DEBUG_LEVEL == 0

public:
    _NODISCARD _CONSTEXPR17 _Array_const_iterator operator+(const ptrdiff_t _Off) const noexcept {
        _Array_const_iterator _Tmp = *this;
        _Tmp += _Off;
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR17 _Array_const_iterator operator-(const ptrdiff_t _Off) const noexcept {
        _Array_const_iterator _Tmp = *this;
        _Tmp -= _Off;
        return _Tmp;
    }

    _NODISCARD_FRIEND _CONSTEXPR17 _Array_const_iterator operator+(
        const ptrdiff_t _Off, _Array_const_iterator _Next) noexcept {
        _Next += _Off;
        return _Next;
    }

#if !_HAS_CXX20
    _NODISCARD _CONSTEXPR17 bool operator!=(const _Array_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }

    _NODISCARD _CONSTEXPR17 bool operator>(const _Array_const_iterator& _Right) const noexcept {
        return _Right < *this;
    }

    _NODISCARD _CONSTEXPR17 bool operator<=(const _Array_const_iterator& _Right) const noexcept {
        return !(_Right < *this);
    }

    _NODISCARD _CONSTEXPR17 bool operator>=(const _Array_const_iterator& _Right) const noexcept {
        return !(*this < _Right);
    }
#endif // !_HAS_CXX20
};

template <class _Ty, size_t _Size>
class _Array_iterator : public _Array_const_iterator<_Ty, _Size> {
public:
    using _Mybase = _Array_const_iterator<_Ty, _Size>;

#ifdef __cpp_lib_concepts
    using iterator_concept = contiguous_iterator_tag;
#endif // __cpp_lib_concepts
    using iterator_category = random_access_iterator_tag;
    using value_type        = _Ty;
    using difference_type   = ptrdiff_t;
    using pointer           = _Ty*;
    using reference         = _Ty&;

    enum { _EEN_SIZE = _Size }; // helper for expression evaluator

    _CONSTEXPR17 _Array_iterator() noexcept {}

    _CONSTEXPR17 explicit _Array_iterator(pointer _Parg, size_t _Off = 0) noexcept : _Mybase(_Parg, _Off) {}

    _NODISCARD _CONSTEXPR17 reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD _CONSTEXPR17 pointer operator->() const noexcept {
        return const_cast<pointer>(_Mybase::operator->());
    }

    _CONSTEXPR17 _Array_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _CONSTEXPR17 _Array_iterator operator++(int) noexcept {
        _Array_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _CONSTEXPR17 _Array_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _CONSTEXPR17 _Array_iterator operator--(int) noexcept {
        _Array_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }

    _CONSTEXPR17 _Array_iterator& operator+=(const ptrdiff_t _Off) noexcept {
        _Mybase::operator+=(_Off);
        return *this;
    }

    _NODISCARD _CONSTEXPR17 _Array_iterator operator+(const ptrdiff_t _Off) const noexcept {
        _Array_iterator _Tmp = *this;
        _Tmp += _Off;
        return _Tmp;
    }

    _NODISCARD_FRIEND _CONSTEXPR17 _Array_iterator operator+(const ptrdiff_t _Off, _Array_iterator _Next) noexcept {
        _Next += _Off;
        return _Next;
    }

    _CONSTEXPR17 _Array_iterator& operator-=(const ptrdiff_t _Off) noexcept {
        _Mybase::operator-=(_Off);
        return *this;
    }

    using _Mybase::operator-;

    _NODISCARD _CONSTEXPR17 _Array_iterator operator-(const ptrdiff_t _Off) const noexcept {
        _Array_iterator _Tmp = *this;
        _Tmp -= _Off;
        return _Tmp;
    }

    _NODISCARD _CONSTEXPR17 reference operator[](const ptrdiff_t _Off) const noexcept {
        return const_cast<reference>(_Mybase::operator[](_Off));
    }

    using _Prevent_inheriting_unwrap = _Array_iterator;

    _NODISCARD constexpr pointer _Unwrapped() const noexcept {
        return const_cast<pointer>(_Mybase::_Unwrapped());
    }
};

//====================================

_STD_BEGIN
template <class _Mytree, class _Base = _Iterator_base0>
class _Tree_unchecked_const_iterator : public _Base {
public:
    using iterator_category = bidirectional_iterator_tag;

    using _Nodeptr        = typename _Mytree::_Nodeptr;
    using value_type      = typename _Mytree::value_type;
    using difference_type = typename _Mytree::difference_type;
    using pointer         = typename _Mytree::const_pointer;
    using reference       = const value_type&;

    _Tree_unchecked_const_iterator() noexcept : _Ptr() {}

    _Tree_unchecked_const_iterator(_Nodeptr _Pnode, const _Mytree* _Plist) noexcept : _Ptr(_Pnode) {
        this->_Adopt(_Plist);
    }

    _NODISCARD reference operator*() const noexcept {
        return _Ptr->_Myval;
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Tree_unchecked_const_iterator& operator++() noexcept {
        if (_Ptr->_Right->_Isnil) { // climb looking for right subtree
            _Nodeptr _Pnode;
            while (!(_Pnode = _Ptr->_Parent)->_Isnil && _Ptr == _Pnode->_Right) {
                _Ptr = _Pnode; // ==> parent while right subtree
            }

            _Ptr = _Pnode; // ==> parent (head if end())
        } else {
            _Ptr = _Mytree::_Min(_Ptr->_Right); // ==> smallest of right subtree
        }

        return *this;
    }

    _Tree_unchecked_const_iterator operator++(int) noexcept {
        _Tree_unchecked_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _Tree_unchecked_const_iterator& operator--() noexcept {
        if (_Ptr->_Isnil) {
            _Ptr = _Ptr->_Right; // end() ==> rightmost
        } else if (_Ptr->_Left->_Isnil) { // climb looking for left subtree
            _Nodeptr _Pnode;
            while (!(_Pnode = _Ptr->_Parent)->_Isnil && _Ptr == _Pnode->_Left) {
                _Ptr = _Pnode; // ==> parent while left subtree
            }

            if (!_Ptr->_Isnil) { // decrement non-begin()
                _Ptr = _Pnode; // ==> parent if not head
            }
        } else {
            _Ptr = _Mytree::_Max(_Ptr->_Left); // ==> largest of left subtree
        }

        return *this;
    }

    _Tree_unchecked_const_iterator operator--(int) noexcept {
        _Tree_unchecked_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

    _NODISCARD bool operator==(const _Tree_unchecked_const_iterator& _Right) const noexcept {
        return _Ptr == _Right._Ptr;
    }

#if !_HAS_CXX20
    _NODISCARD bool operator!=(const _Tree_unchecked_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }
#endif // !_HAS_CXX20

    _NODISCARD bool operator==(_Default_sentinel) const noexcept {
        return !!_Ptr->_Isnil; // TRANSITION, avoid warning C4800:
                               // "Implicit conversion from 'char' to bool. Possible information loss" (/Wall)
    }

#if !_HAS_CXX20
    _NODISCARD bool operator!=(_Default_sentinel) const noexcept {
        return !_Ptr->_Isnil;
    }
#endif // !_HAS_CXX20

    _Nodeptr _Ptr; // pointer to node
};

template <class _Mytree>
class _Tree_unchecked_iterator : public _Tree_unchecked_const_iterator<_Mytree> {
public:
    using _Mybase           = _Tree_unchecked_const_iterator<_Mytree>;
    using iterator_category = bidirectional_iterator_tag;

    using _Nodeptr        = typename _Mytree::_Nodeptr;
    using value_type      = typename _Mytree::value_type;
    using difference_type = typename _Mytree::difference_type;
    using pointer         = typename _Mytree::pointer;
    using reference       = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Tree_unchecked_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _Tree_unchecked_iterator operator++(int) noexcept {
        _Tree_unchecked_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _Tree_unchecked_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _Tree_unchecked_iterator operator--(int) noexcept {
        _Tree_unchecked_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }
};

template <class _Mytree>
class _Tree_const_iterator : public _Tree_unchecked_const_iterator<_Mytree, _Iterator_base> {
public:
    using _Mybase           = _Tree_unchecked_const_iterator<_Mytree, _Iterator_base>;
    using iterator_category = bidirectional_iterator_tag;

    using _Nodeptr        = typename _Mytree::_Nodeptr;
    using value_type      = typename _Mytree::value_type;
    using difference_type = typename _Mytree::difference_type;
    using pointer         = typename _Mytree::const_pointer;
    using reference       = const value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        const auto _Mycont = static_cast<const _Mytree*>(this->_Getcont());
        _STL_ASSERT(_Mycont, "cannot dereference value-initialized map/set iterator");
        _STL_VERIFY(this->_Ptr != _Mycont->_Myhead, "cannot dereference end map/set iterator");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        return this->_Ptr->_Myval;
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Tree_const_iterator& operator++() noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(this->_Getcont(), "cannot increment value-initialized map/set iterator");
        _STL_VERIFY(!this->_Ptr->_Isnil, "cannot increment end map/set iterator");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        _Mybase::operator++();
        return *this;
    }

    _Tree_const_iterator operator++(int) noexcept {
        _Tree_const_iterator _Tmp = *this;
        ++*this;
        return _Tmp;
    }

    _Tree_const_iterator& operator--() noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_ASSERT(this->_Getcont(), "cannot decrement value-initialized map/set iterator");
        _Nodeptr _Ptrsav = this->_Ptr;
        _Mybase::operator--();
        _STL_VERIFY(_Ptrsav != this->_Ptr, "cannot decrement begin map/set iterator");
#else // ^^^ _ITERATOR_DEBUG_LEVEL == 2 / _ITERATOR_DEBUG_LEVEL != 2 vvv
        _Mybase::operator--();
#endif // _ITERATOR_DEBUG_LEVEL == 2

        return *this;
    }

    _Tree_const_iterator operator--(int) noexcept {
        _Tree_const_iterator _Tmp = *this;
        --*this;
        return _Tmp;
    }

    _NODISCARD bool operator==(const _Tree_const_iterator& _Right) const noexcept {
#if _ITERATOR_DEBUG_LEVEL == 2
        _STL_VERIFY(this->_Getcont() == _Right._Getcont(), "map/set iterators incompatible");
#endif // _ITERATOR_DEBUG_LEVEL == 2

        return this->_Ptr == _Right._Ptr;
    }

#if !_HAS_CXX20
    _NODISCARD bool operator!=(const _Tree_const_iterator& _Right) const noexcept {
        return !(*this == _Right);
    }
#endif // !_HAS_CXX20

#if _ITERATOR_DEBUG_LEVEL == 2
    friend void _Verify_range(const _Tree_const_iterator& _First, const _Tree_const_iterator& _Last) noexcept {
        _STL_VERIFY(_First._Getcont() == _Last._Getcont(), "map/set iterators in range are from different containers");
    }
#endif // _ITERATOR_DEBUG_LEVEL == 2

    using _Prevent_inheriting_unwrap = _Tree_const_iterator;

    _NODISCARD _Tree_unchecked_const_iterator<_Mytree> _Unwrapped() const noexcept {
        return _Tree_unchecked_const_iterator<_Mytree>(this->_Ptr, static_cast<const _Mytree*>(this->_Getcont()));
    }

    void _Seek_to(const _Tree_unchecked_const_iterator<_Mytree> _It) noexcept {
        this->_Ptr = _It._Ptr;
    }
};

template <class _Mytree>
class _Tree_iterator : public _Tree_const_iterator<_Mytree> {
public:
    using _Mybase           = _Tree_const_iterator<_Mytree>;
    using iterator_category = bidirectional_iterator_tag;

    using _Nodeptr        = typename _Mytree::_Nodeptr;
    using value_type      = typename _Mytree::value_type;
    using difference_type = typename _Mytree::difference_type;

    using pointer   = typename _Mytree::pointer;
    using reference = value_type&;

    using _Mybase::_Mybase;

    _NODISCARD reference operator*() const noexcept {
        return const_cast<reference>(_Mybase::operator*());
    }

    _NODISCARD pointer operator->() const noexcept {
        return pointer_traits<pointer>::pointer_to(**this);
    }

    _Tree_iterator& operator++() noexcept {
        _Mybase::operator++();
        return *this;
    }

    _Tree_iterator operator++(int) noexcept {
        _Tree_iterator _Tmp = *this;
        _Mybase::operator++();
        return _Tmp;
    }

    _Tree_iterator& operator--() noexcept {
        _Mybase::operator--();
        return *this;
    }

    _Tree_iterator operator--(int) noexcept {
        _Tree_iterator _Tmp = *this;
        _Mybase::operator--();
        return _Tmp;
    }

    using _Prevent_inheriting_unwrap = _Tree_iterator;

    _NODISCARD _Tree_unchecked_iterator<_Mytree> _Unwrapped() const noexcept {
        return _Tree_unchecked_iterator<_Mytree>(this->_Ptr, static_cast<const _Mytree*>(this->_Getcont()));
    }
};

//==============================================================