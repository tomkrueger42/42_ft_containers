/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:11:24 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/10/30 00:29:20 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RED_BLACK_TREE_H
# define RED_BLACK_TREE_H

# include <memory>
# include <stdexcept>
# include <iostream>

# include "../vector.hpp"

# include "../iterator/tree_iterator.hpp"
# include "../iterator/reverse_iterator.hpp"

# include "algorithm.hpp"
# include "functional.hpp"
# include "utility.hpp"
# include "type_traits.hpp"
# include "colours.hpp"

namespace ft
{



/* ************************************************************************** */

enum colour_type
{ BLACK, RED, DOUBLE_BLACK };

/* ************************************************************************** */
/*                                   TREE NODE                                */
/* ************************************************************************** */

template<typename T>
struct node
{

    /* MEMBER TYPES */
    typedef T                    value_type;
    typedef node<value_type>     node_type;
    typedef node<value_type>*    node_ptr;

    /* NODE ATTRIBUTES */
    value_type   data;
    colour_type  colour;
    node_ptr     parent;
    node_ptr     left;
    node_ptr     right;

};

/* ************************************************************************** */
/*                                RED BLACK TREE                              */
/* ************************************************************************** */

template<typename T,
         typename Compare,
         typename Alloc>
class red_black_tree
{
public:

    /* MEMBER TYPES :: TREE */
    typedef T                                                               value_type;
    typedef Compare                                                         value_compare;
    typedef Alloc                                                           allocator_type;
    typedef typename allocator_type::size_type                              size_type;
    typedef typename allocator_type::difference_type                        difference_type; 
    typedef typename allocator_type::reference                              reference;
    typedef typename allocator_type::const_reference                        const_reference;
    typedef typename allocator_type::pointer                                pointer;
    typedef typename allocator_type::const_pointer                          const_pointer;

    /* MEMBER TYPES :: NODE */
    typedef typename node<value_type>::node_type                            node_type;
    typedef typename node_type::node_ptr                                    node_ptr;
    typedef typename allocator_type::template rebind<node_type>::other      node_allocator_type;

    /* MEMBER TYPES :: TREE ITERATOR */
    typedef ft::tree_iterator<node_type*, value_type>                       iterator;
    typedef ft::tree_iterator<const node_type*, const value_type>           const_iterator;
    typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                            const_reverse_iterator;

private:

    node_ptr                _root;
    node_ptr                _sentinel;
    size_type               _size;
    value_compare           _comp;
    allocator_type          _alloc;
    node_allocator_type     _node_alloc;

public:

    explicit red_black_tree(const value_compare& comp, const allocator_type& alloc);

    template<typename InputIterator>
    red_black_tree(InputIterator first,
                   InputIterator last,
                   const value_compare& comp,
                   const allocator_type& alloc);

    red_black_tree(const red_black_tree& rhs);
    ~red_black_tree();
    
    red_black_tree& operator=(const red_black_tree& rhs);

    /* ITERATORS */
    iterator                                    begin();
    const_iterator                              begin() const;
    iterator                                    end();
    const_iterator                              end() const;
    reverse_iterator                            rbegin();
    const_reverse_iterator                      rbegin() const;
    reverse_iterator                            rend();
    const_reverse_iterator                      rend() const;

    /* CAPACITY */
    bool                                        empty() const;
    size_type                                   size() const;
    size_type                                   max_size() const;

    /* MODIFIERS */
    ft::pair<iterator, bool>                    insert(const value_type& val);
    iterator                                    insert(iterator position, const value_type& val);
    template<typename InputIterator>
    void                                        insert(InputIterator first, InputIterator last);
    void                                        erase(iterator position);
    size_type                                   erase(const value_type& val);
    void                                        erase(iterator first, iterator last);
    void                                        swap(red_black_tree& other);
    void                                        clear();

    /* OPERATIONS */
    iterator                                    find(const value_type& val);
    const_iterator                              find(const value_type& val) const;
    size_type                                   count(const value_type& val) const;
    iterator                                    lower_bound(const value_type& val);
    const_iterator                              lower_bound(const value_type& val) const;
    iterator                                    upper_bound(const value_type& val);
    const_iterator                              upper_bound(const value_type& val) const;
    ft::pair<iterator, iterator>                equal_range(const value_type& val);
    ft::pair<const_iterator, const_iterator>    equal_range(const value_type& val) const;

    /* ALLOCATOR */
    allocator_type                              get_allocator() const;

    /* UTILITY */
    void                                        print_tree();

private:

    /* MEMORY MANAGEMENT */
    node_ptr                       allocate_node(value_type data, colour_type colour, node_ptr parent);
    void                           deallocate_node(node_ptr node);

    /* INSERT */
    void                           insert_helper(node_ptr node, value_type key, iterator& pos, bool& inserted);
    void                           insert_fix(node_ptr node);

    /* DELETE */
    void                           delete_node(value_type data);
    void                           delete_helper(node_ptr node);
    void                           delete_fix(node_ptr node);
    void                           delete_tree();

    /* TREE BALANCING */
        /* ROTATION AND COLOUR SWAP */
        void                       rotate_node(node_ptr node);
        void                       right_rotate(node_ptr node);
        void                       left_rotate(node_ptr node);
        void                       swap_colour(node_ptr node1, node_ptr node2);

        /* ACCESSOR */
        node_ptr                   minimum(node_ptr node) const;
        node_ptr                   get_node_by_key(value_type key) const;
        node_ptr                   get_inorder_successor(node_ptr node);
        node_ptr                   get_uncle(node_ptr node);
        node_ptr                   get_sibling(node_ptr node);
        node_ptr                   get_near_nephew(node_ptr node, node_ptr sibling);
        node_ptr                   get_far_nephew(node_ptr node, node_ptr sibling);
        int                        get_near_colour(node_ptr nephew);
        int                        get_far_colour(node_ptr nephew);

        /* UTILITY */
        bool                       is_left_node(node_ptr node);
        bool                       is_right_node(node_ptr node);
        bool                       is_sentinel(node_ptr node);
        bool                       is_less(const value_type& value1, const value_type& value2) const;
        bool                       is_greater(const value_type& value1, const value_type& value2) const;
        bool                       is_equal(const value_type& value1, const value_type& value2) const;

    /* RECURSIVE HELPER */
    node_ptr                       copy_helper(node_ptr parent, node_ptr source, node_ptr rhs_sentinel);
    void                           deallocate_all_helper(node_ptr node);
    node_ptr                       search_helper(node_ptr node, value_type key) const;
    ft::pair<iterator, bool>       search_helper(node_ptr node,
                                                 node_ptr parent,
                                                 const value_type& key,
                                                 int direction) const;

    /* PRINT TREE */
    void                           print_helper(node_ptr node);
    std::string                    get_indentation(node_ptr node);
    size_t                         get_node_depth(node_ptr node, size_t depth);

};

/* ************************************************************************** */
/*                                RED BLACK TREE                              */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
red_black_tree<T, Compare, Alloc>::red_black_tree(const value_compare& comp, const allocator_type& alloc)
: _root(NULL), _sentinel(NULL), _size(0), _comp(comp), _alloc(alloc), _node_alloc(alloc)
{
    _sentinel = allocate_node(value_type(), BLACK, NULL);
    _root = _sentinel;
}


template<typename T, typename Compare, typename Alloc>
template<typename InputIterator>
red_black_tree<T, Compare, Alloc>::red_black_tree(InputIterator first,
                                                  InputIterator last,
                                                  const value_compare& comp,
                                                  const allocator_type& alloc)
: _root(NULL), _sentinel(NULL), _size(0), _comp(comp), _alloc(alloc), _node_alloc(alloc)
{
    _sentinel = allocate_node(value_type(), BLACK, NULL);
    _root = _sentinel;
    insert(first, last);
}


template<typename T, typename Compare, typename Alloc>
red_black_tree<T, Compare, Alloc>::red_black_tree(const red_black_tree& rhs)
: _root(NULL), _sentinel(NULL), _size(rhs._size), _comp(rhs._comp), _alloc(rhs._alloc), _node_alloc(rhs._node_alloc)
{ this->_root = copy_helper(NULL, rhs._root, rhs._sentinel); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
red_black_tree<T, Compare, Alloc>::~red_black_tree()
{ deallocate_all_helper(this->_root); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
red_black_tree<T, Compare, Alloc>&
red_black_tree<T, Compare, Alloc>::operator=(const red_black_tree& rhs)
{
    if (this != &rhs)
    {
        deallocate_all_helper(this->_root);
        _sentinel = NULL;
        this->_size = rhs._size;
        this->_comp = rhs._comp;
        this->_alloc = rhs._alloc;
        this->_node_alloc = rhs._node_alloc;
        this->_root = copy_helper(NULL, rhs._root, rhs._sentinel);
    }
    return *this;
}

/* ************************************************************************** */
/*                                   ITERATORS                                */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::iterator
red_black_tree<T, Compare, Alloc>::begin()
{ return iterator(minimum(_root)); }


template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::const_iterator
red_black_tree<T, Compare, Alloc>::begin() const
{ return const_iterator(minimum(_root)); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::iterator
red_black_tree<T, Compare, Alloc>::end()
{ return iterator(_sentinel); }


template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::const_iterator
red_black_tree<T, Compare, Alloc>::end() const
{ return const_iterator(_sentinel); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::reverse_iterator
red_black_tree<T, Compare, Alloc>::rbegin()
{ return reverse_iterator(iterator(_sentinel)); }


template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::const_reverse_iterator
red_black_tree<T, Compare, Alloc>::rbegin() const
{ return const_reverse_iterator(const_iterator(_sentinel)); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::reverse_iterator
red_black_tree<T, Compare, Alloc>::rend()
{ return reverse_iterator(iterator(minimum(_root))); }


template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::const_reverse_iterator
red_black_tree<T, Compare, Alloc>::rend() const
{ return const_reverse_iterator(const_iterator(minimum(_root))); }

/* ************************************************************************** */
/*                                   CAPACITY                                 */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
bool
red_black_tree<T, Compare, Alloc>::empty(void) const
{ return _size == 0; }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::size_type
red_black_tree<T, Compare, Alloc>::size(void) const
{ return _size; }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::size_type
red_black_tree<T, Compare, Alloc>::max_size(void) const
{ return _node_alloc.max_size(); }

/* ************************************************************************** */
/*                                   MODIFIERS                                */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
ft::pair<typename red_black_tree<T, Compare, Alloc>::iterator, bool>
red_black_tree<T, Compare, Alloc>::insert(const value_type& val)
{
    iterator pos;
    bool inserted = false;

    insert_helper(_root, val, pos, inserted);
    return ft::make_pair(pos, inserted);
}


template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::iterator
red_black_tree<T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
    (void)position;

    iterator pos;
    bool inserted = false;

    insert_helper(_root, val, pos, inserted);
    return pos;
}


template<typename T, typename Compare, typename Alloc>
template<typename InputIterator>
void
red_black_tree<T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
    for (; first != last; ++first)
        insert(*first);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::erase(iterator position)
{
    node_ptr node = get_node_by_key(*position);
    if (!node || is_sentinel(node))
        return ;
    delete_helper(node);
}


template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::size_type
red_black_tree<T, Compare, Alloc>::erase(const value_type& val)
{
    node_ptr node = get_node_by_key(val);
    if (!node || is_sentinel(node))
        return 0;
    delete_helper(node);
    return 1;
}


template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::erase(iterator first, iterator last)
{
    ft::vector<value_type> tmp;

    for (; first != last; ++first)
        tmp.push_back(*first);

    while (!tmp.empty())
    {
        erase(tmp.back());
        tmp.pop_back();
    }
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
void
red_black_tree<T, Compare, Alloc>::swap(red_black_tree& other)
{
    ft::swap(this->_root, other._root);
    ft::swap(this->_sentinel, other._sentinel);
    ft::swap(this->_size, other._size);
    ft::swap(this->_comp, other._comp);
    ft::swap(this->_alloc, other._alloc);
    ft::swap(this->_node_alloc, other._node_alloc);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::clear(void)
{ erase(begin(), end()); }

/* ************************************************************************** */
/*                                   OPERATIONS                               */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::iterator
red_black_tree<T, Compare, Alloc>::find(const value_type& val)
{
    ft::pair<iterator, bool> tmp = search_helper(_root, NULL, val, 0);
    if (!tmp.second)
        return iterator(_sentinel);
    return iterator(tmp.first);
}


template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::const_iterator
red_black_tree<T, Compare, Alloc>::find(const value_type& val) const
{
    ft::pair<iterator, bool> tmp = search_helper(_root, NULL, val, 0);
    if (!tmp.second)
        return const_iterator(_sentinel);
    return const_iterator(tmp.first);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::size_type
red_black_tree<T, Compare, Alloc>::count(const value_type& val) const
{
    ft::pair<iterator, bool> tmp = search_helper(_root, NULL, val, 0);
    if (!tmp.second)
        return 0;
    return 1;
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::iterator
red_black_tree<T, Compare, Alloc>::lower_bound(const value_type& val)
{
    ft::pair<iterator, bool> tmp = search_helper(_root, NULL, val, 0);
    return iterator(tmp.first);
}


template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::const_iterator
red_black_tree<T, Compare, Alloc>::lower_bound(const value_type& val) const
{
    ft::pair<iterator, bool> tmp = search_helper(_root, NULL, val, 0);
    return const_iterator(tmp.first);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::iterator
red_black_tree<T, Compare, Alloc>::upper_bound(const value_type& val)
{
    ft::pair<iterator, bool> tmp = search_helper(_root, NULL, val, 0);
    if (!tmp.second)
        return iterator(tmp.first);
    return iterator(++tmp.first);
}


template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::const_iterator
red_black_tree<T, Compare, Alloc>::upper_bound(const value_type& val) const
{
    ft::pair<iterator, bool> tmp = search_helper(_root, NULL, val, 0);
    if (!tmp.second)
        return const_iterator(tmp.first);
    return const_iterator(++tmp.first);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
ft::pair<typename red_black_tree<T, Compare, Alloc>::iterator,
          typename red_black_tree<T, Compare, Alloc>::iterator>
red_black_tree<T, Compare, Alloc>::equal_range(const value_type& val)
{
    iterator first = lower_bound(val);
    iterator last = upper_bound(val);
    return ft::make_pair(first, last);
}


template<typename T, typename Compare, typename Alloc>
ft::pair<typename red_black_tree<T, Compare, Alloc>::const_iterator,
          typename red_black_tree<T, Compare, Alloc>::const_iterator>
red_black_tree<T, Compare, Alloc>::equal_range(const value_type& val) const
{
    const_iterator first = lower_bound(val);
    const_iterator last = upper_bound(val);
    return ft::make_pair(first, last);
}

/* ************************************************************************** */
/*                                   ALLOCATOR                                */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::allocator_type
red_black_tree<T, Compare, Alloc>::get_allocator(void) const
{ return _alloc; }

/* ************************************************************************** */
/*                                    UTILITY                                 */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::print_tree(void)
{
    print_helper(this->_root);
    if (!this->_root)
        std::cout << "Whoops! It seems the tree bears not a single leaf..." << std::endl;
}

/* ************************************************************************** */
/*                            PRIVATE MEMBER FUNCTIONS                        */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                MEMORY MANAGEMENT                           */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::allocate_node(value_type data, colour_type colour, node_ptr parent)
{
    if (_sentinel)
        _size += 1;

    node_ptr node = _node_alloc.allocate(1);
    _alloc.construct(&node->data, data);
    node->colour = colour;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
void
red_black_tree<T, Compare, Alloc>::deallocate_node(node_ptr node)
{
    if (node != _sentinel)
        _size -= 1;

    _alloc.destroy(&node->data);
    _node_alloc.deallocate(node, 1);
}

/* ************************************************************************** */
/*                                     INSERT                                 */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::insert_helper(node_ptr node, value_type key, iterator& pos, bool& inserted)
{
    if (_root == _sentinel)
    {
        _root = allocate_node(key, BLACK, NULL);
        _root->right = _sentinel;
        _sentinel->parent = _root;

        pos = iterator(_root);
        inserted = true;
        return ;
    }
    else if (is_less(key, node->data) && !node->left)
    {
        node->left = allocate_node(key, RED, node);

        pos = iterator(node->left);
        inserted = true;

        insert_fix(node->left);
        return ;
    }
    else if (is_greater(key, node->data) && !node->right)
    {
        if (node == _sentinel)
        {
            node_ptr tmp = allocate_node(key, RED, node->parent);;
            node->parent->right = tmp;
            tmp->parent = node->parent;

            tmp->right = node;
            node->parent = tmp;
            
            pos = iterator(tmp);
            inserted = true;

            insert_fix(tmp);
        }
        else
        {
            node->right = allocate_node(key, RED, node);

            pos = iterator(node->right);
            inserted = true;
        
            insert_fix(node->right);
        }
        return ;
    }
    else if (is_equal(key, node->data))
    {
        pos = iterator(node);
        return ;
    }
    (is_less(key, node->data)) ? insert_helper(node->left, key, pos, inserted) : insert_helper(node->right, key, pos, inserted);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::insert_fix(node_ptr node)
{
    node_ptr parent = node->parent;

    if (parent->colour == BLACK) 
        return ; 
    else if (node->colour == RED && parent->colour == RED)
    {
        node_ptr uncle = get_uncle(node);

        if (!uncle || uncle->colour == BLACK)
            rotate_node(node);
        else if (uncle->colour == RED)
        {
            parent->colour = BLACK;
            uncle->colour = BLACK;
            if (parent->parent != this->_root)
            {
                parent->parent->colour = RED;
                insert_fix(parent->parent);
            }
        }
    }
}

/* ************************************************************************** */
/*                                     DELETE                                 */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::delete_node(value_type key)
{
    node_ptr node;
        
    node = get_node_by_key(key);
    if (!node)
        return ;
    delete_helper(node);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::delete_helper(node_ptr node)
{
    if (!node->left && (!node->right || node->right == _sentinel)) /* 0 CHILDREN */
    {
        node_ptr parent = node->parent;

        if (node == _root)
        {
            deallocate_node(node);
            _sentinel->parent = NULL;
            _root = _sentinel;
            return ;
        }
        else if (node->colour == BLACK)
        {
            node->colour = DOUBLE_BLACK;
            delete_fix(node);
        }
        (is_left_node(node)) ? parent->left = NULL : parent->right = NULL;
        if (node->right == _sentinel)
        {
            parent->right = _sentinel;
            _sentinel->parent = parent;
        }
        deallocate_node(node);
    }
    else if (node->left && node->right && node->right != _sentinel) /* 2 CHILDREN */
    {
        node_ptr successor = get_inorder_successor(node);

        _alloc.destroy(&node->data);
        _alloc.construct(&node->data, successor->data);
        delete_helper(successor);
    }
    else if (node->left || (node->right && node->right != _sentinel)) /* 1 CHILD */
    {
        node_ptr child = (node->left) ? node->left : node->right;

        _alloc.destroy(&node->data);
        _alloc.construct(&node->data, child->data);
        delete_helper(child);
    }
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::delete_fix(node_ptr node)
{
    if (node == this->_root)
    {
        /* CASE 2 */
        node->colour = BLACK;
        return ;
    }

    node_ptr parent = node->parent;
    node_ptr sibling = get_sibling(node);

    if (!sibling)
    {
        /* CASE X */
        parent->colour = (parent->colour == RED) ? BLACK : DOUBLE_BLACK;
        if (parent->colour == DOUBLE_BLACK)
            delete_fix(parent);
    }
    else if (sibling->colour == BLACK)
    {
        if ( (!sibling->left || sibling->left->colour == BLACK) && (!sibling->right || sibling->right->colour == BLACK) )
        {
            /* CASE 3 */
            node->colour = BLACK;
            parent->colour = (parent->colour == RED) ? BLACK : DOUBLE_BLACK;
            sibling->colour = RED;

            if (parent->colour == DOUBLE_BLACK)
                delete_fix(parent);
        }
        else
        {
            node_ptr far_nephew = get_far_nephew(node, sibling);
            node_ptr near_nephew = get_near_nephew(node, sibling);

            if (get_far_colour(far_nephew) == BLACK && get_near_colour(near_nephew) == RED)
            {
                /* CASE 5 */
                swap_colour(sibling, near_nephew);
                (is_left_node(near_nephew)) ? right_rotate(near_nephew) : left_rotate(near_nephew);
                delete_fix(node);
            }
            else if (get_far_colour(far_nephew) == RED && get_near_colour(near_nephew) == BLACK)
            {
                /* CASE 6 */
                swap_colour(parent, sibling);
                (is_left_node(node)) ? left_rotate(sibling) : right_rotate(sibling);
                far_nephew->colour = BLACK;
                node->colour = BLACK;
            }
            else if (get_far_colour(far_nephew) == RED && get_near_colour(near_nephew) == RED)
            {
                /* CASE 7 */
                (is_left_node(node)) ? left_rotate(sibling) : right_rotate(sibling);
                if (parent->colour == BLACK)
                    far_nephew->colour = BLACK;
                else if (parent->colour == RED)
                    insert_fix(near_nephew);
                node->colour = BLACK;
            }
        }
    }
    else if (sibling->colour == RED)
    {
        /* CASE 4 */
        swap_colour(parent, sibling);
        (is_left_node(node)) ? left_rotate(sibling) : right_rotate(sibling);
        delete_fix(node);
    }
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::delete_tree(void)
{
    deallocate_all_helper(this->_root);
    this->_root = NULL;
}

/* ************************************************************************** */
/*                                TREE BALANCING                              */
/* ************************************************************************** */

/* ************************************************************************** */
/*                           ROTATION AND COLOUR SWAP                         */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::rotate_node(node_ptr node)
{
    if (is_right_node(node) && is_right_node(node->parent)) /* LL */
    {
        left_rotate(node->parent);
        node->parent->colour = BLACK;
        node->parent->left->colour = RED;
    }
    else if (is_left_node(node) && is_left_node(node->parent)) /* RR */
    {
        right_rotate(node->parent);
        node->parent->colour = BLACK;
        node->parent->right->colour = RED;
    }
    else if (is_right_node(node) && is_left_node(node->parent)) /* LR */
    {
        left_rotate(node);
        right_rotate(node);
        node->colour = BLACK;
        node->right->colour = RED;
    }
    else if (is_left_node(node) && is_right_node(node->parent)) /* RL */
    {
        right_rotate(node);
        left_rotate(node);
        node->colour = BLACK;
        node->left->colour = RED;
    }
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::right_rotate(node_ptr node)
{
    node_ptr x = node;
    node_ptr y = node->parent;
    node_ptr p = y->parent;
    node_ptr beta = x->right;

    y->left = beta;
    if (beta)
        beta->parent = y;

    if (!p)
    {
        this->_root = x;
        x->parent = NULL;
        x->colour = BLACK;
    }
    else if (p->right == y)
    {
        p->right = x;
        x->parent = p;
    }
    else
    {
        p->left = x;
        x->parent = p;
    }

    x->right = y;
    y->parent = x;
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::left_rotate(node_ptr node)
{
    node_ptr x = node->parent;
    node_ptr y = node;
    node_ptr p = x->parent;
    node_ptr beta = y->left;

    x->right = beta;
    if (beta)
        beta->parent = x;

    if (!p)
    {
        this->_root = y;
        y->parent = NULL;
        y->colour = BLACK;
    }
    else if (x == p->left)
    {
        p->left = y;
        y->parent = p;
    }
    else
    {
        p->right = y;
        y->parent = p;
    }

    y->left = x;
    x->parent = y;
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::swap_colour(node_ptr node1, node_ptr node2)
{
    if (node1 && node2)
    {
        colour_type tmp = node1->colour;
        node1->colour = node2->colour;
        node2->colour = tmp;
    }
    else if (!node1 && !node2)
        return ;
    else
    {
        if (!node1)
            node2->colour = BLACK;
        else if (!node2)
            node1->colour = BLACK;
    }
}

/* ************************************************************************** */
/*                                   ACCESSOR                                 */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::minimum(node_ptr node) const
{
    if (!node->left)
        return (node);
    return minimum(node->left);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::get_node_by_key(value_type key) const
{
    node_ptr node;

    node = search_helper(this->_root, key);
    return (node);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::get_inorder_successor(node_ptr node)
{ return (minimum(node->right)); }

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::get_uncle(node_ptr node)
{
    node_ptr parent = node->parent;
    node_ptr uncle;

    if (!parent->parent)
        return (NULL);

    uncle = (is_left_node(parent) ? parent->parent->right : parent->parent->left);
    return (uncle);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::get_sibling(node_ptr node)
{
    node_ptr parent = node->parent;
    node_ptr sibling;

    if (!parent)
        return (NULL);

    sibling = (is_left_node(node)) ? parent->right : parent->left;
    return (sibling);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::get_near_nephew(node_ptr node, node_ptr sibling)
{
    node_ptr near_nephew = NULL;

    if (!sibling)
        return (NULL);

    if (is_left_node(node))
        near_nephew = sibling->left;
    else if (is_right_node(node))
        near_nephew = sibling->right;

    return (near_nephew);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::get_far_nephew(node_ptr node, node_ptr sibling)
{
    node_ptr far_nephew = NULL;

    if (!sibling)
        return (NULL);

    if (is_left_node(node))
        far_nephew = sibling->right;
    else if (is_right_node(node))
        far_nephew = sibling->left;

    return (far_nephew);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
int
red_black_tree<T, Compare, Alloc>::get_near_colour(node_ptr nephew)
{
    int colour;

    colour = (!nephew || nephew->colour == BLACK) ? BLACK : RED;
    return (colour);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
int
red_black_tree<T, Compare, Alloc>::get_far_colour(node_ptr nephew)
{
    int colour;

    colour = (!nephew || nephew->colour == BLACK) ? BLACK : RED;
    return (colour);
}

/* ************************************************************************** */
/*                                   UTILITY                                  */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
bool
red_black_tree<T, Compare, Alloc>::is_left_node(node_ptr node)
{
    if (node == this->_root)
        return (false);
    return node == node->parent->left;
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
bool
red_black_tree<T, Compare, Alloc>::is_right_node(node_ptr node)
{
    if (node == this->_root)
        return (false);
    return node == node->parent->right;
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
bool
red_black_tree<T, Compare, Alloc>::is_sentinel(node_ptr node)
{ return node == _sentinel; }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
bool
red_black_tree<T, Compare, Alloc>::is_less(const value_type& value1, const value_type& value2) const
{ return this->_comp(value1, value2); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
bool
red_black_tree<T, Compare, Alloc>::is_greater(const value_type& value1, const value_type& value2) const
{ return this->_comp(value2, value1); }

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
inline
bool
red_black_tree<T, Compare, Alloc>::is_equal(const value_type& value1, const value_type& value2) const
{ return !(is_less(value1, value2)) && !(is_less(value2, value1)); }

/* ************************************************************************** */
/*                               RECURSIVE HELPER                             */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::copy_helper(node_ptr parent, node_ptr source, node_ptr rhs_sentinel)
{
    node_ptr node = allocate_node(source->data, source->colour, parent);

    if (source == rhs_sentinel)
        this->_sentinel = node;

    if (source->left)
        node->left = copy_helper(node, source->left, rhs_sentinel);

    if (source->right)
        node->right = copy_helper(node, source->right, rhs_sentinel);

    return node;
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::deallocate_all_helper(node_ptr node)
{
    if (!node)
        return ;
    deallocate_all_helper(node->left);
    node_ptr tmp = node;
    deallocate_all_helper(node->right);
    deallocate_node(tmp);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
typename red_black_tree<T, Compare, Alloc>::node_ptr
red_black_tree<T, Compare, Alloc>::search_helper(node_ptr node, value_type key) const
{
    if (!node || node == _sentinel || is_equal(node->data, key))
        return (node);

    if (is_less(key, node->data))
        return (search_helper(node->left, key));

    return (search_helper(node->right, key));
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
ft::pair<typename red_black_tree<T, Compare, Alloc>::iterator, bool>
red_black_tree<T, Compare, Alloc>::search_helper(node_ptr node,
                                                 node_ptr parent,
                                                 const value_type& key,
                                                 int direction) const
{
    if (!node)
    {
        if (direction == 1)
            return (ft::make_pair(iterator(parent), false));
        else if (direction == 2)
            return (ft::make_pair(++iterator(parent), false));
    }
    else if (node == _sentinel)
        return (ft::make_pair(iterator(_sentinel), false));
    else if (is_equal(node->data, key))
        return (ft::make_pair(iterator(node), true));
    
        
    if (is_less(key, node->data))
        return (search_helper(node->left, node, key, 1));
        
    return (search_helper(node->right, node, key, 2));
}

/* ************************************************************************** */
/*                                  PRINT TREE                                */
/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
void
red_black_tree<T, Compare, Alloc>::print_helper(node_ptr node)
{
    std::string indent;

    if (!node)
        return ;

    print_helper(node->right);

    // if (node == this->_root)
    //     std::cout << "ROOT\t <- \t";
    // else
    //     std::cout << "P : " << node->parent->data << "\t <- \t";

    std::cout << "\t";

    indent = get_indentation(node);

    std::cout << indent;
    if (node->colour == RED)
        std::cout << PRINT_RED << node->data << PRINT_END << std::endl;
    else
    {
        if (node != _sentinel)
            std::cout << PRINT_BLACK << node->data;
        else
            std::cout << PRINT_ORANGE << "{✿";
        std::cout << PRINT_END << std::endl;
    }

    print_helper(node->left);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
std::string
red_black_tree<T, Compare, Alloc>::get_indentation(node_ptr node)
{
    std::string indent = "";
    size_t depth = get_node_depth(node, 0);

    if (depth > 1)
    {
        if ( (is_right_node(node->parent) && is_left_node(node)) || (is_left_node(node->parent) && is_right_node(node)) )
        {
            for (size_t i = 2; i < depth; i++)
                indent += "  ";
            indent += "│";
        }
        else
        {
            for (size_t i = 2; i < depth; i++)
                indent += "  ";
        }
        indent += "  ";
    }

    if (is_left_node(node))
        indent += "└";
    else if (is_right_node(node))
        indent += "┌";
        
    if (node != this->_root)
        indent += "──";

    return (indent);
}

/* ************************************************************************** */

template<typename T, typename Compare, typename Alloc>
size_t
red_black_tree<T, Compare, Alloc>::get_node_depth(node_ptr node, size_t depth)
{
    if (node == this->_root)
        return (depth);
    depth = get_node_depth(node->parent, depth + 1);
    return (depth);
}

/* ************************************************************************** */
/*                                RED BLACK TREE                              */
/* ************************************************************************** */

}

#endif /* RED_BLACK_TREE_H */
