#pragma once

#include "../utils/red_black_tree_node.hpp"

#include "iterator.hpp"

namespace ft {

template < class NodePtr >
NodePtr red_black_tree_min(NodePtr node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

template < class NodePtr >
NodePtr red_black_tree_max(NodePtr node)
{
    while (node->right != NULL)
        node = node->right;
    return node;
}

template < class NodePtr >
NodePtr red_black_tree_prev(NodePtr x)
{
    if (x->left != NULL)
        return red_black_tree_max(x->left);
    while (x == x->parent->left)
        x = x->parent;
    return x->parent;
}

template < class NodePtr >
NodePtr red_black_tree_next(NodePtr x)
{
    if (x->right != NULL)
        return red_black_tree_min(x->right);
    while (x == x->parent->right)
        x = x->parent;
    return x->parent;
}

template < class T_value >
class const_red_black_tree_iterator;

template <
    class T_value
> class red_black_tree_iterator
{
   public:
/* =================    Member types                        ================= */

    typedef T_value                                     value_type;
    typedef value_type&                                 reference;
    typedef value_type*                                 pointer;
    typedef std::ptrdiff_t                              difference_type;
    typedef ft::bidirectional_iterator_tag              iterator_category;

   private:
    typedef typename red_black_tree_node< T_value >::pointer         node_pointer;
    typedef typename red_black_tree_node< T_value >::const_pointer   const_node_pointer;
    typedef red_black_tree_iterator                                  iterator;
    typedef const_red_black_tree_iterator< T_value >                 const_iterator;

/* =================    Member objects                      ================= */

    node_pointer    _current;
    
   public:
/* =================    Constructors / Destructor           ================= */

    red_black_tree_iterator( const node_pointer& ptr = NULL ) : _current(ptr) {}

    red_black_tree_iterator( const iterator& rhs ) : _current(rhs.base()) {}

    ~red_black_tree_iterator( void ) {}
    
/* =================    Accessors                           ================= */

    node_pointer    base( void ) const
    {
        return (_current);
    }
    
/* =================    Operator overloads                  ================= */

    reference   operator*( void )
    {
        return (_current->value);
    }

    reference   operator*( void ) const
    {
        return (_current->value);
    }

    pointer operator->( void )
    {
        return (&(_current->value));
    }

    pointer operator->( void ) const
    {
        return (&(_current->value));
    }

    iterator &operator++( void )
    {
        _current = red_black_tree_next< node_pointer >(_current);
        return (*this);
    }

    iterator operator++( int )
    {
        iterator tmp(_current);
        ++*this;
        return (tmp);
    }

    iterator &operator--( void )
    {
        _current = red_black_tree_prev< node_pointer >(_current);
        return (*this);
    }

    iterator operator--( int )
    {
        iterator tmp(_current);
        --(*this);
        return (tmp);
    }

    bool    operator==( const iterator& other ) const
    {
        return (_current == other._current);
    }

    bool    operator==( const const_iterator& other ) const
    {
        return (_current == other.base());
    }

    bool    operator!=( const iterator& other ) const
    {
        return (!(*this == other));
    }

    bool    operator!=( const const_iterator& other ) const
    {
        return (!(*this == other));
    }
};

template <
    class T_value
> class const_red_black_tree_iterator
{
   public:
/* =================    Member types                        ================= */
    typedef const T_value                               value_type;
    typedef value_type&                                 reference;
    typedef value_type*                                 pointer;
    typedef std::ptrdiff_t                              difference_type;
    typedef ft::bidirectional_iterator_tag              iterator_category;

   private:
    typedef typename red_black_tree_node< T_value >::pointer        node_pointer;
    typedef typename red_black_tree_node< T_value >::const_pointer  const_node_pointer;
    typedef red_black_tree_iterator< T_value >                      iterator;
    typedef const_red_black_tree_iterator                           const_iterator;

/* =================    Member objects                      ================= */

    const_node_pointer    _current;

   public:
/* =================    Constructors / Destructor           ================= */

    const_red_black_tree_iterator( const const_node_pointer& ptr = NULL )
                                    : _current(ptr) {}

    const_red_black_tree_iterator( const const_iterator& other )
                                    : _current(other.base()) {}

    const_red_black_tree_iterator( const iterator& other )
                                    : _current(other.base()) {}

    ~const_red_black_tree_iterator( void ) {}

/* =================    Accessors                           ================= */

    const_node_pointer    base( void ) const
    {
        return (_current);
    }

/* =================    Operator overloads                  ================= */

    reference   operator*( void )
    {
        return (_current->value);
    }

    reference   operator*( void ) const
    {
        return (_current->value);
    }

    pointer operator->( void )
    {
        return (&(_current->value));
    }

    pointer operator->( void ) const
    {
        return (&(_current->value));
    }

    const_iterator &operator++( void )
    {
        _current = red_black_tree_next< const_node_pointer >(_current);
        return (*this);
    }

    const_iterator operator++( int )
    {
        const_iterator tmp(_current);
        ++*this;
        return (tmp);
    }

    const_iterator &operator--( void )
    {
        _current = red_black_tree_prev< const_node_pointer >(_current);
        return (*this);
    }

    const_iterator operator--( int )
    {
        const_iterator tmp(_current);
        --(*this);
        return (tmp);
    }

    bool    operator==( const const_iterator& other ) const
    {
        return (_current == other._current);
    }

    bool    operator==( const iterator& other ) const
    {
        return (_current == other.base());
    }

    bool    operator!=( const const_iterator& other ) const
    {
        return (!(*this == other));
    }

    bool    operator!=( const iterator& other ) const
    {
        return (!(*this == other));
    }
};

} // namespace ft
