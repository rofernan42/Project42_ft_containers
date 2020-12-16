/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:19:26 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/29 14:19:29 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <limits>
# include <memory>
# include <utility>
# include <cstddef>
# include "../Iterator/BidirectionalIterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T>>>
	class map
	{
		public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef nodeBT<std::pair<Key, T>, Key> node;
		typedef BidirectionalIterator<std::pair<Key, T>, node*> iterator;
		typedef BidirectionalIterator<const std::pair<Key, T>, node*> const_iterator;
		typedef ReverseBidirectional<std::pair<Key, T>, node*> reverse_iterator;
		typedef ReverseBidirectional<const std::pair<Key, T>, node*> const_reverse_iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		class value_compare
		{
			friend class map;

			protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {};

			public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool	operator()(const value_type &x, const value_type &y) const {
				return comp(x.first, y.first);
			};
		};

		/* Member functions */
		map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) {
			(void)alloc;
			_comp = comp;
			_init_map();
		};
		map(iterator first, iterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) {
			(void)alloc;
			_comp = comp;
			_init_map();
			insert(first, last);
		};
		map(const map &x) {
			_comp = x._comp;
			_init_map();
			if (!x.empty())
				insert(x.begin(), x.end());
		};
		~map() {
			clear();
			delete _min;
			delete _max;
			delete _root;
		};
		map &operator=(const map &x) {
			if (this != &x)
			{
				clear();
				_comp = x._comp;
				if (!x.empty())
					insert(x.begin(), x.end());
			}
			return (*this);
		};

		/* Iterators */
		iterator				begin() {
			return (_min->parent);
		};
		const_iterator			begin() const {
			return (_min->parent);
		};
		iterator				end() {
			return (_max);
		};
		const_iterator			end() const {
			return (_max);
		};
		reverse_iterator		rbegin() {
			return (_max->parent);
		};
		const_reverse_iterator	rbegin() const {
			return (_max->parent);
		};
		reverse_iterator		rend() {
			return (_min);
		};
		const_reverse_iterator	rend() const {
			return (_min);
		};

		/* Capacity */
		bool		empty() const {
			return (_size == 0);
		};
		size_type	size() const {
			return (_size);
		};
		size_type	max_size() const {
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		};

		/* Element access */
		mapped_type	&operator[](const key_type &k) {
			iterator it = find(k);
			if (it == end())
				it = insert(value_type(k, mapped_type())).first;
			return (it->second);
		};

		/* Modifiers */
		std::pair<iterator, bool>	insert(const value_type &val) {
			if (empty())
			{
				_root->data = val;
				_size++;
				return (std::make_pair(iterator(_root), true));
			}
			node *tmp = _root;
			while (tmp->left || tmp->right)
			{
				if (tmp->data.first == val.first)
					return (std::make_pair(iterator(tmp), false));
				if (value_comp()(tmp->data, val))
				{
					if (tmp->right && tmp->right != _max)
						tmp = tmp->right;
					else
						break ;
				}
				else
				{
					if (tmp->left && tmp->left != _min)
						tmp = tmp->left;
					else
						break ;
				}
			}
			if (value_comp()(tmp->data, val))
			{
				tmp->right = new node();
				tmp->right->parent = tmp;
				tmp->right->data = val;
				tmp = tmp->right;
			}
			else
			{
				tmp->left = new node();
				tmp->left->parent = tmp;
				tmp->left->data = val;
				tmp = tmp->left;
			}
			_set_min();
			_set_max();
			_size++;
			return (std::make_pair(iterator(tmp), true));
		};
		iterator					insert(iterator position, const value_type &val) {
			(void)position;
			return (insert(val).first);
		};
		void						insert(iterator first, iterator last) {
			while (first != last)
			{
				insert(*first);
				first++;
			}
		};
		void						insert(const_iterator first, const_iterator last) {
			while (first != last)
			{
				insert(*first);
				first++;
			}
		};
		void		erase(iterator position) {
			erase(position->first);
		};
		size_type	erase(const key_type &k) {
			node		*tmp;
			size_type	n = count(k);
			if (!(tmp = _root->search(_root, k)))
				return (0);
			if ((!tmp->left || tmp->left == _min) \
			&& (!tmp->right || tmp->right == _max))
			{
				if (tmp != _root)
				{
					if (value_comp()(tmp->data, tmp->parent->data))
						tmp->parent->left = nullptr;
					else
						tmp->parent->right = nullptr;
					delete tmp;
				}
				else
				{
					delete _root;
					_root = new node();
				}
			}
			else if ((!tmp->left || tmp->left == _min) \
			&& (tmp->right && tmp->right != _max))
			{
				if (tmp != _root)
				{
					if (value_comp()(tmp->data, tmp->parent->data))
						tmp->parent->left = tmp->right;
					else
						tmp->parent->right = tmp->right;
					tmp->right->parent = tmp->parent;
				}
				else
				{
					tmp->right->parent = nullptr;
					_root = tmp->right;
				}
				delete tmp;
			}
			else if ((tmp->left && tmp->left != _min) \
			&& (!tmp->right || tmp->right == _max))
			{
				if (tmp != _root)
				{
					if (value_comp()(tmp->data, tmp->parent->data))
						tmp->parent->left = tmp->left;
					else
						tmp->parent->right = tmp->left;
					tmp->left->parent = tmp->parent;
				}
				else
				{
					tmp->left->parent = nullptr;
					_root = tmp->left;
				}
				delete tmp;
			}
			else if ((tmp->left && tmp->left != _min) \
			&& (tmp->right && tmp->right != _max))
			{
				tmp->data = tmp->nxt()->data;
				tmp = tmp->nxt();
				if (value_comp()(tmp->data, tmp->parent->data))
					tmp->parent->left = nullptr;
				else
					tmp->parent->right = nullptr;
				delete tmp;
			}
			_size--;
			_set_min();
			_set_max();
			return (n);
		};
		void		erase(iterator first, iterator last) {
			iterator tmp;
			while (first != last)
			{
				tmp = first;
				first++;
				erase(tmp);
			}
		};
		void		swap(map &x) {
			map	tmp(x);
			x = *this;
			*this = tmp;
		};
		void		clear() {
			iterator it = begin();
			while (_min->parent != _root)
			{
				if (_min->parent->right)
				{
					_min->parent->right->parent = _min->parent->parent;
					_min->parent->parent->left = _min->parent->right;
				}
				else
					_min->parent->parent->left = nullptr;
				delete _min->parent;
				_set_min();
			}
			while (_max->parent != _root)
			{
				if (_max->parent->left)
				{
					_max->parent->left->parent = _max->parent->parent;
					_max->parent->parent->right = _max->parent->left;
				}
				else
					_max->parent->parent->right = nullptr;
				delete _max->parent;
				_set_max();
			}
			delete _min;
			delete _max;
			delete _root;
			_init_map();
		};

		/* Observers */
		key_compare		key_comp() const {
			return (_comp);
		};
		value_compare	value_comp() const {
			return (value_compare(_comp));
		};

		/* Operations */
		iterator		find(const key_type &k) {
			iterator it = begin();
			while (it != end())
			{
				if (it->first == k)
					return (it);
				it++;
			}
			return (it);
		};
		const_iterator	find(const key_type &k) const {
			const_iterator it = begin();
			while (it != end())
			{
				if (it->first == k)
					return (it);
				it++;
			}
			return (it);
		};
		size_type		count(const key_type &k) const {
			const_iterator	it = begin();
			size_type		n = 0;
			while (it != end())
			{
				if (it->first == k)
					n++;
				it++;
			}
			return (n);
		};
		iterator		lower_bound(const key_type &k) {
			iterator it = begin();
			while (it != end() && key_comp()(it->first, k))
				it++;
			return (it);
		};
		const_iterator	lower_bound(const key_type &k) const {
			const_iterator it = begin();
			while (it != end() && key_comp()(it->first, k))
				it++;
			return (it);
		};
		iterator		upper_bound(const key_type &k) {
			iterator it = begin();
			while (it != end())
			{
				if (key_comp()(k, it->first))
					return (it);
				it++;
			}
			return (it);
		};
		const_iterator	upper_bound(const key_type &k) const {
			const_iterator it = begin();
			while (it != end())
			{
				if (key_comp()(k, it->first))
					return (it);
				it++;
			}
			return (it);
		};
		std::pair<const_iterator, const_iterator>	equal_range(const key_type &k) const {
			std::pair<const_iterator, const_iterator> ret;
			ret.first = lower_bound(k);
			ret.second = upper_bound(k);
			return (ret);
		};
		std::pair<iterator, iterator>				equal_range(const key_type &k) {
			std::pair<iterator, iterator> ret;
			ret.first = lower_bound(k);
			ret.second = upper_bound(k);
			return (ret);
		};

		/* For tests purpose */
		void	print() {
			std::cout << "---------------------------\n";
			_printBT(_root);
			std::cout << "---------------------------\n";
		}

		private:
		key_compare	_comp;
		size_type	_size;
		node		*_root;
		node		*_max;
		node		*_min;
		node		*_ptr;

		void	_init_map() {
			_root = new node();
			_max = new node();
			_min = new node();
			_set_min();
			_set_max();
			_size = 0;
		};

		void	_set_min() {
			node *tmp = _root;
			while (tmp->left && tmp->left != _min)
				tmp = tmp->left;
			tmp->left = _min;
			_min->parent = tmp;
		};
		void	_set_max() {
			node *tmp = _root;
			while (tmp->right && tmp->right != _max)
				tmp = tmp->right;
			tmp->right = _max;
			_max->parent = tmp;
		};

		/* For tests purpose */
		void	_printBT(node *x, int n = 0) {
			if (x == NULL)
				return ;
			n = n + 4;
			_printBT(x->right, n);
			for (int i = 4; i < n; i++)
				std::cout << " ";
			if (x == _min)
				std::cout << "MIN\n";
			else if (x == _max)
				std::cout << "MAX\n";
			else
				std::cout << x->data.first << "\n";
			_printBT(x->left, n);
		};
	};

	/* Non-member function overloads */
	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc> &lhs, \
    const map<Key, T, Compare, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		typename map<Key, T>::const_iterator itl = lhs.begin();
		typename map<Key, T>::const_iterator itr = rhs.begin();
		while (itl != lhs.end() && itr != rhs.end())
		{
			if (*itl != *itr)
				return (false);
			itl++;
			itr++;
		}
		return (true);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc> &lhs, \
    const map<Key, T, Compare, Alloc> &rhs) {
		return (!(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc> &lhs, \
    const map<Key, T, Compare, Alloc> &rhs) {
		typename map<Key, T>::const_iterator itl = lhs.begin();
		typename map<Key, T>::const_iterator itr = rhs.begin();
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
	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc> &lhs, \
    const map<Key, T, Compare, Alloc> &rhs) {
		return (!(rhs < lhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc> &lhs, \
    const map<Key, T, Compare, Alloc> &rhs) {
		return (rhs < lhs);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc> &lhs, \
    const map<Key, T, Compare, Alloc> &rhs) {
		return (!(lhs < rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	void	swap(const map<Key, T, Compare, Alloc> &x, \
    const map<Key, T, Compare, Alloc> &y) {
		x.swap(y);
	};
};

#endif
