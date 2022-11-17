#ifndef TREE_REVERSE_ITERATOR_HPP
# define TREE_REVERSE_ITERATOR_HPP

namespace ft {

	template<class Iterator>
		class tree_reverse_iterator {
			public:
				typedef typename Iterator::difference_type		difference_type;
				typedef typename Iterator::value_type			value_type;
				typedef typename Iterator::pointer				pointer;
				typedef typename Iterator::reference			reference;
				typedef typename Iterator::iterator_category	iterator_category;
				typedef typename Iterator::variable_type		variable_type;
		
			private:
				Iterator	_it;

			public:
				/* default */
				tree_reverse_iterator( Iterator it = NULL ) : _it(it) {}

				/* copy */
				template<class Iter>
				tree_reverse_iterator( const tree_reverse_iterator<Iter> &in ) : _it(in.base()) {}

				/* destructor */
				~tree_reverse_iterator() {}

				Iterator					base() const { return _it; }

				tree_reverse_iterator &		operator=( const tree_reverse_iterator & in ) { this->_it = in.base(); return *this; }
				
				variable_type &				operator*() { Iterator temp(_it); --temp; return (*temp); }
				variable_type &				operator*() const { Iterator temp(_it); --temp; return (*temp); }
				
				variable_type *				operator->() { Iterator temp(_it); --temp; return temp.operator->(); }
				variable_type *				operator->() const { Iterator temp(_it); --temp; return temp.operator->(); }
		
				tree_reverse_iterator &		operator++() {
					--(_it);
					return *this;
				}

				tree_reverse_iterator &		operator--() {
					++(_it);
					return *this;
				}

				tree_reverse_iterator		operator++(int) {
					tree_reverse_iterator	temp = *this;
					++(*this);
					return temp;
				}
		
				tree_reverse_iterator		operator--(int) {
					tree_reverse_iterator	temp = *this;
					--(*this);
					return temp;
				}

				bool		operator==( const tree_reverse_iterator & in ) {
					return (this->base() == in.base());
				}
		
				bool		operator!=( const tree_reverse_iterator & in ) {
					return (this->base() != in.base());
				}
		
		}; /* class tree_reverse_iterator */
} /* namespace ft */

#endif