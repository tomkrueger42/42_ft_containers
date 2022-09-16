#pragma once
#include <vector>

#define	GROWING_FACTOR 2 // needs to be larger than 1!

namespace ft {
template<typename T>
class Vector
{
	public:
		Vector(void) : _data(nullptr), _size(0), _capacity(0)
		{
			realloc(2);
		}

		void	push_back(const T& value)
		{
			if (_size >= _capacity)
				realloc(_capacity * GROWING_FACTOR);
			_data[_size] = value;
			_size++;
		}

		size_t	size(void) const
		{
			return (_size);
		}

		const T	&operator[](size_t index) const
		{
			if (index >= _size)
			{
				// out of bounds protection??
			}
			return (_data[index]);
		}

		T	&operator[](size_t index)
		{
			if (index >= _size)
			{
				// out of bounds protection??
			}
			return (_data[index]);
		}

	private:
		void	realloc(size_t newCapacity)
		{
			T	*newVector = new T[newCapacity];
			if (newCapacity < _size)
				_size = newCapacity;
			std::memmove(newVector, _data, _size * sizeof(T));
			// for (size_t i = 0; i < _size; i++)
			// 	newVector[i] = _data[i];
			delete []_data;
			_data = newVector;
			_capacity = newCapacity;
		}

	private:
		T	*_data;
		size_t	_size;
		size_t	_capacity;
};
}