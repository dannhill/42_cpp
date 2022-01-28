#pragma once
#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>{
	public:
		class iterator : public std::iterator{};

		iterator &	begin(void) const{
			return iterator(&this->c[0]);
		}
		iterator &	end(void) const;
};
