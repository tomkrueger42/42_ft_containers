#pragma once

#include <memory>
#include "red_black_tree_node.hpp"
#include "red_black_tree_iterator.hpp"
#include "utility.hpp"

namespace ft {

	template< 
		class Key,
		class T,
		class Compare
	> class red_black_tree
	{

		public:

/* =================	Member types						================= */

			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair< const Key, T >								value_type;
			typedef std::allocator< value_type >							value_allocator_type;
			typedef std::allocator< ft::red_black_tree_node< value_type > >	node_allocator_type;
			typedef typename node_allocator_type::size_type					size_type;
			typedef Compare													value_compare;

			typedef red_black_tree_node<value_type>							node;
			typedef	typename node_allocator_type::reference					node_reference;
			typedef	typename node_allocator_type::const_reference			node_const_reference;
			typedef	typename node_allocator_type::pointer					node_pointer;
			typedef	typename node_allocator_type::const_pointer				node_const_pointer;

			typedef typename ft::red_black_tree_iterator<node, value_type, node>					iterator;		//	"node, value_type, node"??
			typedef typename ft::red_black_tree_iterator<const node, const value_type, const node>	const_iterator;
			// typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;


		private:

/* =================	Member objects						================= */

			value_allocator_type	_value_alloc;
			node_allocator_type		_node_alloc;
			value_compare			_comp;
			size_type				_size;
			node_pointer			_root;
			node_pointer			_delimitingNode;


		public:

/* =================	Member classes						================= */

			red_black_tree( void )
			{
				_comp = value_compare();
				_value_alloc = value_allocator_type();
				_root = NULL;
				_delimitingNode = _new_node(value_type(), NULL);
				_delimitingNode->left = _delimitingNode;
				_node_alloc = node_allocator_type();
				_size = 0;
			}

			red_black_tree( value_compare comp, value_allocator_type value_allocator = value_allocator_type())
			{
				_comp = comp;
				_value_alloc = value_allocator;
				_root = NULL;
				_delimitingNode = _new_node(value_type(), NULL);
				_delimitingNode->left = _delimitingNode;
				_node_alloc = node_allocator_type();
				_size = 0;
			}

			red_black_tree( const red_black_tree& other ) : _value_alloc(other._value_alloc), _comp(other._comp), _root(NULL), _delimitingNode(_new_node(value_type(), NULL))
			{
				_size = 0;
				*this = other;
			}

			~red_black_tree( void )
			{
				clear();
				_delete_node(_delimitingNode);
			}

			red_black_tree&	operator=( const red_black_tree& other )
			{
				if (this != &other)
				{
					clear();
					_node_alloc = other._node_alloc;
					_value_alloc = other._value_alloc;
					_comp = other._comp;
					for (const_iterator it = other.begin(); it != other.end(); it++)
						insert(*it, NULL);
				}
				return (*this);
			}

			value_allocator_type	get_allocator( void ) const
			{
				return (_value_alloc);
			}


/* =================	Iterators							================= */

			iterator	begin( void )
			{
				return (iterator(_delimitingNode->left));
			}

			const_iterator	begin( void ) const
			{
				return (const_iterator(_delimitingNode->left));
			}

			iterator	end( void )
			{
				return (iterator(_delimitingNode));
			}

			const_iterator	end( void ) const
			{
				return (const_iterator(_delimitingNode));
			}


/* =================	Capacity							================= */

			size_type	size( void ) const
			{
				return (_size);
			}

			size_type	max_size( void ) const
			{
				return (_node_alloc.max_size());
			}


/* =================	Modifiers							================= */

			void	clear( void )
			{
				_clear_helper(_root);
				_root = NULL;
				_delimitingNode->left = NULL;
				_delimitingNode->parent = NULL;
			}

			//	Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
			//	(1) Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
			ft::pair<iterator, bool>	insert( const value_type& value, node_pointer pos )
			{
				if (_root != NULL)
					pos = _root;
				if (pos == NULL)
				{
					_root = _new_node(value, NULL);
					_root->color = BLACK;
					_root->right = _delimitingNode;
					_delimitingNode->parent = _root;
					_delimitingNode->left = _root;
					return (ft::make_pair(iterator(_root), true));
				}
				while (pos != NULL)
				{
					if (value.first < pos->value_pair.first && pos->left != NULL)
						pos = pos->left;
					else if (value.first > pos->value_pair.first && pos->right != NULL && pos->right != _delimitingNode)
						pos = pos->right;
					else
						break ;
				}
				if (value.first < pos->value_pair.first)
				{
					pos->left = _new_node(value, pos);
					if (pos == _delimitingNode->left)								//	begin iterator is invalidated
						_delimitingNode->left = pos->left;
					_insert_rb_violation(pos->right);
					return (ft::make_pair(iterator(pos->left), true));
				}
				else if (value.first > pos->value_pair.first)						//	value is inserted right of n
				{
					if (pos->right == _delimitingNode)								//	value is largest in tree: end iterator is invalidated
					{
						pos->right = _new_node(value, pos);
						pos->right->right = _delimitingNode;
						_delimitingNode->parent = pos->right;
					}
					else
						pos->right = _new_node(value, pos);
					_insert_rb_violation(pos->right);
					return (ft::make_pair(iterator(pos->right), true));
				}
				return (ft::make_pair(end(), false));
			}

			void	erase( iterator pos )
			{
				node_pointer	nodeToBeDeleted = pos.base();
				COLOR			originalColor = nodeToBeDeleted->color;
				node_pointer	x;

				if (pos == _delimitingNode)
					return ;
				if (nodeToBeDeleted->left == NULL)
				{
					x = nodeToBeDeleted->right;
					_transplant_node(nodeToBeDeleted, x);
				}
				else if (nodeToBeDeleted->right == NULL)
				{
					x = nodeToBeDeleted->left;
					_transplant_node(nodeToBeDeleted, x);
				}
				else
				{
					node_pointer	y = nodeToBeDeleted->right;
					while (y != NULL && y->left != NULL)
						y = y->left;
					originalColor = y->color;
					x = y->right;
					if (y->parent == nodeToBeDeleted)
					{
						x->parent = y;
					}
					else
					{
						_transplant_node(y, y->right);
						y->right = nodeToBeDeleted->right;
						y->right->parent = y;
					}
					_transplant_node(nodeToBeDeleted, y);
					y->left = nodeToBeDeleted->left;
					y->left->parent = y;
					y->color = nodeToBeDeleted->color;
				}
				_delete_node(nodeToBeDeleted);
				if (originalColor == BLACK)
					_erase_rb_violation(x);
			}


/* =================	Lookup								================= */

			//	Finds an element with key equivalent to key.
			iterator	find( const key_type& key )
			{
				return (iterator(_search(_root, key)));
			}

			const_iterator find( const key_type& key ) const
			{
				return (const_iterator(_search(_root, key)));
			}


/* =================	Observers							================= */

			value_compare	value_comp() const
		{
			return (_comp);
		}


/* =================	private Member-functions			================= */

		private:

			node_pointer	_new_node( value_type value_pair, node_pointer parent )
			{
				node_pointer	n = _node_alloc.allocate(1);
				_value_alloc.construct(&n->value_pair, value_pair);
				n->parent = parent;
				++_size;
				return (n);
			}

			void	_delete_node( node_pointer n )
			{
				_value_alloc.destroy(&(n->value_pair));
				_node_alloc.deallocate(n, 1);
				--_size;
			}

			node_pointer	_search( node_pointer n, key_type k ) const
			{
				while (n != NULL)
				{
					if (k == n->value_pair.first)								//	was passiert wenn wir bei der _delimitingNode landen??
						return (n);
					else if (k < n->value_pair.first)
						n = n->left;
					else
						n = n->right;
				}
				return (_delimitingNode);
			}

			void	_clear_helper( node_pointer n )
			{
				if (n == NULL)
					return ;
				if (n->left == NULL && n->right == NULL)
				{
					_delete_node(n);
				}
				else if (n->left != NULL)
				{
					_clear_helper(n->left);
				}
				else
				{
					_clear_helper(n->right);
				}
			}

			void	_transplant_node( node_pointer o, node_pointer n )
			{
				if (o->parent == NULL)
					_root = n;
				else if (o == o->parent->left)
					o->parent->left = n;
				else
					o->parent->right = n;
				if (_delimitingNode->left == o)
					_delimitingNode->left = n;
				n->parent = o->parent;											//	maybe needs protection in case last element is removed
			}

			void	_left_rotate( node_pointer o )
			{
				node_pointer	n = o->right;
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

			void	_right_rotate( node_pointer o )
			{
				node_pointer	n = o->left;
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

			void	_insert_rb_violation( node_pointer n )
			{
				while (n->parent->color == RED)									//	tutorial and codebase differ
				{
					if (n->parent->parent->left == n->parent)
					{
						if (n->parent->parent->right->color == RED)
						{
							n->parent->parent->left->color = BLACK;					//	this codeblock is double
							n->parent->parent->right->color = BLACK;
							n->parent->parent->color = RED;
							n = n->parent->parent;
						}
						else 
						{
							if (n->parent->right == n)
							{
								n->parent = n;
								_left_rotate(n);
							}
							n->parent->color = BLACK;
							n->parent->parent->color = RED;
							_right_rotate(n->parent->parent);
						}
					}
					else
					{
						if (n->parent->parent->left->color == RED)
						{
							n->parent->parent->left->color = BLACK;
							n->parent->parent->right->color = BLACK;
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
					if (n == _root)
						break ;
				}
				_root->color = BLACK;
			}

			void	_erase_rb_violation( node_pointer n )
			{
				while (n != _root && n->color == BLACK)
				{
					if (n == n->parent->left)
					{
						node_pointer	sibling = n->parent->right;
						if (sibling->color == RED)
						{
							sibling->color = BLACK;
							n->parent->color = RED;
							_left_rotate(n->parent);
							sibling = n->parent->right;
						}
						if (sibling->left->color == BLACK && sibling->right->color == BLACK)
						{
							sibling->color = RED;
							n = n->parent;
						}
						else {
							if (sibling->right->color == BLACK)
							{
								sibling->left->color = BLACK;
								sibling->color = RED;
								_right_rotate(sibling);
								sibling = n->parent->right;
							}
							sibling->color = n->parent->color;
							n->parent->color = BLACK;
							sibling->right->color = BLACK;
							_left_rotate(n->parent);
							n = _root;
						}
					}
					else
					{
						node_pointer	sibling = n->parent->left;
						if (sibling->color == RED)
						{
							sibling->color = BLACK;
							n->parent->color = RED;
							_right_rotate(n->parent);
							sibling = n->parent->left;
						}
						if (sibling->right->color == BLACK && sibling->left->color == BLACK)
						{
							sibling->color = RED;
							n = n->parent;
						}
						else {
							if (sibling->left->color == BLACK)
							{
								sibling->right->color = BLACK;
								sibling->color = RED;
								_left_rotate(sibling);
								sibling = n->parent->left;
							}
							sibling->color = n->parent->color;
							n->parent->color = BLACK;
							sibling->left->color = BLACK;
							_right_rotate(n->parent);
							n = _root;
						}
					}
				}
			}
	}; //	class red_black_tree

} //	namespace ft
