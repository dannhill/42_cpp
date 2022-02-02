#pragma once
#include <stdexcept>
#include <iostream>

template <typename T>
class Array{
	public:
		Array<T>(void) : _len(0){
			_array = new T[0];
			return;
		}
		Array<T>(unsigned int n) : _len(n){
			_array = new T[n];
			for (unsigned int i(0); i < n; i++)//loop non necessario
				_array[i] = T();
			return;
		}
		Array<T>(const Array<T> & cpy){
			_len = cpy._len;
			_array = new T[_len];
			for (unsigned int i(0); i < _len; i++)
				_array[i] = cpy._array[i];
			return;
		}
		virtual	~Array<T>(void){
			delete []	_array;
		}
		Array<T> &	operator=(const Array<T> & asn){
			_len = asn._len;
			delete []	_array;
			_array = new T[_len];
			for (unsigned int i(0); i < _len; i++)
				_array[i] = asn._array[i];
			return;
		}
		T &	operator[](unsigned int i){
			if (i >= _len)
			{
				throw std::exception();
				return *(new T());
			}
			return _array[i];
		}
		unsigned int	size(void) const{
			return _len;
		}
	private:
		T				*_array;
		unsigned int	_len;
};
