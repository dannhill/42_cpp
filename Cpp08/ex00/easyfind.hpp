#pragma once
#include <stdexcept>
#include <iostream>

template <typename T>
int &	easyfind(T & cont, int n){
	typename T::iterator	s(cont.begin());
	typename T::iterator	e(cont.end());

	for (; s != e; s++)
		if (*s == n)
			break;
	try{
		if (s == e)
			throw std::exception();
		return *s;
	}
	catch (std::exception & e){
		std::cerr << "Value not found." << std::endl;
		return *(new int(-1));
	}
}
