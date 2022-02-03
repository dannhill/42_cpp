#include "Span.hpp"

Span::Span(unsigned int N) : _N(N){
	_index = 0;
}

Span::Span(Span const & cpy) : _N(cpy._N){
	_vect = cpy._vect;
	_index = cpy._index;
	return;
}

Span::~Span(void){
	return;
}

void	Span::addNumber(int v){
	if (_index >= _N)
		throw OutOfBoundException();
	_vect.push_back(v);
	++_index;
	return;
}

unsigned int	Span::shortestSpan(void) const{
	if (_index <= 1)
		throw NonExistentSpanException();
	std::vector<int>	srtd(_vect);
	int		min(abs(_vect[0] - _vect[1]));

	std::sort(srtd.begin(), srtd.end());
	for (unsigned int i(0); i < _N; i++)
		if (abs(srtd[i] - srtd[i + 1]) <= min)
			min = abs(srtd[i] - srtd[i + 1]);
	return static_cast<unsigned int>(min);
}

unsigned int	Span::longestSpan(void) const{
	if (_index <= 1)
		throw NonExistentSpanException();
	return *std::max_element(_vect.begin(), _vect.end()) -
		*std::min_element(_vect.begin(), _vect.end());
}

Span &	Span::operator=(Span const & asn){
	_vect = asn._vect;
	_index = asn._index;

	unsigned int	*p = const_cast<unsigned int *>(&_N);
	*p = asn._N;

	return *this;
}

Span::Span(void) : _N(0){
	return;
}
