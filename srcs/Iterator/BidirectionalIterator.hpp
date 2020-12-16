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

		Elem	*nxt() {
			return (this->next);
		};
		Elem	*pvs() {
			return (this->prev);
		};
	};

	template <class Pair, class Key>
	struct nodeBT
	{
		Pair	data;
		nodeBT	*parent;
		nodeBT	*left;
		nodeBT	*right;

		nodeBT() {
			parent = nullptr;
			left = nullptr;
			right = nullptr;
		};

		nodeBT	*search(nodeBT *root, Key key) {
			if (root == NULL || root->data.first == key)
				return (root);
			if (root->data.first < key)
				return (search(root->right, key));
			return (search(root->left, key));
		};
		nodeBT	*nxt() {
			nodeBT *tmp;
			if (this->right)
			{
				tmp = this->right;
				while (tmp->left)
					tmp = tmp->left;
			}
			else
			{
				tmp = this;
				while (tmp->parent && tmp == tmp->parent->right)
					tmp = tmp->parent;
				if (tmp->parent)
					tmp = tmp->parent;
			}
			return (tmp);
		};
		nodeBT	*pvs() {
			nodeBT *tmp;
			if (this->left)
			{
				tmp = this->left;
				while (tmp->right)
					tmp = tmp->right;
			}
			else
			{
				tmp = this;
				while (tmp->parent && tmp == tmp->parent->left)
					tmp = tmp->parent;
				if (tmp->parent)
					tmp = tmp->parent;
			}
			return (tmp);
		};
	};

	template <class T, class P>
	class BidirectionalIterator
	{
		public:
		typedef BidirectionalIterator iterator;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef P pointer_Elem;
		typedef bidirectional_iterator_tag iterator_category;
		typedef size_t size_type;

		BidirectionalIterator() {
			_ptr = nullptr;
		};
		BidirectionalIterator(pointer_Elem ptr) {
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
			&& _ptr->pvs() == x._ptr->pvs() \
			&& _ptr->nxt() == x._ptr->nxt());
		};
		bool	operator!=(const iterator &x) const {
			return (!(_ptr->data == x._ptr->data \
			&& _ptr->pvs() == x._ptr->pvs() \
			&& _ptr->nxt() == x._ptr->nxt()));
		};

		reference	operator*() const {
			return (_ptr->data);
		};
		pointer		operator->() const {
			return (&(operator*()));
		};

		iterator	&operator++() {
			if (_ptr && _ptr->nxt())
				_ptr = _ptr->nxt();
			return (*this);
		};
		iterator	operator++(int) {
			iterator temp(*this);
			operator++();
			return (temp);
		};
		iterator	&operator--() {
			if (_ptr && _ptr->pvs())
				_ptr = _ptr->pvs();
			return (*this);
		};
		iterator	operator--(int) {
			iterator temp(*this);
			operator--();
			return (temp);
		};

		private:
		pointer_Elem	_ptr;
	};

	template <class T, class P>
	class ReverseBidirectional
	{
		public:
		typedef ReverseBidirectional iterator;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef P pointer_Elem;
		typedef size_t size_type;

		ReverseBidirectional() {
			_ptr = nullptr;
		};
		ReverseBidirectional(pointer_Elem ptr) {
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
			&& _ptr->pvs() == x._ptr->pvs() \
			&& _ptr->nxt() == x._ptr->nxt());
		};
		bool	operator!=(const iterator &x) const {
			return (!(_ptr->data == x._ptr->data \
			&& _ptr->pvs() == x._ptr->pvs() \
			&& _ptr->nxt() == x._ptr->nxt()));
		};

		reference	operator*() const {
			return (_ptr->data);
		};
		pointer		operator->() const {
			return (&(operator*()));
		};

		iterator	&operator++() {
			if (_ptr && _ptr->pvs())
				_ptr = _ptr->pvs();
			return (*this);
		};
		iterator	operator++(int) {
			iterator temp(*this);
			operator++();
			return (temp);
		};
		iterator	&operator--() {
			if (_ptr && _ptr->nxt())
				_ptr = _ptr->nxt();
			return (*this);
		};
		iterator	operator--(int) {
			iterator temp(*this);
			operator--();
			return (temp);
		};

		private:
		pointer_Elem	_ptr;
	};
};

#endif
