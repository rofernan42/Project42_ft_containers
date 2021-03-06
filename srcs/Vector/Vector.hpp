/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:10:37 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/27 17:10:40 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <memory>
# include <cstddef>
# include <string>
# include "../Iterator/RandomAccessIterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef RandomAccessIterator<T> iterator;
		typedef RandomAccessIterator<const T> const_iterator;
		typedef ReverseRandomAccess<T> reverse_iterator;
		typedef ReverseRandomAccess<const T> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		/* Member functions */
		vector(const allocator_type &alloc = allocator_type()) {
			_alloc = alloc;
			_vec = nullptr;
			_size = 0;
			_cap = 0;
		};
		vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) {
			_alloc = alloc;
			_vec = nullptr;
			_vec = _alloc.allocate(n);
			_size = 0;
			_cap = n;
			assign(n, val);
		};
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) {
			difference_type n = last - first;
			_alloc = alloc;
			_vec = nullptr;
			_vec = _alloc.allocate(n);
			_size = 0;
			_cap = n;
			assign(first, last);
		};
		vector(const vector &x) {
			_alloc = x._alloc;
			_vec = nullptr;
			_size = 0;
			_cap = 0;
			reserve(x._size);
			assign(x.begin(), x.end());
		};
		~vector() {
			if (_cap > 0)
				_alloc.deallocate(_vec, _cap);
		};
		vector	&operator=(const vector &x) {
			if (this != &x)
			{
				_alloc = x._alloc;
				_size = 0;
				reserve(x._size);
				assign(x.begin(), x.end());
			}
			return (*this);
		};

		/* Iterators */
		iterator				begin() {
			return (iterator(_vec));
		};
		const_iterator			begin() const {
			return (const_iterator(_vec));
		};
		iterator				end() {
			return (iterator(_vec + _size));
		};
		const_iterator			end() const {
			return (const_iterator(_vec + _size));
		};
		reverse_iterator		rbegin() {
			return (reverse_iterator(_vec + _size - 1));
		};
		const_reverse_iterator	rbegin() const {
			return (const_reverse_iterator(_vec + _size - 1));
		};
		reverse_iterator		rend() {
			return (reverse_iterator(_vec - 1));
		};
		const_reverse_iterator	rend() const {
			return (const_reverse_iterator(_vec - 1));
		};

		/* Capacity */
		size_type	size() const {
			return (_size);
		};
		size_type	max_size() const {
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		};
		void		resize(size_type n, value_type val = value_type()) {
			if (n < _size)
				_size = n;
			else if (n > _size)
			{
				reserve(n);
				for (size_t i = _size; i < n; i++)
					push_back(val);
			}
		};
		size_type	capacity() const {
			return (_cap);
		};
		bool		empty() const {
			return (_size == 0);
		};
		void		reserve(size_type n) {
			value_type	*tmp;
			if (n == 0)
				return ;
			if (n > max_size())
				throw (std::length_error("new capacity (which is " + std::to_string(n) \
				+ ") > max_size() (which is " + std::to_string(max_size()) + ")"));
			if (n > _cap)
			{
				tmp = _alloc.allocate(n);
				if (_cap > 0)
				{
					for (size_t i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _vec[i]);
					_alloc.deallocate(_vec, _cap);
				}
				_cap = n;
				_vec = tmp;
			}
		};

		/* Element access */
		reference		operator[](size_type n) {
			return (_vec[n]);
		};
		const_reference	operator[](size_type n) const {
			return (_vec[n]);
		};
		reference		at(size_type n) {
			if (n >= _size)
				throw (std::out_of_range("range_check: n (which is " + std::to_string(n) \
				+ ") >= this->size() (which is " + std::to_string(_size) + ")"));
			return (_vec[n]);
		};
		const_reference	at(size_type n) const {
			if (n >= _size)
				throw (std::out_of_range("range_check: n (which is " + std::to_string(n) \
				+ ") >= this->size() (which is " + std::to_string(_size) + ")"));
			return (_vec[n]);
		};
		reference		front() {
			return (_vec[0]);
		};
		const_reference	front() const {
			return (_vec[0]);
		};
		reference		back() {
			return (_vec[_size - 1]);
		};
		const_reference	back() const {
			return (_vec[_size - 1]);
		};

		/* Modifiers */
		template <class InputIterator>
		void		assign(InputIterator first, InputIterator last) {
			if (!empty())
				clear();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		};
		void		assign(size_type n, const value_type &val) {
			if (!empty())
				clear();
			for (size_type i = 0; i < n; i++)
				push_back(val);
		};
		void		push_back(const value_type &val) {
			if (_cap == 0)
				reserve(1);
			if (_vec == nullptr || _cap <= _size)
				reserve(_cap * 2);
			_alloc.construct(&_vec[_size], val);
			_size++;
		};
		void		pop_back() {
			erase(end() - 1);
		};
		iterator	insert(iterator position, const value_type &val) {
			difference_type pos = position - begin();

			if (_cap < _size + 1  && _size * 2 >= _size + 1)
				reserve(_size * 2);
			else if (_cap < _size + 1  && _size * 2 < _size + 1)
				reserve(_size + 1);
			_size++;
			for (size_t i = _size - 1; i > (size_t)pos; i--)
				_alloc.construct(&_vec[i], _vec[i - 1]);
			_alloc.construct(&_vec[pos], val);
			return (begin() + pos);
		};
		void		insert(iterator position, size_type n, const value_type &val) {
			difference_type pos = position - begin();

			if (_cap < _size + n && _size * 2 >= _size + n)
				reserve(_size * 2);
			else if (_cap < _size + n && _size * 2 < _size + n)
				reserve(_size + n);
			for (size_t i = 0; i < n; i++)
				insert(begin() + pos, val);
		};
		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last) {
			difference_type range = last - first;
			difference_type pos = position - begin();

			if (_cap < _size + range && _size * 2 >= _size + range)
				reserve(_size * 2);
			else if (_cap < _size + range && _size * 2 < _size + range)
				reserve(_size + range);
			while (first != last)
			{
				insert(begin() + pos, *first);
				pos++;
				first++;
			}
		};
		iterator	erase(iterator position) {
			for (iterator it = position; it != end() - 1; it++)
				*it = *(it + 1);
			_size--;
			_alloc.destroy(&_vec[_size]);
			return (position);
		};
		iterator	erase(iterator first, iterator last) {
			difference_type range = last - first;
			for (iterator it = first; it != end() - range; it++)
				*it = *(it + range);
			_size -= range;
			for (difference_type i = 0; i < range; i++)
				_alloc.destroy(&_vec[_size + i]);
			return (first);
		};
		void		swap(vector &x) {
			value_type	*tmp;
			size_type	tmpsize = _size;
			size_type	tmpcap = _cap;

			tmp = x._vec;
			x._vec = _vec;
			_vec = tmp;
			tmpsize = x._size;
			x._size = _size;
			_size = tmpsize;
			tmpcap = x._cap;
			x._cap = _cap;
			_cap = tmpcap;
		};
		void		clear() {
			_size = 0;
		};

		private:
		value_type		*_vec;
		size_type		_size;
		size_type		_cap;
		allocator_type	_alloc;
	};

	/* Non-member function overloads */
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return (false);
		return (true);
	};
	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(lhs == rhs));
	};
	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		for (size_t i = 0, j = 0; i < lhs.size() && j < rhs.size(); i++, j++)
			if (lhs[i] < rhs[j])
				return (true);
			else if (lhs[i] > rhs[j])
				return (false);
		if (lhs.size() >= rhs.size())
			return (false);
		return (true);
	};
	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(rhs < lhs));
	};
	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (rhs < lhs);
	};
	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs) {
		return (!(lhs < rhs));
	};
	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &x, vector<T, Alloc> &y) {
		x.swap(y);
	};
};

#endif
