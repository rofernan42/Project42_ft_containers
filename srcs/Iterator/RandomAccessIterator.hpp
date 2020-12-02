/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:10:29 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/29 14:19:09 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <cstddef>

namespace ft
{
	struct random_access_iterator_tag {};
	struct bidirectional_iterator_tag {};

	template <class T>
	class RandomAccessIterator
	{
		public:
		typedef RandomAccessIterator iterator;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag iterator_category;
		typedef size_t size_type;

		RandomAccessIterator() {
			_ptr = nullptr;
		};
		RandomAccessIterator(pointer ptr) {
			_ptr = ptr;
		};
		RandomAccessIterator(const iterator &x) {
			_ptr = x._ptr;
		};
		~RandomAccessIterator() {};
		iterator	&operator=(const iterator &x) {
			_ptr = x._ptr;
			return (*this);
		};

		bool	operator==(const iterator &x) const {
			return (_ptr == x._ptr);
		};
		bool	operator!=(const iterator &x) const {
			return (_ptr != x._ptr);
		};

		reference	operator*() const {
			return (*_ptr);
		};
		pointer		operator->() const {
			return (&(operator*()));
		};

		iterator	&operator++() {
			_ptr++;
			return (*this);
		};
		iterator	operator++(int) {
			iterator temp(*this);
			_ptr++;
			return (temp);
		};
		iterator	&operator--() {
			_ptr--;
			return (*this);
		};
		iterator	operator--(int) {
			iterator temp(*this);
			_ptr--;
			return (temp);
		};

		iterator		operator+(difference_type n) {
			iterator temp(*this);
			temp._ptr += n;
			return (temp);
		};
		difference_type	operator+(iterator x) {
			return (_ptr + x._ptr);
		}
		iterator		operator-(difference_type n) {
			iterator temp(*this);
			temp._ptr -= n;
			return (temp);
		};
		difference_type	operator-(iterator x) {
			return (_ptr - x._ptr);
		}

		bool	operator<(const iterator &x) const {
			return (_ptr < x._ptr);
		};
		bool	operator>(const iterator &x) const {
			return (_ptr > x._ptr);
		};
		bool	operator<=(const iterator &x) const {
			return (_ptr <= x._ptr);
		};
		bool	operator>=(const iterator &x) const {
			return (_ptr >= x._ptr);
		};

		iterator	&operator+=(difference_type n) {
			_ptr += n;
			return (*this);
		}
		iterator	&operator-=(difference_type n) {
			_ptr -= n;
			return (*this);
		};

		reference	operator[](size_type n) const {
			return (*(_ptr + n));
		};

		private:
		pointer _ptr;
	};

	template <class T>
	class ReverseRandomAccess
	{
		public:
		typedef ReverseRandomAccess iterator;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef random_access_iterator_tag iterator_category;
		typedef size_t size_type;

		ReverseRandomAccess() {
			_ptr = nullptr;
		};
		ReverseRandomAccess(pointer ptr) {
			_ptr = ptr;
		};
		ReverseRandomAccess(const iterator &x) {
			_ptr = x._ptr;
		};
		~ReverseRandomAccess() {};

		iterator	&operator=(const iterator &x) {
			_ptr = x._ptr;
			return (*this);
		};

		bool	operator==(const iterator &x) const {
			return (_ptr == x._ptr);
		};
		bool	operator!=(const iterator &x) const {
			return (_ptr != x._ptr);
		};

		reference	operator*() const {
			return (*_ptr);
		};
		pointer		operator->() const {
			return (&(operator*()));
		};

		iterator	&operator++() {
			_ptr--;
			return (*this);
		};
		iterator	operator++(int) {
			iterator temp(*this);
			_ptr--;
			return (temp);
		};
		iterator	&operator--() {
			_ptr++;
			return (*this);
		};
		iterator	operator--(int) {
			iterator temp(*this);
			_ptr++;
			return (temp);
		};

		iterator		operator+(difference_type x) {
			iterator temp(*this);
			temp._ptr -= x;
			return (temp);
		};
		difference_type	operator+(iterator x) {
			return (_ptr - x._ptr);
		}
		iterator		operator-(difference_type x) {
			iterator temp(*this);
			temp._ptr += x;
			return (temp);
		};
		difference_type	operator-(iterator x) {
			return (_ptr + x._ptr);
		}

		bool	operator<(const iterator &x) const {
			return (_ptr < x._ptr);
		};
		bool	operator>(const iterator &x) const {
			return (_ptr > x._ptr);
		};
		bool	operator<=(const iterator &x) const {
			return (_ptr <= x._ptr);
		};
		bool	operator>=(const iterator &x) const {
			return (_ptr >= x._ptr);
		};

		iterator	&operator+=(difference_type x) {
			_ptr -= x;
			return (*this);
		}
		iterator	&operator-=(difference_type x) {
			_ptr += x;
			return (*this);
		};

		reference	operator[](size_type n) const {
			return (*(_ptr + n));
		};

		private:
		pointer _ptr;
	};
};

#endif
