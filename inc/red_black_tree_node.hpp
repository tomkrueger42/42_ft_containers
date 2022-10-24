#pragma once

namespace ft {

	enum COLOR {
		BLACK,
		RED
	};

	template< class T >
	class rb_node
	{
		public:
			typename T	value_type;

			rb_node*	_parent;
			rb_node*	_left;
			rb_node*	_right;
			value_type	_value;
			bool		_color;

			rb_node( void ) : _parent(NULL), _left(NULL), _right(NULL), _value(), _color(BLACK) {}

			rb_node( const value_type& value ) : _parent(NULL), _left(NULL), _right(NULL), _value(value), _color(BLACK) {}

			rb_node( const rb_node* parent, const rb_node* left, const rb_node* right, const value_type& value, bool color )
				: _parent(parent), _left(left), _right(right), value(value), _color(color) {}

			rb_node( const rb_node& other )
			{
				*this = other;
			}

			~rb_node( void ) {}

			rb_node&	operator=( const rb_node& other )
			{
				if (this != &other )
				{
					_parent = other._parent;
					_left = other._left;
					_right = other._right;
					_value = other._value;
					_color = other._color;
				}
				return (*this);
			}

			void	swap_family( rb_node& other )
			{
			rb_node*	tmp_parent = other._parent;
			rb_node*	tmp_left = other._left;
			rb_node*	tmp_right = other._right;
			other._parent = _parent;
			other._left = _left;
			other._right = _right; 
			_parent = tmp_parent;
			_left = tmp_left;
			_right = tmp_right;
			}
	};

} //	namespace ft