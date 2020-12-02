/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:19:37 by rofernan          #+#    #+#             */
/*   Updated: 2020/11/29 14:19:40 by rofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../List/List.hpp"

namespace ft
{
	template <class T, class Container = list<T>>
	class queue
	{
        public:
        typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

        /* Member functions */
        queue(const container_type &ctnr = container_type()) {
            _ctnr = ctnr;
        };
        ~queue() {};

        bool	empty() const {
			if (_ctnr.size() == 0)
				return (true);
			return (false);
		};
		size_type	size() const {
			return (_ctnr.size());
		};
		value_type	&front() {
			return (_ctnr.front());
		};
		const value_type	&front() const {
			return (_ctnr.front());
		};
        value_type	&back() {
			return (_ctnr.back());
		};
		const value_type	&back() const {
			return (_ctnr.back());
		};
		void	push(const value_type &val) {
			_ctnr.push_back(val);
		};
		void	pop() {
			_ctnr.pop_front();
		};

        private:
        container_type  _ctnr;
    };

    /* Non-member function overloads */
	template <class T, class Container>
	bool	operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs == rhs);
	};
	template <class T, class Container>
	bool	operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs != rhs);
	};
	template <class T, class Container>
	bool	operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs < rhs);
	};
	template <class T, class Container>
	bool	operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs <= rhs);
	};
	template <class T, class Container>
	bool	operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs > rhs);
	};
	template <class T, class Container>
	bool	operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs >= rhs);
	};
	template <class T, class Container>
	void	swap(queue<T, Container> &x, queue<T, Container> &y) {
		x.swap(y);
	};
};

#endif
