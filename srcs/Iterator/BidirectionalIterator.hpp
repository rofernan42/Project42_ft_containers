/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:10:29 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/29 14:19:03 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

# include <cstddef>

namespace ft
{
	struct bidirectional_iterator_tag {};

	template <class T>
	struct Elem
	{
		Elem	*prev;
		T		data;
		Elem	*next;
	};

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
		BidirectionalIterator(Elem<value_type> *ptr) {
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
			return (_ptr->data == x._ptr->data \
			&& _ptr->prev == x._ptr->prev \
			&& _ptr->next == x._ptr->next);
		};
		bool	operator!=(const iterator &x) const {
			return (!(_ptr->data == x._ptr->data \
			&& _ptr->prev == x._ptr->prev \
			&& _ptr->next == x._ptr->next));
		};

		reference	operator*() const {
			return (_ptr->data);
		};
		pointer		operator->() const {
			return (&(operator*()));
		};

		iterator	&operator++() {
			if (_ptr && _ptr->next)
				_ptr = _ptr->next;
			return (*this);
		};
		iterator	operator++(int) {
			iterator temp(*this);
			operator++();
			return (temp);
		};
		iterator	&operator--() {
			if (_ptr && _ptr->prev)
				_ptr = _ptr->prev;
			return (*this);
		};
		iterator	operator--(int) {
			iterator temp(*this);
			operator--();
			return (temp);
		};

		private:
		Elem<value_type>	*_ptr;
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

		ReverseBidirectional() {
			_ptr = nullptr;
		};
		ReverseBidirectional(pointer ptr) {
			_ptr = ptr;
		};
		ReverseBidirectional(const iterator &x) {
			_ptr = x._ptr;
		};
		~ReverseBidirectional() {};

		iterator	&operator=(const iterator &x) {
			_ptr = x._ptr;
			return (*this);
		};

		bool	operator==(const iterator &x) const {
			return (_ptr->data == x._ptr->data \
			&& _ptr->prev == x._ptr->prev \
			&& _ptr->next == x._ptr->next);
		};
		bool	operator!=(const iterator &x) const {
			return (!(_ptr->data == x._ptr->data \
			&& _ptr->prev == x._ptr->prev \
			&& _ptr->next == x._ptr->next));
		};

		reference	operator*() const {
			return (_ptr->data);
		};
		pointer		operator->() const {
			return (&(operator*()));
		};

		iterator	&operator++() {
			if (_ptr && _ptr->prev)
				_ptr = _ptr->prev;
			return (*this);
		};
		iterator	operator++(int) {
			iterator temp(*this);
			operator++();
			return (temp);
		};
		iterator	&operator--() {
			if (_ptr && _ptr->next)
				_ptr = _ptr->next;
			return (*this);
		};
		iterator	operator--(int) {
			iterator temp(*this);
			operator--();
			return (temp);
		};

		private:
		Elem<value_type>	*_ptr;
	};
};

#endif
