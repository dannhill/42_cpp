#pragma once
#include <cstdint>

//typedef unsigned long uintptr_t;
//definizione alternativa, nel caso non si voglia usare c++11, e quindi l'header <cstdint>

class Data{
	public:
		char	c;
		int		i;
		float	f;
		double	d;
};

uintptr_t	serialize(Data *ptr);

Data	*deserialize(uintptr_t raw);
