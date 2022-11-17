#ifndef SET_HPP
# define SET_HPP

# include <memory>

# include "../utils/red_black_tree.hpp"
# include "../utils/pair.hpp"
# include "../utils/equal.hpp"
# include "../utils/lexicographical_compare.hpp"

namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
		public:
			typedef				T									key_type;
			typedef				T									value_type;
			typedef				Compare								key_compare;
			typedef				Compare								value_compare;
			typedef				Alloc								allocator_type;
			typedef typename	allocator_type::reference			reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer		const_pointer;
			typedef				ft::RBTree<const T, value_compare>	RBTree;
			typedef typename	RBTree::iterator					iterator;
			typedef typename	RBTree::const_iterator				const_iterator;
			typedef typename	RBTree::reverse_iterator			reverse_iterator;
			typedef typename	RBTree::const_reverse_iterator		const_reverse_iterator;
			typedef				size_t								size_type;
			typedef				ptrdiff_t							difference_type;

		private:
			allocator_type	_alloc;
			key_compare		_compare;
			size_type		_size;
			RBTree			_tree;

		public:
			/* default */
			explicit set( const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type() ) : _alloc(alloc), _compare(comp), _size(0) {}

			/* range */
			template <class InputIterator>
			set( InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type() ) : _alloc(alloc), _compare(comp), _size(0) {
				insert(first, last);
			}

			/* copy */
			set( const set& x ) : _size(0) { *this = x; }

			/* destructor */
			~set() { clear(); }

			/* operator overload */
			set &	operator=( const set& x ) {
				if (_size)
					this->clear();
				this->insert(x.begin(), x.end());
				this->_compare = x._compare;
				this->_alloc = x._alloc;
				this->_size = x._size;
				return *this;
			}

			/* single element */
			ft::pair<iterator, bool>	insert( const value_type& val ) {
				ft::pair<iterator, bool> ret = _tree.insert(val);
				if (ret.second)
					_size++;
				return ret;
			}

			/* with hint */
			iterator insert (iterator position, const value_type& val) {
				if (position == end() || position.base() == NULL)
					return (insert(val).first);
				ft::pair<iterator, bool>	ret = _tree.insert_hint(val, position.base());
				if (ret.second)
					_size += 1;
				return ret.first;
			}

			/* range */
			template <class InputIterator>
			void	insert( InputIterator first, InputIterator last ) {
				for (;first != last; first++) {
					if (_tree.insert(*first).second)
						_size++;
				}
			}

			/* iterator */
			iterator				begin() { return _tree.begin(); }
			const_iterator			begin() const { return _tree.begin(); }

			reverse_iterator		rbegin() { return _tree.rbegin(); }
			const_reverse_iterator	rbegin() const { return _tree.rbegin(); }

			iterator				end() { return _tree.end(); }
			const_iterator			end() const { return _tree.end(); }

			reverse_iterator		rend() { return _tree.rend(); }
			const_reverse_iterator	rend() const { return _tree.rend(); }
			/* iterator */

			/* size */
			size_type				size() const { return _size; }
			size_type				max_size() const { return _tree.max_size(); };
			/* size */

			/* compare */
			value_compare			value_comp() const { return _compare; }
			key_compare				key_comp() const { return _compare; }
			/* compare */

			bool					empty() const { return (_size == 0); }

			allocator_type			get_allocator() const { return allocator_type(_alloc); }

			void					clear() { if (_size) {erase(begin(), end());} }

			void					swap( set& x ) {
				allocator_type	temp_alloc = this->_alloc;
				key_compare		temp_compare = this->_compare;
				size_type		temp_size = this->_size;
				RBTree			temp_tree = this->_tree;
				this->_alloc = x._alloc;
				this->_compare = x._compare;
				this->_size = x._size;
				this->_tree = x._tree;
				x._alloc = temp_alloc;
				x._compare = temp_compare;
				x._size = temp_size;
				x._tree = temp_tree;
			}

			iterator				find( const value_type& val ) const {
				iterator	ret = _tree.search(val, _tree.getRoot());
				if (*ret != val)
					return end();
				return ret;
			}

			size_type				count( const value_type& val ) const {
				if (find(val) == end())
					return 0;
				return 1;
			}

			/* position */
			void		erase( iterator position ) {
				if (_tree.erase(position))
					_size--;
			}

			/* value */
			size_type	erase( const value_type& val ) {
				if (_tree.deleteByVal(val)) {
					_size--;
					return 1;
				}
				return 0;
			}

			/* range */
			void		erase( iterator first, iterator last ) {
				value_type next = *first;
				while (first != last) {
					first = find(next);
					value_type	curr = *first;
					first++;
					next = *first;
					erase(curr);
				}
			}

			iterator	upper_bound( const value_type& val ) const {
				iterator beg = this->begin();
				while (beg != this->end()) {
					if (_compare(val, *beg))
						return beg;
					beg++;
				}
				return beg;
			}

			iterator	lower_bound( const value_type& val ) const {
				iterator beg = this->begin();
				while (beg != this->end()) {
					if (!_compare(*beg, val))
						return beg;
					beg++;
				}
				return beg;
			}

			ft::pair<iterator, iterator>	equal_range( const value_type& val ) const {
				return ft::make_pair<iterator, iterator>(lower_bound(val), upper_bound(val));
			}

	}; /* class set */


	template <class T, class Compare, class Alloc>
	bool operator== ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Compare, class Alloc>
	bool operator!= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
		return !(lhs == rhs);
	}

	template <class T, class Compare, class Alloc>
	bool operator<  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Compare, class Alloc>
	bool operator<= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
		if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			return true;
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size()))
			return true;
		return false;
	}

	template <class T, class Compare, class Alloc>
	bool operator>  ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
		return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template <class T, class Compare, class Alloc>
	bool operator>= ( const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs ) {
		if (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()))
			return true;
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size()))
			return true;
		return false;
	}

	template <class T, class Compare, class Alloc>
	void	swap( set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y ) { x.swap(y); }
} /* namespace ft */

#endif