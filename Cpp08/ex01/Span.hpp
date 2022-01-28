#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Span{
	public:
		Span(unsigned int N);
		virtual	~Span(void);

		void	addNumber(int v);

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
	private:
		std::vector<int>		_vect;
		unsigned int	_index;
		const unsigned int	_N;

		class OutOfBoundException : public std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "Span is full. Value discarded.";
				}
		};

		Span(void);
};
