#pragma once
#include <deque>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T>{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack<T>(void) : std::stack<T>(){};
		virtual	~MutantStack<T>(void){};

		iterator	begin(void){
			return	this->c.begin();
		}
		iterator	end(void){
			return	this->c.end();
		}
};
