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

/* =================	Member types						================= */

			typedef Value																value_type;
			typedef Allocator															value_allocator_type;

			typedef Compare																value_compare;

			typedef typename red_black_tree_node< value_type >::node_type				node_type;
			typedef typename node_type::node_pointer									node_pointer;
			typedef typename value_allocator_type::template rebind<node_type>::other	node_allocator_type;
			typedef typename node_allocator_type::size_type								size_type;

			typedef typename ft::red_black_tree_iterator< node_type*, value_type >				iterator;
			typedef typename ft::red_black_tree_iterator< const node_type*, const value_type >	const_iterator;


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


			red_black_tree( void ) : _root(NULL)
			{
				LOGN1("rb_tree: default constructor");
				_endNode = _new_node(value_type(), NULL, BLACK);
				_beginNode = _endNode;
				_root = _endNode;
				_size = 0;
				LOGI2(_endNode);
			}

			~red_black_tree( void )
			{
				LOGN1("rb_tree: destructor");
				clear();
				LOGN1("hello");
				_delete_node(_endNode);
				LOGN1("destructor out");
			}

			red_black_tree&	operator=( const red_black_tree& other )
			{
				LOGN1("rb_tree: operator=");
				if (this != &other)
				{
					clear();
					_delete_node(_endNode);
					_compare = other._compare;
					_node_alloc = other._node_alloc;
					_value_alloc = other._value_alloc;
					_endNode = _new_node(value_type(), NULL, BLACK);
					_beginNode = _endNode;
					_root = _copy_tree(other.get_root(), NULL);
					_size = other._size;
					_set_iterator_pointers();
					LOGI1(_size);
				}
				return (*this);
			}

			// value_allocator_type	get_allocator( void ) const
			// {
			// 	return (_value_alloc);
			// }


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
				LOGN1("after helper");
				_root = _endNode;
				_beginNode = _endNode;
				_endNode->parent = NULL;
			}

			//	Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
			//	(1) Returns a pair consisting of an iterator to the inserted element (or to the element that prevented the insertion) and a bool denoting whether the insertion took place.
			ft::pair<iterator, bool>	insert( const value_type& value, node_pointer pos )
			{
				// LOG("rb_tree: insert: ");
				// LOGN(value.first);
				// if (_root != NULL)
				// 	LOGI1(_root->value_pair.first);

				if (pos == NULL)
					pos = _root;
				if (pos == _endNode)
				{
					// LOGN("root insert");
					_root = _new_node(value, NULL, BLACK);
					_root->right = _endNode;
					_endNode->parent = _root;
					_beginNode = _root;
					return (ft::make_pair(iterator(_root), true));
				}
				while (pos != NULL)
				{
					// LOGN("loop");
					if (_compare(value, pos->value_pair) && pos->left != NULL)
						pos = pos->left;
					else if (_compare(pos->value_pair, value) && pos->right != NULL && pos->right != _endNode)
						pos = pos->right;
					else
						break ;
				}
				if (_compare(value, pos->value_pair))						//	value is inserted left of n
				{
					// LOGN("value is inserted left of n");
					pos->left = _new_node(value, pos, RED);
					if (pos == _beginNode)										//	begin iterator is invalidated
						_beginNode = pos->left;
					_insert_rb_violation(pos->left);							//	pos->right or pos->left??
					return (ft::make_pair(iterator(pos->left), true));
				}
				else if (_compare(pos->value_pair, value))					//	value is inserted right of n
				{
					// LOGN("value is inserted right of n");
					if (pos->right == _endNode)									//	value is largest in tree: end iterator is invalidated
					{
						pos->right = _new_node(value, pos, RED);
						pos->right->right = _endNode;
						_endNode->parent = pos->right;
					}
					else
						pos->right = _new_node(value, pos, RED);
					_insert_rb_violation(pos->right);
					// LOGN("end of insertion on the right");
					return (ft::make_pair(iterator(pos->right), true));
				}
				// LOGN("insertion unsuccessful");
				return (ft::make_pair(iterator(pos), false));
			}

			void	erase( node_pointer n )
			{
				LOG("rb_tree: erase(): ");
				if (n != NULL)
					LOGN(n->value_pair.first);
				else
					LOGN("(null)");
				LOGN(*n);

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
						if (x != NULL)
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

			iterator	lower_bound( const value_type& value )
			{
				iterator	it = begin();
				for ( ; it != end(); it++)
				{
					if (!_compare(*it, value))
						break ;
				}
				return (it);
			}

			const_iterator	lower_bound( const value_type& value ) const
			{
				const_iterator	it = begin();
				for ( ; it != end(); it++)
				{
					if (!_compare(*it, value))
						break ;
				}
				return (it);
			}

			iterator	upper_bound( const value_type& value )
			{
				iterator	it = begin();
				for ( ; it != end(); it++)
				{
					if (_compare(value, *it))
						break ;
				}
				return (it);
			}

			const_iterator	upper_bound( const value_type& value ) const
			{
				const_iterator	it = begin();
				for ( ; it != end(); it++)
				{
					if (_compare(value, *it))
						break ;
				}
				return (it);
			}


			node_pointer	search( value_type value, node_pointer n ) const
			{
				// LOG1("rb_tree: _search(): ");
				// if (n != NULL)
				// 	LOGN1(n->value_pair.first);
				// else
				// 	LOGN1("(null)");

				if (n == NULL)
					n = _root;
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

			node_pointer	get_root( void ) const
			{
				return (_root);
			}


/* =================	private Member-functions			================= */

		private:

			node_pointer	_new_node( value_type value, node_pointer parent, COLOR c )
			{
				LOG1("rb_tree: _new_node(): ");
				LOGN1(value.first);

				node_pointer	n = _node_alloc.allocate(1);
				n->parent = parent;
				n->left = NULL;
				n->right = NULL;
				n->color = c;
				_value_alloc.construct(&n->value_pair, value);
				++_size;
				return (n);
			}

			void	_delete_node( node_pointer n )
			{
				LOG1("rb_tree: _delete_node(): ");
				if (n != NULL)
					LOG1(n->value_pair.first);
				else
					LOGN1("(null)");
				LOG1("\t");
				LOGN1(&n->value_pair);

				_value_alloc.destroy(&(n->value_pair));
				_node_alloc.deallocate(n, 1);
				--_size;
			}

			node_pointer	_copy_tree( node_pointer n, node_pointer parent )
			{
				if (n == NULL)
					return (NULL);
				node_pointer	newNode = _new_node(n->value_pair, parent, n->color);
				newNode->left = _copy_tree(n->left, newNode);
				_endNode = newNode;												// sets the new end_iterator. should be done differently cause nobody will understand this!!
				newNode->right = _copy_tree(n->right, newNode);
				return (newNode);
			}

			void	_set_iterator_pointers( void )
			{
				_beginNode = _root;
				while (_beginNode != NULL && _beginNode->left != NULL)
					_beginNode = _beginNode->left;
				_endNode = _root;
				while (_endNode != NULL && _endNode->right != NULL)
					_endNode = _endNode->right;
			}

			void	_clear_helper( node_pointer n )
			{
				LOG1("rb_tree: _clear_helper(): ");
				if (n != NULL)
					LOG1(n->value_pair.first);
				else
					LOGN1("(null)");
				LOG1("\t");
				LOGN1(n);

				if (n == NULL || n == _endNode)
					return ;
				_clear_helper(n->left);
				_clear_helper(n->right);
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
					// LOGI(n);
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
				// LOGN("end of _insert_rb_violation()");
				_root->color = BLACK;
			}

			// void	_erase_rb_violation( node_pointer n )
			// {
			// 	LOG("rb_tree: _erase_rb_violation(): ");
			// 	if (n != NULL)
			// 		LOGN(n->value_pair.first);
			// 	else
			// 		LOGN("(null)");

			// 	while (n != NULL && n != _root && n->color == BLACK)
			// 	{
			// 		LOGN(*n);
			// 		if (n == n->parent->left)
			// 		{
			// 			node_pointer	sibling = n->parent->right;
			// 			if (sibling->color == RED)
			// 			{
			// 				sibling->color = BLACK;
			// 				n->parent->color = RED;
			// 				_left_rotate(n->parent);
			// 				sibling = n->parent->right;
			// 			}
			// 			if (sibling->left->color == BLACK && sibling->right->color == BLACK)
			// 			{
			// 				sibling->color = RED;
			// 				n = n->parent;
			// 			}
			// 			else {
			// 				if (sibling->right->color == BLACK)
			// 				{
			// 					sibling->left->color = BLACK;
			// 					sibling->color = RED;
			// 					_right_rotate(sibling);
			// 					sibling = n->parent->right;
			// 				}
			// 				sibling->color = n->parent->color;
			// 				n->parent->color = BLACK;
			// 				sibling->right->color = BLACK;
			// 				_left_rotate(n->parent);
			// 				n = _root;
			// 			}
			// 		}
			// 		else
			// 		{
			// 			node_pointer	sibling = n->parent->left;
			// 			LOGI(sibling);
			// 			if (sibling != NULL && sibling->color == RED)
			// 			{
			// 				sibling->color = BLACK;
			// 				n->parent->color = RED;
			// 				_right_rotate(n->parent);
			// 				sibling = n->parent->left;
			// 			}
			// 			// LOGI(sibling->right);
			// 			// LOGI(sibling->left);
			// 			if (sibling->right != NULL && sibling->right->color == BLACK && sibling->left != NULL && sibling->left->color == BLACK)
			// 			{
			// 				sibling->color = RED;
			// 				n = n->parent;
			// 			}
			// 			else
			// 			{
			// 				LOGN("hello");
			// 				if (sibling != NULL && sibling->left != NULL && sibling->left->color == BLACK)
			// 				{
			// 					if (sibling->right != NULL)
			// 						sibling->right->color = BLACK;
			// 					sibling->color = RED;
			// 					_left_rotate(sibling);
			// 					sibling = n->parent->left;
			// 				}
			// 				if (sibling != NULL)
			// 					sibling->color = n->parent->color;
			// 				n->parent->color = BLACK;
			// 				if (sibling != NULL && sibling->left != NULL)
			// 					sibling->left->color = BLACK;
			// 				_right_rotate(n->parent);
			// 				n = _root;
			// 			}
			// 		}
			// 	}
			// }

			#define _GET_COLOR( n ) (n == NULL || n->color == BLACK) ? BLACK : RED
			#define _IS_LEFT_CHILD( n ) (n != NULL && n->parent != NULL && n == n->parent->left) ? true : false
			#define _IS_RIGHT_CHILD( n ) (n != NULL && n->parent != NULL && n == n->parent->right) ? true : false

			void	_erase_rb_violation( node_pointer n )
			{
				LOGN("_erase_rb_violation(): ");
				LOG(n);
				if (n == _root)
				{
					n->color = BLACK;
					return ;
				}

				node_pointer	parent = n->parent;
				node_pointer	sibling = parent->right;
				if (n == sibling)
					sibling = parent->left;

				if (sibling == NULL)
				{
					if (parent->color == RED)
						parent->color = BLACK;
					else
						_erase_rb_violation(parent);
				}
				else if (sibling->color == BLACK)
				{
					if ( (sibling->left == NULL || sibling->left->color == BLACK)
						&& (sibling->right == NULL || sibling->right->color == BLACK) )
					{
						n->color = BLACK;
						sibling->color = RED;
						if (parent->color == RED)
							parent->color = BLACK;
						else
							_erase_rb_violation(parent);
					}
					else
					{
						node_pointer	far_nephew = NULL;
						if (sibling != NULL && n == parent->left)
							far_nephew = sibling->right;
						else if (sibling != NULL)
							far_nephew = sibling->left;

						node_pointer	near_nephew = NULL;
						if (sibling != NULL && n == parent->left)
							far_nephew = sibling->left;
						else if (sibling != NULL)
							far_nephew = sibling->right;

						if (_GET_COLOR(far_nephew) == BLACK && _GET_COLOR(near_nephew) == RED)
						{
							_swap_colors(sibling, near_nephew);
							if (_IS_LEFT_CHILD(near_nephew))
								_left_rotate(sibling);
							else
								_right_rotate(sibling);
							_erase_rb_violation(n);
						}
						else if (_GET_COLOR(far_nephew) == RED && _GET_COLOR(near_nephew) == BLACK)
						{
							_swap_colors(sibling, parent);
							if (_IS_LEFT_CHILD(n))
								_left_rotate(sibling);
							else
								_right_rotate(sibling);
							far_nephew->color = BLACK;
							n->color = BLACK;
						}
						else if (_GET_COLOR(far_nephew) == RED && _GET_COLOR(near_nephew) == RED)
						{
							if (_IS_LEFT_CHILD(n))
								_left_rotate(sibling);
							else
								_right_rotate(sibling);
							if (parent->color == BLACK)
								far_nephew->color = BLACK;
							else
								_insert_rb_violation(near_nephew);
							n->color = BLACK;
						}
					}
				}
				else if (_GET_COLOR(sibling) == RED)
				{
					_swap_colors(sibling, parent);
					if (_IS_LEFT_CHILD(n))
						_left_rotate(sibling);
					else
						_right_rotate(sibling);
					_erase_rb_violation(n);
				}
			}

			void	_swap_colors( node_pointer n1, node_pointer n2 )
			{
				COLOR	c;
				c = _GET_COLOR(n1);
				n1->color = _GET_COLOR(n2);
				n2->color = c;
			}
	}; //	class red_black_tree
} //	namespace ft
