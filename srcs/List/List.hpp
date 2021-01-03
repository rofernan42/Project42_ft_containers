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
# include <cstddef>
# include "../Iterator/BidirectionalIterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef BidirectionalIterator<value_type, Elem<value_type>*> iterator;
		typedef BidirectionalIterator<const value_type, Elem<value_type>*> const_iterator;
		typedef ReverseBidirectional<value_type, Elem<value_type>*> reverse_iterator;
		typedef ReverseBidirectional<const value_type, Elem<value_type>*> const_reverse_iterator;
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
		list(const list &x) {
			_init_list();
			assign(x.begin(), x.end());
		};
		~list() {
			clear();
			_alloc.deallocate(_head->data, 1);
			_alloc.deallocate(_tail->data, 1);
			delete _head;
			delete _tail;
		};
		list	&operator=(const list &x) {
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
			return (*_start->data);
		};
		const_reference	front() const {
			return (*_start->data);
		};
		reference		back() {
			return (*_end->data);
		};
		const_reference	back() const {
			return (*_end->data);
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
				_ptr = new Elem<value_type>;
				_ptr->data = _alloc.allocate(1);
				_alloc.construct(_ptr->data, val);
				_ptr->next = _tail;
				_start = _ptr;
				_end = _ptr;
				_tail->prev = _end;
			}
			else
			{
				_ptr = new Elem<value_type>;
				_ptr->data = _alloc.allocate(1);
				_alloc.construct(_ptr->data, val);
				_ptr->next = _start;
				_start->prev = _ptr;
				_start = _ptr;
			}
			_start->prev = _head;
			_head->next = _start;
			_size++;
		};
		void		pop_front() {
			if (_size == 0)
				return ;
			Elem<value_type>	*tmp;
			tmp = _start;
			_start->next->prev = _head;
			_head->next = _start->next;
			_start = _start->next;
			_alloc.deallocate(tmp->data, 1);
			delete tmp;
			_size--;
		};
		void		push_back(const value_type &val) {
			if (empty())
			{
				_ptr = new Elem<value_type>;
				_ptr->data = _alloc.allocate(1);
				_alloc.construct(_ptr->data, val);
				_ptr->prev = _head;
				_start = _ptr;
				_end = _ptr;
				_head->next = _start;
			}
			else
			{
				_ptr = new Elem<value_type>;
				_ptr->data = _alloc.allocate(1);
				_alloc.construct(_ptr->data, val);
				_ptr->prev = _end;
				_end->next = _ptr;
				_end = _ptr;
			}
			_end->next = _tail;
			_tail->prev = _end;
			_size++;
		};
		void		pop_back() {
			if (_size == 0)
				return ;
			if (_size == 1)
			{
				pop_front();
				return ;
			}
			Elem<value_type>	*tmp;
			tmp = _end;
			_end->prev->next = _tail;
			_tail->prev = _end->prev;
			_end = _end->prev;
			_alloc.deallocate(tmp->data, 1);
			delete tmp;
			_size--;
		};
		iterator	insert(iterator position, const value_type &val) {
			if (position == begin())
			{
				push_front(val);
				return (begin());
			}
			Elem<value_type>	*tmp = new Elem<value_type>;
			iterator			it = begin();
			_ptr = _start;
			while (it != position)
			{
				it++;
				_ptr = _ptr->next;
			}
			tmp->data = _alloc.allocate(1);
			_alloc.construct(tmp->data, val);
			tmp->prev = _ptr->prev;
			tmp->next = _ptr;
			tmp->prev->next = tmp;
			_ptr->prev = tmp;
			if (position == end())
				_end = tmp;
			_size++;
			return (iterator(tmp));
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
			_ptr = tmp->next;
			_alloc.deallocate(tmp->data, 1);
			delete tmp;
			_size--;
			return (iterator(_ptr));
		};
		iterator	erase(iterator first, iterator last) {
			iterator tmp;
			while (first != last)
			{
				tmp = first;
				first++;
				erase(tmp);
			}
			return (last);
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
			erase(begin(), end());
		};

		/* Operations */
		void	splice(iterator position, list &x) {
			splice(position, x, x.begin(), x.end());
		};
		void	splice(iterator position, list &x, iterator i) {
			insert(position, *i);
			x.erase(i);
		};
		void	splice(iterator position, list &x, iterator first, iterator last) {
			insert(position, first, last);
			x.erase(first, last);
		};
		void	remove(const value_type &val) {
			iterator it = begin();
			while (it != end())
			{
				if (*it == val)
					it = erase(it);
				else
					it++;
			}
		};
		template <class Predicate>
		void	remove_if(Predicate pred) {
			iterator it = begin();
			while (it != end())
			{
				if (pred(*it))
					it = erase(it);
				else
					it++;
			}
		};
		void	unique() {
			iterator it = begin();
			iterator tmp = begin();
			tmp++;
			while (it != end() && tmp != end())
			{
				if (*tmp == *it)
					tmp = erase(tmp);
				else
				{
					tmp++;
					it++;
				}
			}
		};
		template <class BinaryPredicate>
		void	unique(BinaryPredicate binary_pred) {
			iterator it = begin();
			iterator tmp = begin();
			tmp++;
			while (it != end() && tmp != end())
			{
				if (binary_pred(*tmp, *it))
					tmp = erase(tmp);
				else
				{
					tmp++;
					it++;
				}
			}
		};
		void	merge(list &x) {
			if (this == &x)
				return ;
			int n = 0;
			if (_is_sorted() && x._is_sorted())
				n = 1;
			_end->next = x._start;
			x._start->prev = _end;
			x._end->next = _tail;
			_tail->prev = x._end;
			_end = x._end;
			_size += x._size;
			x._size = 0;
			x._start = x._tail;
			x._end = x._head;
			if (n == 1)
				sort();
		};
		template <class Compare>
		void	merge(list &x, Compare comp) {
			if (this == &x)
				return ;
			int n = 0;
			if (_is_sorted(comp) && x._is_sorted(comp))
				n = 1;
			_end->next = x._start;
			x._start->prev = _end;
			x._end->next = _tail;
			_tail->prev = x._end;
			_end = x._end;
			_size += x._size;
			x._size = 0;
			x._start = x._tail;
			x._end = x._head;
			if (n == 1)
				sort(comp);
		};
		void	sort() {
			value_type tmp;
			_ptr = _start;
			for (size_t i = 0; i < _size; i++)
			{
				_ptr = _ptr->next;
				if (*_ptr->prev->data > *_ptr->data)
				{
					tmp = *_ptr->data;
					_alloc.destroy(_ptr->data);
					_alloc.construct(_ptr->data, *_ptr->prev->data);
					_alloc.destroy(_ptr->prev->data);
					_alloc.construct(_ptr->prev->data, tmp);
					i = 0;
					_ptr = _start;
				}
			}
		};
		template <class Compare>
		void	sort(Compare comp) {
			value_type tmp;
			_ptr = _start;
			for (size_t i = 0; i < _size; i++)
			{
				_ptr = _ptr->next;
				if (comp(*_ptr->data, *_ptr->prev->data))
				{
					tmp = *_ptr->data;
					_alloc.destroy(_ptr->data);
					_alloc.construct(_ptr->data, *_ptr->prev->data);
					_alloc.destroy(_ptr->prev->data);
					_alloc.construct(_ptr->prev->data, tmp);
					i = 0;
					_ptr = _start;
				}
			}
		};
		void	reverse() {
			iterator it = begin();
			for (size_t i = 0; i < _size - 1; i++)
				splice(it, *this, iterator(_end));
		};

		private:
		Elem<value_type>	*_head;
		Elem<value_type>	*_start;
		Elem<value_type>	*_end;
		Elem<value_type>	*_tail;
		Elem<value_type>	*_ptr;
		size_type			_size;
		allocator_type		_alloc;

		void	_init_list() {
			_head = new Elem<value_type>;
			_head->data = _alloc.allocate(1);
			_alloc.construct(_head->data, value_type());
			_head->prev = NULL;
			_tail = new Elem<value_type>;
			_tail->data = _alloc.allocate(1);
			_alloc.construct(_tail->data, value_type());
			_tail->next = NULL;
			_start = _tail;
			_end = _head;
			_size = 0;
		};
		bool	_is_sorted() {
			iterator it = begin();
			iterator it2 = begin();
			it2++;
			while (it != end() && it2 != end())
			{
				if (*it > *it2)
					return (false);
				it++;
				it2++;
			}
			return (true);
		};
		template <class Compare>
		bool	_is_sorted(Compare comp) {
			iterator it = begin();
			iterator it2 = begin();
			it2++;
			while (it != end() && it2 != end())
			{
				if (comp(*it2, *it))
					return (false);
				it++;
				it2++;
			}
			return (true);
		};
	};

	/* Non-member function overloads */
	template <class T, class Alloc>
	bool	operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename list<T>::const_iterator itl = lhs.begin();
		typename list<T>::const_iterator itr = rhs.begin();
		while (itl != lhs.end() && itr != rhs.end())
		{
			if (*itl != *itr)
				return (false);
			itl++;
			itr++;
		}
		return (true);
	};
	template <class T, class Alloc>
	bool	operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		return (!(lhs == rhs));
	};
	template <class T, class Alloc>
	bool	operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		typename list<T>::const_iterator itl = lhs.begin();
		typename list<T>::const_iterator itr = rhs.begin();
		while (itl != lhs.end() && itr != rhs.end())
		{
			if (*itl < *itr)
				return (true);
			else if (*itl > *itr)
				return (false);
			itl++;
			itr++;
		}
		if (lhs.size() >= rhs.size())
			return (false);
		return (true);
	};
	template <class T, class Alloc>
	bool	operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		return (!(rhs < lhs));
	};
	template <class T, class Alloc>
	bool	operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		return (rhs < lhs);
	};
	template <class T, class Alloc>
	bool	operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs) {
		return (!(lhs < rhs));
	};
	template <class T, class Alloc>
	void	swap (const list<T, Alloc> &x, const list<T, Alloc> &y) {
		x.swap(y);
	};
};

#endif
