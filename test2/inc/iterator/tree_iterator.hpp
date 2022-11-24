/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:29:50 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/11/21 23:11:02 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{



/* ************************************************************************** */
/*                                 TREE ITERATOR                              */
/* ************************************************************************** */

template<typename NodePtr, typename T>
class tree_iterator
{
public:

    /* MEMBER TYPES */
    typedef NodePtr                                              node_ptr;
    typedef T                                                    value_type;
    typedef T*                                                   pointer;
    typedef T&                                                   reference;
    typedef std::ptrdiff_t                                       difference_type;
    typedef ft::bidirectional_iterator_tag                       iterator_category;

protected:

    /* MEMBER ATTRIBUTES */
    node_ptr _node;

public:

    tree_iterator(const node_ptr& node = NULL);
    template<typename NodePtr2, typename T2>
    tree_iterator(const tree_iterator<NodePtr2, T2>& rhs);
    ~tree_iterator();

    template<typename NodePtr2, typename T2>
    tree_iterator& operator=(const tree_iterator<NodePtr2, T2>& rhs);

    /* ELEMENT ACCESS */
    reference                           operator*();
    reference                           operator*() const;
    pointer                             operator->();
    pointer                             operator->() const;

    /* PREFIX */
    tree_iterator&                      operator++();
    tree_iterator&                      operator--();

    /* POSTFIX */
    tree_iterator                       operator++(int);
    tree_iterator                       operator--(int);

    /* ACCESSOR */
    node_ptr base() const;

    /* CONSTANT CAST OVERLOAD */
    operator tree_iterator<const NodePtr, const T>() const;

};

/* ************************************************************************** */
/*                                 TREE ITERATOR                              */
/* ************************************************************************** */

template<typename NodePtr, typename T>
tree_iterator<NodePtr, T>::tree_iterator(const node_ptr& node)
: _node(node) {}


template<typename NodePtr, typename T>
template<typename NodePtr2, typename T2>
tree_iterator<NodePtr, T>::tree_iterator(const tree_iterator<NodePtr2, T2>& rhs)
: _node(rhs.base()) {}

/* ************************************************************************** */

template<typename NodePtr, typename T>
tree_iterator<NodePtr, T>::~tree_iterator() {}

/* ************************************************************************** */

template<typename NodePtr, typename T>
template<typename NodePtr2, typename T2>
tree_iterator<NodePtr, T>&
tree_iterator<NodePtr, T>::operator=(const tree_iterator<NodePtr2, T2>& rhs)
{
    this->_node = rhs.base();
    return *this;
}

/* ************************************************************************** */
/*                                 ELEMENT ACCESS                             */
/* ************************************************************************** */

template<typename NodePtr, typename T>
inline
typename tree_iterator<NodePtr, T>::reference
tree_iterator<NodePtr, T>::operator*()
{ return _node->data; }


template<typename NodePtr, typename T>
inline
typename tree_iterator<NodePtr, T>::reference
tree_iterator<NodePtr, T>::operator*() const
{ return _node->data; }

/* ************************************************************************** */

template<typename NodePtr, typename T>
inline
typename tree_iterator<NodePtr, T>::pointer
tree_iterator<NodePtr, T>::operator->()
{ return &(_node->data); }


template<typename NodePtr, typename T>
inline
typename tree_iterator<NodePtr, T>::pointer
tree_iterator<NodePtr, T>::operator->() const
{ return &(_node->data); }

/* ************************************************************************** */
/*                                   PREFIX                                   */
/* ************************************************************************** */

template<typename NodePtr, typename T>
tree_iterator<NodePtr, T>&
tree_iterator<NodePtr, T>::operator++()
{
    if (_node->right)
    {
        _node = _node->right;
        while (_node->left)
            _node = _node->left;
    }
    else
    {
        node_ptr parent = _node->parent;
        
        while (parent && _node == parent->right)
        {
            _node = parent;
            parent = parent->parent;
        }
        _node = parent;
    }
    return *this;
}


template<typename NodePtr, typename T>
tree_iterator<NodePtr, T>&
tree_iterator<NodePtr, T>::operator--()
{
    if (_node->left)
    {
        _node = _node->left;
        while (_node->right)
            _node = _node->right;
    }
    else
    {
        node_ptr parent = _node->parent;

        while (parent && _node == parent->left)
        {
            _node = parent;
            parent = parent->parent;
        }
        _node = parent;
    }
    return *this;
}

/* ************************************************************************** */
/*                                  POSTFIX                                   */
/* ************************************************************************** */

template<typename NodePtr, typename T>
tree_iterator<NodePtr, T>
tree_iterator<NodePtr, T>::operator++(int)
{
    tree_iterator it(*this);
    ++(*this);
    return it;
}


template<typename NodePtr, typename T>
tree_iterator<NodePtr, T>
tree_iterator<NodePtr, T>::operator--(int)
{
    tree_iterator it(*this);
    --(*this);
    return it;
}

/* ************************************************************************** */
/*                                   ACCESSOR                                 */
/* ************************************************************************** */

template<typename NodePtr, typename T>
inline
typename tree_iterator<NodePtr, T>::node_ptr
tree_iterator<NodePtr, T>::base() const
{ return _node; };

/* ************************************************************************** */
/*                             CONSTANT CAST OVERLOAD                         */
/* ************************************************************************** */

template<typename NodePtr, typename T>
inline
tree_iterator<NodePtr, T>::operator tree_iterator<const NodePtr, const T>() const
{ return _node; }

/* ************************************************************************** */
/*                                 TREE ITERATOR                              */
/* ************************************************************************** */






/* ************************************************************************** */
/*                               NON-MEMBER FUNCTIONS                         */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               RELATIONAL OPERATORS                         */
/* ************************************************************************** */

template<typename NodePtr, typename T>
inline
bool
operator==(const tree_iterator<NodePtr, T>& lhs, const tree_iterator<NodePtr, T>& rhs)
{ return lhs.base() == rhs.base(); }


template<typename NodePtr1, typename T1, typename NodePtr2, typename T2>
inline
bool
operator==(const tree_iterator<NodePtr1, T1>& lhs, const tree_iterator<NodePtr2, T2>& rhs)
{ return lhs.base() == rhs.base(); }

/* ************************************************************************** */

template<typename NodePtr, typename T>
inline
bool
operator!=(const tree_iterator<NodePtr, T>& lhs, const tree_iterator<NodePtr, T>& rhs)
{ return lhs.base() != rhs.base(); }


template<typename NodePtr1, typename T1, typename NodePtr2, typename T2>
inline
bool
operator!=(const tree_iterator<NodePtr1, T1>& lhs, const tree_iterator<NodePtr2, T2>& rhs)
{ return lhs.base() != rhs.base(); }

/* ************************************************************************** */



}

#endif /* TREE_ITERATOR_HPP */
