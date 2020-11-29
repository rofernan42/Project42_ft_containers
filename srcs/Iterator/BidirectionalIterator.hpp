/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:10:29 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/27 17:10:33 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

# include <cstddef>

namespace ft
{
	struct bidirectional_iterator_tag {};

	template <class T>
	class BidirectionalIterator
	{
		public:
		typedef BidirectionalIterator iterator;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef bidirectional_iterator_tag iterator_category;
		typedef size_t size_type;

		BidirectionalIterator() {
			_ptr = nullptr;
		};
		BidirectionalIterator(pointer ptr) {
			_ptr = ptr;
		};
		BidirectionalIterator(const iterator &x) {
			_ptr = x._ptr;
		};
		~BidirectionalIterator() {};
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

		private:
		pointer _ptr;
	};

	template <class T>
	class ReverseBidirectional
	{
		public:
		typedef ReverseBidirectional iterator;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef size_t size_type;

		ReverseIterator() {
			_ptr = nullptr;
		};
		ReverseIterator(pointer ptr) {
			_ptr = ptr;
		};
		ReverseIterator(const iterator &x) {
			_ptr = x._ptr;
		};
		~ReverseIterator() {};

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
