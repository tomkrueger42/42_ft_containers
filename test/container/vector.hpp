#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <exception>

# include "../iterator/vector_iterator.hpp"
# include "../iterator/reverse_iterator.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/lexicographical_compare.hpp"
# include "../utils/equal.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef				T													value_type;
			typedef				Alloc												allocator_type;
			typedef typename	allocator_type::reference							reference;
			typedef typename	allocator_type::const_reference						const_reference;
			typedef typename	allocator_type::pointer								pointer;
			typedef typename	allocator_type::const_pointer						const_pointer;
			typedef typename	allocator_type::size_type							size_type;
			typedef typename	ft::vector_iterator<value_type>::difference_type	difference_type;
			typedef				ft::vector_iterator<value_type>						iterator;
			typedef 			ft::vector_iterator<const value_type>				const_iterator;
			typedef				ft::reverse_iterator<iterator>						reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		private:
			size_type		_size;
			size_type		_capacity;
			pointer			_ptr;
			Alloc			_alloc;

		public:
			/* default constructor */
			explicit vector( const allocator_type& alloc = allocator_type() ) {
				this->_alloc = alloc;
				this->_ptr = this->_alloc.allocate(0);
				this->_size = 0;
				this->_capacity = 0;
			}

			/* fill constructor */
			explicit vector( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() ) {
				this->_alloc = alloc;
				this->_ptr = this->_alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
					this->_alloc.construct(&this->_ptr[i], val);
				this->_size = n;
				this->_capacity = n;
			}

			/* range constructor */
			template <class InputIterator>
			vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0 ) {
				this->_alloc = alloc;
				difference_type	distance = ft::difference(first, last);
				this->_ptr = this->_alloc.allocate(distance);
				for (size_t i = 0; first != last; i++) {
					this->_alloc.construct(&this->_ptr[i], *first);
					first++;
				}
				this->_size = distance;
				this->_capacity = distance;
			}

			/* copy constructor */
			vector( const vector& x ) {
				this->_alloc = x.get_allocator();
				this->_ptr = this->_alloc.allocate(x._capacity);
				for (size_t i = 0; i < x._size; i++)
					this->_alloc.construct(&this->_ptr[i], x._ptr[i]);
				this->_capacity = x._capacity;
				this->_size = x._size;
			}

			/* destructor */
			~vector() { clear(); }

			/* size */
			size_type				size() const { return (this->_size); }
			size_type				max_size() const { return (this->_alloc.max_size()); }
			/* size */

			/* iterator */
			iterator				begin() { return iterator(this->_ptr); }
			const_iterator			begin() const { return (const_iterator(this->_ptr)); }

			reverse_iterator		rbegin() { return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin() const { return (const_reverse_iterator(end())); }

			iterator				end() { return iterator(this->_ptr + this->_size); }
			const_iterator			end() const { return (const_iterator(this->_ptr + this->_size)); }

			reverse_iterator		rend() { return (reverse_iterator(begin())); }
			const_reverse_iterator	rend() const { return (const_reverse_iterator(begin())); }
			/* iterator */

			/* get values */
			reference				front() { return (this->_ptr[0]); }
			const_reference			front() const { return (this->_ptr[0]); }

			reference				back() { return (this->_ptr[this->_size - 1]); }
			const_reference			back() const { return (this->_ptr[this->_size - 1]); }

			reference				operator[]( size_type n ) { return (this->_ptr[n]); }
			const_reference			operator[]( size_type n ) const { return (this->_ptr[n]); }
			/* get values */

			bool					empty() const { return (this->_size == 0); }

			size_type				capacity() const { return (this->_capacity); }

			allocator_type			get_allocator() const { return (Alloc(this->_alloc)); }

			void	reserve( size_type n ) {
				if (n > this->_alloc.max_size())
					throw std::length_error("vector");
				if (n <= this->_capacity)
					return ;
				pointer	newPtr = this->_alloc.allocate(n);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.construct(&newPtr[i], this->_ptr[i]);
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&(this->_ptr[i]));
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = newPtr;
				this->_capacity = n;
			}

			void	push_back( const value_type& val ) {
				if (this->_capacity > this->_size) {
					this->_alloc.construct(&this->_ptr[this->_size], val);
					this->_size++;
				}
				else if (!this->_capacity && !this->_size) {
					pointer	newPtr = this->_alloc.allocate(1);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_alloc.construct(&this->_ptr[this->_size], val);
					this->_capacity++;
					this->_size++;
				}
				else if (this->_capacity == this->_size) {
					pointer	newPtr = this->_alloc.allocate(this->_capacity * 2);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.construct(&newPtr[i], this->_ptr[i]);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_alloc.construct(&this->_ptr[this->_size], val);
					this->_capacity *= 2;
					this->_size++;
				}
			}

			reference	at( size_type n ) {
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return this->_ptr[n];
			}

			const_reference	at( size_type n ) const {
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return this->_ptr[n];
			}

			void	clear() {
				for (size_t i = 0; i < this->_size; i++)
					this->_alloc.destroy(&this->_ptr[i]);
				this->_size = 0;
			}

			void	pop_back() {
				if (this->_size == 0)
					return ;
				this->_alloc.destroy(&this->_ptr[this->_size - 1]);
				this->_size--;
			}

			void	resize( size_type n, value_type val = value_type() ) {
				if (n < this->_size) {
					for (size_t i = n; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_size = n;
				}
				else if (n > this->_capacity) {
					pointer	newPtr = this->_alloc.allocate(n);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.construct(&newPtr[i], this->_ptr[i]);
					for (size_t i = this->_size; i < n; i++)
						this->_alloc.construct(&newPtr[i], val);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_capacity = n;
					this->_size = n;
				}
				else if (n <= this->_capacity) {
					for (size_t i = this->_size; i < n; i++)
						this->_alloc.construct(&this->_ptr[i], val);
					this->_size = n;
				}
			}

			void	swap( vector& x ) {
				size_type	temp_size = this->_size;
				size_type	temp_capacity = this->_capacity;
				pointer		temp_ptr = this->_ptr;
				Alloc		temp_alloc = this->_alloc;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_ptr = x._ptr;
				this->_alloc = x._alloc;
				x._size = temp_size;
				x._capacity = temp_capacity;
				x._ptr = temp_ptr;
				x._alloc = temp_alloc;
			}

			vector &	operator=( const vector& x ) {
				if (this->_capacity >= x._capacity) {
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					for (size_t i = 0; i < x._size; i++)
						this->_alloc.construct(&this->_ptr[i], x._ptr[i]);
					this->_size = x._size;
				}
				else if (this->_capacity < x._capacity) {
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = this->_alloc.allocate(x._size);
					for (size_t i = 0; i < x._size; i++)
						this->_alloc.construct(&this->_ptr[i], x._ptr[i]);
					this->_size = x._size;
					this->_capacity = x._size;
				}
				return *this;
			}

			/* range */
			template <class InputIterator>
			void	assign( InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0 ) {
				size_t	distance = ft::difference(first, last);
				if (distance > this->_capacity) {
					pointer	newPtr = this->_alloc.allocate(distance);
					for (size_t i = 0; first != last; i++) {
						this->_alloc.construct(&newPtr[i], *first);
						first++;
					}
					this->clear();
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_size = distance;
					this->_capacity = distance;
				}
				else {
					this->clear();
					for (size_t i = 0; first != last; i++) {
						this->_alloc.construct(&this->_ptr[i], *first);
						first++;
					}
					this->_size = distance;
				}
			}
			
			/* fill */
			void	assign( size_type n, const T& val ) {
				if (n > this->_capacity) {
					pointer	newPtr = this->_alloc.allocate(n);
					for (size_t i = 0; i < n; i++)
						this->_alloc.construct(&newPtr[i], val);
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_size = n;
					this->_capacity = n;
				}
				else {
					for (size_t i = 0; i < this->_size; i++)
						this->_alloc.destroy(&this->_ptr[i]);
					for (size_t i = 0; i < n; i++)
						this->_alloc.construct(&this->_ptr[i], val);
					this->_size = n;
				}
			}

			/* single element */
			iterator	erase( iterator position ) {
				iterator posp1 = position;
				posp1++;
				for (iterator cop = position; cop != this->end(); cop++, posp1++)
					if (posp1 != this->end())
						*cop = *posp1;
				this->_size--;
				return position;
			}

			/* range */
			iterator	erase( iterator first, iterator last ) {
				for (iterator it = first; last + (it - first) != end(); it++)
					*it = *(last + (it - first));
				this->_size -= (last - first);
				return first;
			}

			/* single element */
			iterator	insert( iterator position, const value_type& val ) {
				difference_type	index = ft::difference(begin(), position);
				insert(position, 1, val);
				return (iterator(this->_ptr + index));
			}

			/* fill */
			void	insert( iterator position, size_type n, const value_type& val ) {
				if (position == end() || (position == begin() && !this->_size)) {
					for (size_t i = 0; i < n; i++)
						push_back(val);
					return ;
				}
				else {
					size_type	sizeToAllocate = this->_capacity;
					if (sizeToAllocate < this->_size + n) {
						while (sizeToAllocate < this->_size + n)
							sizeToAllocate *= 2;
					}
					pointer		newPtr = this->_alloc.allocate(sizeToAllocate);
					for (iterator it = begin(); it != position; it++)
						this->_alloc.construct(&newPtr[it - begin()], *it);
					difference_type	distance = ft::difference(begin(), position);
					for (size_t i = 0; i < n; i++)
						this->_alloc.construct(&newPtr[distance + i], val);
					for (iterator it = position; it != end(); it++) {
						this->_alloc.construct(&newPtr[distance + n], *it);
						distance++;
					}
					size_type	newSize = this->_size + n;
					this->clear();
					this->_alloc.deallocate(this->_ptr, this->_capacity);
					this->_ptr = newPtr;
					this->_size = newSize;
					this->_capacity = sizeToAllocate;
				}
			}

			/* range */
			template <class InputIterator>
			void	insert( iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0 ) {
				if (position == end() || (position == begin() && !this->_size)) {
					for ( ; first != last; first++)
						push_back(*first);
					return ;
				}
				difference_type	n = ft::difference(first, last);
				size_type	sizeToAllocate = this->_capacity;
				if (sizeToAllocate < this->_size + n) {
					while (sizeToAllocate < this->_size + n)
						sizeToAllocate *= 2;
				}
				pointer	newPtr = this->_alloc.allocate(sizeToAllocate);
				for (iterator it = begin(); it != position; it++)
					this->_alloc.construct(&newPtr[it - begin()], *it);
				size_t i = position - begin();
				for ( ; first != last; first++) {
					this->_alloc.construct(&newPtr[i], *first);
					i++;
				}
				for (iterator it = position; it != end(); it++) {
					this->_alloc.construct(&newPtr[i], *it);
					i++;
				}
				size_type	newSize = this->_size + n;
				this->clear();
				this->_alloc.deallocate(this->_ptr, this->_capacity);
				this->_ptr = newPtr;
				this->_size = newSize;
				this->_capacity = sizeToAllocate;
			}
	}; /* class vector */

	template <class T, class Alloc>
	bool	operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool	operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return true;
		return !ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool	operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool	operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
			return true;
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size()))
			return true;
		return false;
	}

	template <class T, class Alloc>
	bool	operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
	}

	template <class T, class Alloc>
	bool	operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
		if (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()))
			return true;
		if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size()))
			return true;
		return false;
	}

	template <class T, class Alloc>
	void	swap( vector<T,Alloc>& x, vector<T,Alloc>& y ) { x.swap(y); }
} /* namespace ft */

#endif