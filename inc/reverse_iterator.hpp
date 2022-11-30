#pragma once

#include "iterator.hpp"

namespace ft {

template< class Iter >
class reverse_iterator
{

/* =================    Member types                        ================= */


    public:
        typedef Iter                                                    iterator_type;
        typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;
        typedef typename ft::iterator_traits<Iter>::value_type          value_type;
        typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
        typedef typename ft::iterator_traits<Iter>::pointer             pointer;
        typedef typename ft::iterator_traits<Iter>::reference           reference;

    private:
        iterator_type   _current;


/* =================    Public Member-functions             ================= */

    public:

/* =================    Constructors                        ================= */

        //  Constructs a new iterator adaptor.
        //  (1) Default constructor. The underlying iterator is value-initialized.
        //  Operations on the resulting iterator have defined behavior if and only if
        //  the corresponding operations on a value-initialized Iter also have defined behavior.
        reverse_iterator( void )
        {
            _current = iterator_type();
        }

        //  (2) The underlying iterator is initialized with x.
        explicit reverse_iterator( iterator_type x )
        {
            _current = x;
        }

        //  (3) The underlying iterator is initialized with that of other.
        template< class U >
        reverse_iterator( const reverse_iterator<U>& other )
        {
            *this = other;
        }

        //  destructor is not implemented in STL

        //  The underlying iterator is assigned the value of the underlying
        //  iterator of other, i.e. other.base().
        template< class U >
        reverse_iterator&   operator=( const reverse_iterator<U>& other )
        {
            _current = other.base();
            return (*this);
        }

        operator    reverse_iterator< const iterator_type >( void ) const
        {
            return (_current);
        }

        //  Returns the underlying base iterator. That is ft::reverse_iterator(it).base() == it.
        iterator_type   base( void ) const
        {
            return (_current);
        }

/* =================    Operator overloads                  ================= */

        //  Returns a reference or pointer to the element previous to current.
        //  (1) Equivalent to Iter tmp = current; return *--tmp;
        reference   operator*( void ) const
        {
            iterator_type   tmp = _current;
            --tmp;
            return (*tmp);
        }

        //  (2) Equivalent to return std::addressof(operator*());
        pointer operator->( void ) const
        {
            return (&(operator*()));
        }

        //  Returns a reference to the element at specified relative location.
        reference   operator[]( difference_type n ) const
        {
            iterator_type   tmp = base();
            while (n-- > 0)
                --tmp;
            --tmp;
            return (*tmp);
        }

        //  Increments or decrements the iterator. Inverse operations are
        //  applied to the underlying operator because of the reverse order.
        reverse_iterator&   operator++( void )
        {
            --_current;
            return (*this);
        }

        reverse_iterator&   operator--( void )
        {
            ++_current;
            return (*this);
        }

        reverse_iterator    operator++( int )
        {
            reverse_iterator    tmp(*this);
            --_current;
            return (tmp);
        }

        reverse_iterator operator--( int )
        {
            reverse_iterator    tmp(*this);
            ++_current;
            return (tmp);
        }

        reverse_iterator operator+( difference_type n ) const
        {
            return (reverse_iterator(base() - n));
        }

        reverse_iterator operator-( difference_type n ) const
        {
            return (reverse_iterator(base() + n));
        }

        reverse_iterator& operator+=( difference_type n )
        {
            _current -= n;
            return (*this);
        }

        reverse_iterator& operator-=( difference_type n )
        {
            _current += n;
            return (*this);
        }
};

/* =================    Operations                          ================= */

template < class InputIt, class Distance >
void    advance( InputIt& it, Distance n )
{
    it += n;
}

template< typename It >
bool    operator==( const reverse_iterator< It >& lhs, const reverse_iterator< It >& rhs )
{
    return (lhs.base() == rhs.base());
}

template< typename It1, typename It2 >
bool    operator==( const reverse_iterator< It1 >& lhs, const reverse_iterator< It2 >& rhs )
{
    return (lhs.base() == rhs.base());
}

template< typename It >
bool    operator!=( const reverse_iterator< It >& lhs, const reverse_iterator< It >& rhs )
{
    return (!(lhs == rhs));
}

template< typename It1, typename It2 >
bool    operator!=( const reverse_iterator< It1 >& lhs, const reverse_iterator< It2 >& rhs )
{
    return (!(lhs == rhs));
}

template< typename It >
bool    operator<( const reverse_iterator< It >& lhs, const reverse_iterator< It >& rhs )
{
    return (rhs.base() < lhs.base());
}

template< typename It1, typename It2 >
bool    operator<( const reverse_iterator< It1 >& lhs, const reverse_iterator< It2 >& rhs )
{
    return (rhs.base() < lhs.base());
}

template< typename It >
bool    operator<=( const reverse_iterator< It >& lhs, const reverse_iterator< It >& rhs )
{
    return (!(rhs < lhs));
}

template< typename It1, typename It2 >
bool    operator<=( const reverse_iterator< It1 >& lhs, const reverse_iterator< It2 >& rhs )
{
    return (!(rhs < lhs));
}

template< typename It >
bool    operator>( const reverse_iterator< It >& lhs, const reverse_iterator< It >& rhs )
{
    return (rhs < lhs);
}

template< typename It1, typename It2 >
bool    operator>( const reverse_iterator< It1 >& lhs, const reverse_iterator< It2 >& rhs )
{
    return (rhs < lhs);
}

template< typename It >
bool    operator>=( const reverse_iterator< It >& lhs, const reverse_iterator< It >& rhs )
{
    return (!(lhs < rhs));
}

template< typename It1, typename It2 >
bool    operator>=( const reverse_iterator< It1 >& lhs, const reverse_iterator< It2 >& rhs )
{
    return (!(lhs < rhs));
}

template< typename It >
reverse_iterator< It >  operator+( const typename reverse_iterator< It >::difference_type& i, const reverse_iterator< It >& iter )
{
    return (reverse_iterator< It >(iter.base() - i));
}

template< typename It >
reverse_iterator< It >  operator-( const typename reverse_iterator< It >::difference_type& i, const reverse_iterator< It >& iter )
{
    return (reverse_iterator< It >(iter.base() + i));
}

template< typename It >
typename reverse_iterator< It >::difference_type    operator+( const reverse_iterator< It >& lhs, const reverse_iterator< It >& rhs )
{
    return (lhs.base() + rhs.base());
}

template< typename It >
typename reverse_iterator< It >::difference_type    operator-( const reverse_iterator< It >& lhs, const reverse_iterator< It >& rhs )
{
    return (rhs.base() - lhs.base());
}

template< typename It1, typename It2 >
typename reverse_iterator< It1 >::difference_type   operator+( const reverse_iterator< It1 >& lhs, const reverse_iterator< It2 >& rhs )
{
    return (lhs.base() + rhs.base());
}

template< typename It1, typename It2 >
typename reverse_iterator< It1 >::difference_type   operator-( const reverse_iterator< It1 >& lhs, const reverse_iterator< It2 >& rhs )
{
    return (rhs.base() - lhs.base());
}

} //    namespace ft
