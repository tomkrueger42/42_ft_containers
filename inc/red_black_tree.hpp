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
			value_compare			_compare;
			size_type				_size;
			node_pointer			_root;
			node_pointer			_endNode;
			node_pointer			_beginNode;


		public:

/* =================	Member classes						================= */

			red_black_tree( void )
			{
				LOGN1("rb_tree: default constructor");
				_compare = value_compare();
				_value_alloc = value_allocator_type();
				_root = NULL;
				_endNode = _new_node(value_type(), NULL);
				_beginNode = _endNode;
				_node_alloc = node_allocator_type();
				_size = 0;
				LOGI2(_endNode);
			}

			red_black_tree( value_compare comp, value_allocator_type value_allocator = value_allocator_type())
			{
				LOGN1("rb_tree: init constructor");
				_compare = comp;
				_value_alloc = value_allocator;
				_root = NULL;
				_endNode = _new_node(value_type(), NULL);
				_beginNode = _endNode;
				_node_alloc = node_allocator_type();
				_size = 0;
				LOGI2(_endNode);
			}

			red_black_tree( const red_black_tree& other )
			{
				LOGN1("rb_tree: copy constructor");
				_compare = value_compare();
				_value_alloc = value_allocator_type();
				_root = NULL;
				_endNode = _new_node(value_type(), NULL);
				_beginNode = _endNode;
				_node_alloc = node_allocator_type();
				_size = 0;
				*this = other;
				LOGI2(_endNode);
			}

			~red_black_tree( void )
			{
				LOGN1("rb_tree: destructor");
				clear();
				_delete_node(_endNode);
			}

			red_black_tree&	operator=( const red_black_tree& other )
			{
				LOGN1("rb_tree: operator=");
				if (this != &other)
				{
					clear();
					_node_alloc = other._node_alloc;
					_value_alloc = other._value_alloc;
					_compare = other._compare;
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
				return (iterator(_beginNode));
			}

			const_iterator	begin( void ) const
			{
				return (const_iterator(_beginNode));
			}

			iterator	end( void )
			{
				return (iterator(_endNode));
			}

			const_iterator	end( void ) const
			{
				return (const_iterator(_endNode));
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
				LOG1("rb_tree: clear(): ");
				if (_root != NULL)
					LOGN1(_root->value_pair.first);
				else
					LOGN1("(null)");
				_clear_helper(_root);
				_root = NULL;
				_beginNode = _endNode;
				_endNode->parent = NULL;
			}

			//	Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
			//	(1) Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
			ft::pair<iterator, bool>	insert( const value_type& value, node_pointer pos )
			{
				LOG1("rb_tree: insert: ");
				LOGN1(value.first);
				// if (_root != NULL)
				// 	LOGI1(_root->value_pair.first);
				if (pos == NULL)
					pos = _root;
				if (pos == NULL)
				{
					LOGN2("root insert");
					_root = _new_node(value, NULL);
					_root->color = BLACK;
					_root->right = _endNode;
					_endNode->parent = _root;
					_beginNode = _root;
					return (ft::make_pair(iterator(_root), true));
				}
				while (pos != NULL)
				{
					if (_compare(value, pos->value_pair) && pos->left != NULL)
						pos = pos->left;
					else if (_compare(pos->value_pair, value) && pos->right != NULL && pos->right != _endNode)
						pos = pos->right;
					else
						break ;
				}
				if (_compare(value, pos->value_pair))						//	value is inserted left of n
				{
					pos->left = _new_node(value, pos);
					if (pos == _beginNode)										//	begin iterator is invalidated
						_beginNode = pos->left;
					_insert_rb_violation(pos->left);							//	pos->right or pos->left??
					return (ft::make_pair(iterator(pos->left), true));
				}
				else if (_compare(pos->value_pair, value))					//	value is inserted right of n
				{
					if (pos->right == _endNode)									//	value is largest in tree: end iterator is invalidated
					{
						pos->right = _new_node(value, pos);
						pos->right->right = _endNode;
						_endNode->parent = pos->right;
					}
					else
						pos->right = _new_node(value, pos);
					_insert_rb_violation(pos->right);
					return (ft::make_pair(iterator(pos->right), true));
				}
				return (ft::make_pair(iterator(pos), false));
			}

			void	erase( node_pointer n )
			{
				LOG1("rb_tree: erase(): ");
				if (n != NULL)
					LOGN1(n->value_pair.first);
				else
					LOGN1("(null)");

				COLOR			originalColor = n->color;
				node_pointer	x;

				if (n->left == NULL)
				{
					x = n->right;
					if (n == _beginNode && n->right != NULL)				//	invalidating begin() iterator
						_beginNode = n->right;
					else if (n == _beginNode)
						_beginNode = n->parent;
					_transplant_node(n, x);
				}
				else if (n->right == NULL)
				{
					x = n->left;
					_transplant_node(n, x);
				}
				else
				{
					node_pointer	y = n->right;
					while (y != NULL && y->left != NULL)
						y = y->left;
					originalColor = y->color;
					x = y->right;
					if (y->parent == n)
					{
						x->parent = y;
					}
					else
					{
						_transplant_node(y, y->right);
						y->right = n->right;
						y->right->parent = y;
					}
					_transplant_node(n, y);
					y->left = n->left;
					y->left->parent = y;
					y->color = n->color;
				}
				_delete_node(n);
				if (originalColor == BLACK)
					_erase_rb_violation(x);
			}


/* =================	Lookup								================= */

			//	Finds an element with key equivalent to key.
			iterator	find( const key_type& key )
			{
				LOGN1("rb_tree: find()");
				return (iterator(_search(_root, ft::make_pair(key, mapped_type()))));
			}

			const_iterator find( const key_type& key ) const
			{
				LOGN1("rb_tree: find() const");
				return (const_iterator(_search(_root, ft::make_pair(key, mapped_type()))));
			}


/* =================	Observers							================= */

			value_compare	value_comp() const
			{
				LOGN1("rb_tree: value_comp()");
				return (_compare);
			}


/* =================	private Member-functions			================= */

		private:

			node_pointer	_new_node( value_type value_pair, node_pointer parent )
			{
				LOGN1("rb_tree: _new_node()");
				node_pointer	n = _node_alloc.allocate(1);
				_node_alloc.construct(n);
				_value_alloc.construct(&n->value_pair, value_pair);
				n->parent = parent;
				++_size;
				return (n);
			}

			void	_delete_node( node_pointer n )
			{
				LOGN1("rb_tree: _delete_node()");
				_value_alloc.destroy(&(n->value_pair));
				_node_alloc.destroy(n);
				_node_alloc.deallocate(n, 1);
				--_size;
			}

			node_pointer	_search( node_pointer n, value_type value ) const
			{
				LOG1("rb_tree: _search(): ");
				if (n != NULL)
					LOGN1(n->value_pair.first);
				else
					LOGN1("(null)");

				while (n != NULL)
				{
					if (_compare(value, n->value_pair))
						n = n->left;
					else if (_compare(n->value_pair, value))
						n = n->right;
					else
						return (n);
				}
				return (_endNode);
			}

			void	_clear_helper( node_pointer n )
			{
				LOG1("rb_tree: _clear_helper(): ");
				if (n != NULL)
					LOGN1(n->value_pair.first);
				else
					LOGN1("(null)");

				if (n == NULL)
					return ;
				_clear_helper(n->left);
				if (n->right != _endNode)
					_clear_helper(n->right);
				if (n != _endNode)
					_delete_node(n);
			}

			void	_transplant_node( node_pointer o, node_pointer n )
			{
				LOG1("rb_tree: _transplant_node(): ");
				if (o != NULL)
					LOGN1(o->value_pair.first);
				else
					LOGN1("(null)");

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

			void	_left_rotate( node_pointer o )
			{
				LOG1("rb_tree: _left_rotate(): ");
				if (o != NULL)
					LOGN1(o->value_pair.first);
				else
					LOGN1("(null)");

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
				LOG1("rb_tree: _right_rotate(): ");
				if (o != NULL)
					LOGN1(o->value_pair.first);
				else
					LOGN1("(null)");

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
				LOG1("rb_tree: _insert_rb_violation(): ");
				if (n != NULL)
					LOGN1(n->value_pair.first);
				else
					LOGN1("(null)");

				while (n != NULL && n->parent != NULL && n->parent->parent != NULL
						&& n != _root && n->parent->color == RED)									//	tutorial and codebase differ
				{
					if (n->parent->parent->right == n->parent)
					{
						if (n->parent->parent->left != NULL && n->parent->parent->left->color == RED)
						{
							n->parent->parent->left->color = BLACK;
							n->parent->right->color = BLACK;
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
							n->parent->color = BLACK;					//	this codeblock is double
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

			void	_erase_rb_violation( node_pointer n )
			{
				LOG1("rb_tree: _erase_rb_violation(): ");
				if (n != NULL)
					LOGN1(n->value_pair.first);
				else
					LOGN1("(null)");

				while (n != NULL && n != _root && n->color == BLACK)
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
