/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:19:18 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/29 14:19:20 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include <memory>
# include "../Iterator/BidirectionalIterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T>>
	class list
	{
		public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef BidirectionalIterator<T> iterator;
		typedef BidirectionalIterator<const T> const_iterator;
		typedef ReverseBidirectional<T> reverse_iterator;
		typedef ReverseBidirectional<const T> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		/* Member functions */
		list() {
			_init_list();
		};
		list(size_type n, const value_type &val = value_type()) {
			_init_list();
			assign(n, val);
		};
		list(iterator first, iterator last) {
			_init_list();
			assign(first, last);
		};
		list(list &x) {
			_init_list();
			assign(x.begin(), x.end());
		};
		~list() {
			clear();
			delete _head;
			delete _tail;
		};
		list	&operator=(list &x) {
			if (this != &x)
				assign(x.begin(), x.end());
			return (*this);
		};

		/* Iterators */
		iterator				begin() {
			return (iterator(_start));
		};
		const_iterator			begin() const {
			return (const_iterator(_start));
		};
		iterator				end() {
			return (iterator(_tail));
		};
		const_iterator			end() const {
			return (const_iterator(_tail));
		};
		reverse_iterator		rbegin() {
			return (reverse_iterator(_end));
		};
		const_reverse_iterator	rbegin() const {
			return (const_reverse_iterator(_end));
		};
		reverse_iterator		rend() {
			return (reverse_iterator(_head));
		};
		const_reverse_iterator	rend() const {
			return (const_reverse_iterator(_head));
		};

		/* Capacity */
		bool		empty() const {
			if (_size == 0)
				return (true);
			return (false);
		};
		size_type	size() const {
			return (_size);
		};
		size_type	max_size() const {
			return (std::numeric_limits<size_type>::max() / sizeof(Elem<value_type>));
		};

		/* Element access */
		reference		front() {
			return (_start->data);
		};
		const_reference	front() const {
			return (_start->data);
		};
		reference		back() {
			return (_end->data);
		};
		const_reference	back() const {
			return (_end->data);
		};

		/* Modifiers */
  		void		assign(iterator first, iterator last) {
			if (!empty())
				clear();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		};
		void		assign(const_iterator first, const_iterator last) {
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
			for (size_t i = 0; i < n; i++)
				push_back(val);
		};
		void		push_front(const value_type &val) {
			if (empty())
			{
				_new = new Elem<value_type>;
				_new->data = val;
				_new->next = _end;
				_start = _new;
				_end = _new;
				_tail->prev = _end;
			}
			else
			{
				_new = new Elem<value_type>;
				_new->data = val;
				_new->next = _start;
				_start->prev = _new;
				_start = _new;
			}
			_start->prev = _head;
			_head->next = _start;
			_size++;
		};
		void		pop_front() {
			Elem<value_type>	*tmp;
			tmp = _start;
			_start->next->prev = _head;
			_head->next = _start->next;
			_start = _start->next;
			delete tmp;
			_size--;
		};
		void		push_back(const value_type &val) {
			if (empty())
			{
				_new = new Elem<value_type>;
				_new->data = val;
				_new->prev = _head;
				_start = _new;
				_end = _new;
				_head->next = _start;
			}
			else
			{
				_new = new Elem<value_type>;
				_new->data = val;
				_new->prev = _end;
				_end->next = _new;
				_end = _new;
			}
			_end->next = _tail;
			_tail->prev = _end;
			_size++;
		};
		void		pop_back() {
			Elem<value_type>	*tmp;
			tmp = _end;
			_end->prev->next = _tail;
			_tail->prev = _end->prev;
			_end = _end->prev;
			delete tmp;
			_size--;
		};
		iterator	insert(iterator position, const value_type &val) {
			Elem<value_type>	*tmp = new Elem<value_type>;
			iterator			it = begin();
			_new = _start;
			while (it != position)
			{
				it++;
				_new = _new->next;
			}
			tmp->data = val;
			tmp->prev = _new->prev;
			tmp->next = _new;
			_new->prev->next = tmp;
			_new->prev = tmp;
			return (--it);
		};
		void		insert(iterator position, size_type n, const value_type &val) {
			for (size_t i = 0; i < n; i++)
				insert(position, val);
		};
		void		insert(iterator position, iterator first, iterator last) {
			while (first != last)
			{
				insert(position, *first);
				first++;
			}
		};
		iterator	erase(iterator position) {
			if (position == begin())
			{
				pop_front();
				return (begin());
			}
			else if (position == --end())
			{
				pop_back();
				return (begin());
			}
			Elem<value_type>	*tmp;
			iterator			it = begin();
			tmp = _start;
			while (it != position)
			{
				it++;
				tmp = tmp->next;
				if (it == end())
					return (--it);
			}
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			delete tmp;
			_size--;
			return (++it);
		};
		iterator	erase(iterator first, iterator last) {
			while (first != last)
			{
				erase(first);
				first++;
			}
			return (first);
		};
		void		swap(list &x) {
			list	tmp(x);
			x = *this;
			*this = tmp;
		};
		void		resize(size_type n, value_type val = value_type()) {
			if (n < _size)
			{
				iterator it = begin();
				for (size_t i = 0; i < n; i++)
					it++;
				erase(it, end());
			}
			else if (n > _size)
				for (size_t i = _size; i < n; i++)
					push_back(val);
		};
		void		clear() {
			Elem<value_type> *tmp;
			while (_start != _tail)
			{
				tmp = _start;
				_start = _start->next;
				delete tmp;
			}
			_size = 0;
		};

		/* Operations */
		void	splice(iterator position, list &x);
		void	splice(iterator position, list &x, iterator i);
		void	splice(iterator position, list &x, iterator first, iterator last);
		void	remove(const value_type &val);
		template <class Predicate>
		void	remove_if(Predicate pred);
		void	unique();
		template <class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred);
		void	merge(list &x);
		template <class Compare>
		void	merge(list &x, Compare comp);
		void	sort();
		template <class Compare>
		void	sort(Compare comp);
		void	reverse();

		private:
		Elem<value_type>	*_head;
		Elem<value_type>	*_start;
		Elem<value_type>	*_end;
		Elem<value_type>	*_tail;
		Elem<value_type>	*_new;
		size_type			_size;
		allocator_type		_alloc;

		void	_init_list() {
			_head = new Elem<value_type>;
			_head->data = value_type();
			_head->prev = NULL;
			_tail = new Elem<value_type>;
			_tail->data = value_type();
			_tail->next = NULL;
			_start = _tail;
			_end = _head;
			_size = 0;
		};
	};
};

#endif
