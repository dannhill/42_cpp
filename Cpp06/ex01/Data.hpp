#pragma once
#include <cstdint>

class Data{
	public:
		char	c;
		int		i;
		float	f;
		double	d;
};

uintptr_t	serialize(Data *ptr);

Data	*deserialize(uintptr_t raw);
