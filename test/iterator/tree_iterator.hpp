#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft {

	template<class T_node, class var_type , class var_type_no_const = var_type>
		class tree_iterator {
			public:
				typedef ptrdiff_t						difference_type;
				typedef T_node							value_type;
				typedef T_node *						pointer;
				typedef T_node &						reference;
				typedef ft::bidirectional_iterator_tag	iterator_category;
				typedef var_type						variable_type;
		
			private:
				pointer	_ptr;

			public:
				/* default */
				tree_iterator( pointer ptr = nullptr ) : _ptr(ptr) {}

				/* copy */
				tree_iterator( const tree_iterator &in ) : _ptr(in._ptr) {}

				/* copy from non-const to const */
				tree_iterator( tree_iterator<value_type, var_type_no_const, var_type_no_const> in ) : _ptr(in.base()) {}

				/* destructor */
				~tree_iterator() {}

				pointer				base() const { return _ptr; }
				
				variable_type &		operator*() { return _ptr->val; }
				variable_type &		operator*() const { return _ptr->val; }
				
				variable_type *		operator->() { return &(operator*()); }
				variable_type *		operator->() const { return &(operator*()); }
		
				tree_iterator &		operator++() {
					if (!_ptr)
						return *this;
					if (_ptr->right != NULL) {
						_ptr = _ptr->right;
						while (_ptr->left != NULL)
							_ptr = _ptr->left;
					}
					else {
						pointer	cur;
						cur = _ptr->parent;
						while (cur != NULL && cur->right == _ptr) {
							_ptr = cur;
							cur = _ptr->parent;
						}
						_ptr = cur;
					}
					return *this;
				}

				tree_iterator &		operator--() {
					if (!_ptr)
						return *this;
					if (_ptr->left != NULL) {
						_ptr = _ptr->left;
						while (_ptr->right != NULL)
							_ptr = _ptr->right;
					}
					else {
						pointer	cur;
						cur = _ptr->parent;
						while (cur != NULL && cur->left == _ptr) {
							_ptr = cur;
							cur = _ptr->parent;
						}
						_ptr = cur;
					}
					return *this;
				}

				tree_iterator		operator++(int) {
					tree_iterator	temp = *this;
					++(*this);
					return temp;
				}
		
				tree_iterator		operator--(int) {
					tree_iterator	temp = *this;
					--(*this);
					return temp;
				}

				bool		operator==( const tree_iterator & in ) {
					return (this->base() == in.base());
				}
		
				bool		operator!=( const tree_iterator & in ) {
					return (this->base() != in.base());
				}
		}; /* class tree_iterator */
} /* namespace ft */

#endif