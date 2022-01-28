#include "Span.hpp"

Span::Span(unsigned int N) : _N(N){
	_index = 0;
}

Span::~Span(void){
	return;
}

void	Span::addNumber(int v){
	try{
		if (_index >= _N)
			throw OutOfBoundException();
		_vect.push_back(v);
		++_index;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}

unsigned int	Span::shortestSpan(void) const{
	std::vector<int>	srtd(_vect);
	int		min(abs(_vect[0] - _vect[1]));

	std::sort(srtd.begin(), srtd.end());
	for (unsigned int i(0); i < _N; i++)
		if (abs(srtd[i] - srtd[i + 1]) <= min)
			min = abs(srtd[i] - srtd[i + 1]);
	return static_cast<unsigned int>(min);
}

unsigned int	Span::longestSpan(void) const{
	return *std::max_element(_vect.begin(), _vect.end()) -
		*std::min_element(_vect.begin(), _vect.end());
}

Span::Span(void) : _N(0){
	return;
}
