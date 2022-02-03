#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Span{
	public:
		Span(unsigned int N);
		Span(Span const & cpy);
		virtual	~Span(void);

		void	addNumber(int v);
		template <typename T>
		void	addNumber(T beg, T end){
			if (std::distance(beg, end) > _N)
				throw RangeTooBigException();
			for (; beg != end; beg++, _index++)
				_vect.push_back(*beg);
		}

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		Span &	operator=(Span const & asn);

		class OutOfBoundException : public std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "Span is full. Value discarded.";
				}
		};

		class NonExistentSpanException : public std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "At least 2 elements needed to find span.";
				}
		};

		class RangeTooBigException : public std::exception{
			public:
				virtual const char	*what(void) const throw(){
					return "Range bigger than span max size";
				}
		};
	private:
		std::vector<int>		_vect;
		unsigned int	_index;
		const unsigned int	_N;

		Span(void);
};
