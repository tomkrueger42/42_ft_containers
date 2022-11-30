#pragma once

#include <memory>
#include "red_black_tree_node.hpp"
#include "red_black_tree_iterator.hpp"
#include "utility.hpp"

namespace ft {

template< 
    class Value,
    class Compare,
    class Allocator = std::allocator< Value >
> class red_black_tree
{

public:

/* =================    Member types                        ================= */

    typedef Value                                                               value_type;
    typedef Allocator                                                           value_allocator_type;
    typedef typename value_allocator_type::difference_type                      difference_type;

    typedef Compare                                                             value_compare;

    typedef typename red_black_tree_node< value_type >::node_type               node_type;
    typedef typename node_type::pointer                                         node_pointer;
    typedef typename value_allocator_type::template rebind<node_type>::other    node_allocator_type;
    typedef typename node_allocator_type::size_type                             size_type;

    typedef ft::red_black_tree_iterator< value_type >             iterator;
    typedef ft::const_red_black_tree_iterator< value_type >       const_iterator;


private:

/* =================    Member objects                      ================= */

    value_allocator_type    _value_alloc;
    node_allocator_type     _node_alloc;
    value_compare           _compare;
    size_type               _size;
    node_pointer            _root;
    node_pointer            _endNode;
    node_pointer            _beginNode;


public:

/* =================    Member classes                      ================= */


    red_black_tree( void ) : _root(NULL)
    {
        _endNode = _new_node(value_type(), NULL, BLACK);
        _beginNode = _endNode;
        _root = _endNode;
        _size = 0;
    }

    ~red_black_tree( void )
    {
        clear();
        _delete_node(_endNode);
    }

    red_black_tree& operator=( const red_black_tree& other )
    {
        if (this != &other)
        {
            clear();
            _delete_node(_endNode);
            _compare = other._compare;
            _node_alloc = other._node_alloc;
            _value_alloc = other._value_alloc;
            _root = _copy_tree(other._root, NULL);
            _size = other._size;
            _set_iterator_pointers();
        }
        return (*this);
    }


/* =================    Iterators                           ================= */

    iterator    begin( void )
    {
        return (iterator(_beginNode));
    }

    const_iterator  begin( void ) const
    {
        return (const_iterator(_beginNode));
    }

    iterator    end( void )
    {
        return (iterator(_endNode));
    }

    const_iterator  end( void ) const
    {
        return (const_iterator(_endNode));
    }


/* =================    Capacity                            ================= */

    size_type   size( void ) const
    {
        return (_size);
    }

    size_type   max_size( void ) const
    {
        return (_node_alloc.max_size());
    }


/* =================    Modifiers                           ================= */

    void    clear( void )
    {
        _clear_helper(_root);
        _root = _endNode;
        _beginNode = _endNode;
        _endNode->parent = NULL;
    }

    ft::pair<iterator, bool>    insert( const value_type& value, node_pointer pos )
    {
        if (pos == NULL)
            pos = _root;
        if (pos == _endNode)
        {
            _root = _new_node(value, NULL, BLACK);
            _root->right = _endNode;
            _endNode->parent = _root;
            _beginNode = _root;
            return (ft::make_pair(iterator(_root), true));
        }
        while (pos != NULL)
        {
            if (_compare(value, pos->value) && pos->left != NULL)
                pos = pos->left;
            else if (_compare(pos->value, value) && pos->right != NULL && pos->right != _endNode)
                pos = pos->right;
            else
                break ;
        }
        if (_compare(value, pos->value))                                   //  value is inserted left of n
        {
            node_pointer newNode = _new_node(value, pos, RED);
            pos->left = newNode;
            if (pos == _beginNode)                                              //  begin iterator is invalidated
                _beginNode = newNode;
            _insert_rb_violation(newNode);                                      //  pos->right or pos->left??
            return (ft::make_pair(iterator(newNode), true));
        }
        else if (_compare(pos->value, value))                              //  value is inserted right of n
        {
            node_pointer newNode = _new_node(value, pos, RED);
            if (pos->right == _endNode)                                         //  value is largest in tree: end iterator is invalidated
            {
                pos->right = newNode;
                pos->right->right = _endNode;
                _endNode->parent = pos->right;
            }
            else
                pos->right = newNode;
            _insert_rb_violation(newNode);
            return (ft::make_pair(iterator(newNode), true));
        }
        return (ft::make_pair(iterator(pos), false));
    }

    void    erase( const_iterator pos )
    {
        node_pointer    n = const_cast< node_pointer >(pos.base());
        COLOR           originalColor = n->color;
        node_pointer    x;

        if (n->left == NULL)                                                    //  node has no left child
        {
            x = n->right;
            if (n == _beginNode && n->right != NULL)                            //  invalidating begin() iterator
                _beginNode = n->right;
            else if (n == _beginNode)
                _beginNode = n->parent;
            _transplant_node(n, x);
        }
        else if (n->right == NULL || n->right == _endNode)                      //  node has no right child (not counting _endNode)
        {
            x = n->left;
            _transplant_node(n, x);
            if (n->right == _endNode)                                           //  reassigning _endNode relations
            {
                _endNode->parent = x;
                x->right = _endNode;
            }
        }
        else                                                                    //  node has two children
        {
            node_pointer    successor = n->right;                               //  next after node
            while (successor != NULL && successor->left != NULL)
                successor = successor->left;
            originalColor = successor->color;
            x = successor->right;
            if (successor->parent == n && x != NULL)
            {
                x->parent = successor;
            }
            else
            {
                _transplant_node(successor, successor->right);
                successor->right = n->right;
                if (successor->right != NULL)
                    successor->right->parent = successor;
            }
            _transplant_node(n, successor);
            successor->left = n->left;
            successor->left->parent = successor;
            successor->color = n->color;
        }
        _delete_node(n);
        if (originalColor == BLACK)
            _erase_rb_violation(x);
        _set_iterator_pointers();
    }


/* =================    Lookup                              ================= */

    iterator    lower_bound( const value_type& value )
    {
        node_pointer result = _endNode;
        node_pointer node = _root;
        while (node != NULL)
        {
            if (!_compare(node->value, value))
            {
                result = node;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return (iterator(result));
    }

    const_iterator  lower_bound( const value_type& value ) const
    {
        node_pointer result = _endNode;
        node_pointer node = _root;
        while (node != NULL)
        {
            if (!_compare(node->value, value))
            {
                result = node;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return (const_iterator(result));
    }

    iterator    upper_bound( const value_type& value )
    {
        node_pointer result = _endNode;
        node_pointer node = _root;
        while (node != NULL)
        {
            if (_compare(value, node->value))
            {
                result = node;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return (iterator(result));
    }

    const_iterator  upper_bound( const value_type& value ) const
    {
        node_pointer result = _endNode;
        node_pointer node = _root;
        while (node != NULL)
        {
            if (_compare(value, node->value))
            {
                result = node;
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return (const_iterator(result));
    }

    node_pointer    search( value_type value, node_pointer n ) const
    {
        if (n == NULL)
            n = _root;
        while (n != NULL)
        {
            if (_compare(value, n->value))
                n = n->left;
            else if (_compare(n->value, value))
                n = n->right;
            else
                return (n);
        }
        return (_endNode);
    }

    node_pointer    get_root( void ) const
    {
        return (_root);
    }

    void    swap( red_black_tree& other )
    {
        ft::swap(_value_alloc, other._value_alloc);
        ft::swap(_node_alloc, other._node_alloc);
        ft::swap(_compare, other._compare);
        ft::swap(_size, other._size);
        ft::swap(_root, other._root);
        ft::swap(_endNode, other._endNode);
        ft::swap(_beginNode, other._beginNode);
    }


/* =================    private Member-functions            ================= */

private:

    node_pointer    _new_node( value_type value, node_pointer parent, COLOR c )
    {
        if (_endNode != NULL)
            ++_size;
        node_pointer    n = _node_alloc.allocate(1);
        n->parent = parent;
        n->left = NULL;
        n->right = NULL;
        n->color = c;
        _value_alloc.construct(&n->value, value);
        return (n);
    }

    void    _delete_node( node_pointer& n )
    {
        if (n != _endNode)
            --_size;
        _value_alloc.destroy(&n->value);
        _node_alloc.deallocate(n, 1);
        n = NULL;
    }

    node_pointer    _copy_tree( node_pointer n, node_pointer parent )
    {
        if (n == NULL)
            return (NULL);
        node_pointer newNode = _new_node(n->value, parent, n->color);
        newNode->left = _copy_tree(n->left, newNode);
        _endNode = newNode;                                                     // sets the new end_iterator. should be done differently cause it's not self explainatory ;)
        newNode->right = _copy_tree(n->right, newNode);
        return (newNode);
    }

    void    _set_iterator_pointers( void )
    {
        _beginNode = _root;
        while (_beginNode != NULL && _beginNode->left != NULL)
            _beginNode = _beginNode->left;
        _endNode = _root;
        while (_endNode != NULL && _endNode->right != NULL)
            _endNode = _endNode->right;
    }

    void    _clear_helper( node_pointer n )
    {
        if (n == NULL || n == _endNode)
            return ;
        _clear_helper(n->left);
        _clear_helper(n->right);
        _delete_node(n);
    }

    void    _transplant_node( node_pointer o, node_pointer n )
    {
        if (o->parent == NULL)
            _root = n;
        else if (o == o->parent->left)
            o->parent->left = n;
        else
            o->parent->right = n;
        if (_beginNode == o)
            _beginNode = n;
        if (n != NULL)
            n->parent = o->parent;
    }

    void    _left_rotate( node_pointer o )
    {
        node_pointer    n = o->right;
        n->parent = o->parent;
        if (o->parent == NULL)
            _root = n;
        else if (o->parent->left == o)
            o->parent->left = n;
        else
            o->parent->right = n;
        o->right = n->left;
        if (o->right != NULL)
            o->right->parent = o;
        n->left = o;
        o->parent = n;
    }

    void    _right_rotate( node_pointer o )
    {
        node_pointer    n = o->left;
        n->parent = o->parent;
        if (o->parent == NULL)
            _root = n;
        else if (o->parent->right == o)
            o->parent->right = n;
        else
            o->parent->left = n;
        o->left = n->right;
        if (o->left != NULL)
            o->left->parent = o;
        n->right = o;
        o->parent = n;
    }

    void    _insert_rb_violation( node_pointer n )
    {
        while (n != NULL && n->parent != NULL && n->parent->parent != NULL
                && n != _root && n->parent->color == RED)
        {
            if (n->parent->parent->right == n->parent)
            {
                if (n->parent->parent->left != NULL && n->parent->parent->left->color == RED)
                {
                    n->parent->parent->left->color = BLACK;
                    n->parent->color = BLACK;
                    n->parent->parent->color = RED;
                    n = n->parent->parent;
                }
                else
                {
                    if (n->parent->left == n)
                    {
                        n = n->parent;
                        _right_rotate(n);
                    }
                    n->parent->color = BLACK;
                    n->parent->parent->color = RED;
                    _left_rotate(n->parent->parent);
                }
            }
            else
            {
                if (n->parent->parent->right != NULL && n->parent->parent->right->color == RED)
                {
                    n->parent->parent->right->color = BLACK;
                    n->parent->color = BLACK;
                    n->parent->parent->color = RED;
                    n = n->parent->parent;
                }
                else 
                {
                    if (n->parent->right == n)
                    {
                        n = n->parent;
                        _left_rotate(n);
                    }
                    n->parent->color = BLACK;
                    n->parent->parent->color = RED;
                    _right_rotate(n->parent->parent);
                }
            }
        }
        _root->color = BLACK;
    }

    #define _IS_LEFT_CHILD( n ) (n != NULL && n->parent != NULL && n == n->parent->left) ? true : false

    void    _erase_rb_violation( node_pointer n )
    {
        if (n == _root || n == NULL)
            return;
    
        node_pointer    parent = n->parent;
        node_pointer    sibling = parent->left;
        if (_IS_LEFT_CHILD(n))
            sibling = parent->right;

        if (sibling == NULL)                                                    //  No sibiling, double black pushed up
        {
            _erase_rb_violation(parent);
        }
        else
        {
            if (sibling->color == RED)
            {
                parent->color = RED;
                sibling->color = BLACK;
                if (_IS_LEFT_CHILD(sibling))
                    _right_rotate(parent);
                else
                    _left_rotate(parent);
                _erase_rb_violation(n);
            }
            else                                                                //  Sibling has color black
            {
                if ((sibling->left != NULL && sibling->left->color == RED)
                    || (sibling->right != NULL && sibling->right->color == RED))    //  node has at least one red child
                {
                    if (sibling->left != NULL && sibling->left->color == RED) {
                        if (_IS_LEFT_CHILD(sibling))
                        {
                            sibling->left->color = sibling->color;
                            sibling->color = parent->color;
                            _right_rotate(parent);
                        }
                        else
                        {
                            sibling->left->color = parent->color;
                            _right_rotate(sibling);
                            _left_rotate(parent);
                        }
                    }
                    else
                    {
                        if (_IS_LEFT_CHILD(sibling))
                        {
                            sibling->right->color = parent->color;
                            _left_rotate(sibling);
                            _right_rotate(parent);
                        }
                        else
                        {
                            sibling->right->color = sibling->color;
                            sibling->color = parent->color;
                            _left_rotate(parent);
                        }
                    }
                    parent->color = BLACK;
                }
                else                                                            //  node has two black children
                {
                    sibling->color = RED;
                    if (parent->color == BLACK)
                        _erase_rb_violation(parent);
                    else
                        parent->color = BLACK;
                }
            }
        }
    }
}; //   class red_black_tree
} //    namespace ft
