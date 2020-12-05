/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:34:53 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/29 12:34:55 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../Vector/Vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T>>
	class stack
	{
		public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		/* Member functions */
		stack(const container_type &ctnr = container_type()) {
			_ctnr = ctnr;
		};
		~stack() {
			_ctnr.clear();
		};

		bool	empty() const {
			if (_ctnr.size() == 0)
				return (true);
			return (false);
		};
		size_type	size() const {
			return (_ctnr.size());
		};
		value_type	&top() {
			return (_ctnr.back());
		};
		const value_type	&top() const {
			return (_ctnr.back());
		};
		void	push(const value_type &val) {
			_ctnr.push_back(val);
		};
		void	pop() {
			_ctnr.pop_back();
		};

		private:
		container_type	_ctnr;
	};

	/* Non-member function overloads */
	template <class T, class Container>
	bool	operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs == rhs);
	};
	template <class T, class Container>
	bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs != rhs);
	};
	template <class T, class Container>
	bool	operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs < rhs);
	};
	template <class T, class Container>
	bool	operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs <= rhs);
	};
	template <class T, class Container>
	bool	operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs > rhs);
	};
	template <class T, class Container>
	bool	operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs >= rhs);
	};
	template <class T, class Container>
	void	swap(stack<T, Container> &x, stack<T, Container> &y) {
		x.swap(y);
	};
};

#endif
