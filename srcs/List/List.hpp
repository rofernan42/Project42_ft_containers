#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include <memory>
# include "BidirectionalIterator.hpp"

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
		list();
		list(size_type n, const value_type &val = value_type());
		list(iterator first, iterator last);
		list(const list &x);
		~list();
		list	&operator=(const list &x);

		/* Iterators */
		iterator				begin() {
			return (iterator(_list));
		};
		const_iterator			begin() const {
			return (const_iterator(_list));
		};
		iterator				end() {
			return (iterator(_list + _size));
		};
		const_iterator			end() const {
			return (const_iterator(_list + _size));
		};
		reverse_iterator		rbegin() {
			return (reverse_iterator(_list + _size - 1));
		};
		const_reverse_iterator	rbegin() const {
			return (reverse_iterator(_list + _size - 1));
		};
		reverse_iterator		rend() {
			return (reverse_iterator(_list - 1));
		};
		const_reverse_iterator	rend() const {
			return (const_reverse_iterator(_list - 1));
		};

		private:
		value_type		*_list;
		size_type		_size;
		allocator_type	_alloc;
	};
};

#endif