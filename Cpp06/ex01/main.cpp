#include "Data.hpp"
#include <cstdint>
#include <iostream>

uintptr_t	serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw){
	return	reinterpret_cast<Data *>(raw);
}

int	main(void){
	Data			*d = new Data();
	uintptr_t		raw;
	Data			*spec;

	d->c = 'a';
	d->i = 12345;
	d->f = 666.666f;
	d->d = 23232.444;

	std::cout << "Assigning values..." << std::endl;
	std::cout << "Char = " << d->c << std::endl;
	std::cout << "Integer = " << d->i << std::endl;
	std::cout << "Floating = " << d->f << std::endl;
	std::cout << "Double = " << d->d << std::endl;

	std::cout << std::endl;

	raw = serialize(d);
	std::cout << "Serialization done." << std::endl;
	std::cout << "Raw data: 0x" << std::hex << raw << std::endl;
	std::cout << "Data pointer: " << std::hex << d << std::endl;

	std::cout << std::endl;

	spec = deserialize(raw);
	std::cout << "DeSerialization done." << std::endl;
	std::cout << "Char = " << spec->c << std::endl;
	std::cout << "Integer = " << spec->i << std::endl;
	std::cout << "Floating = " << spec->f << std::endl;
	std::cout << "Double = " << spec->d << std::endl;

	std::cout << std::endl;

	std::cout << "Is d equal to spec? " << (d == spec ? "yes!" : "no...")
		<< std::endl;
	std::cout << "d = " << std::hex << d << std::endl;
	std::cout << "spec = " << std::hex << spec << std::endl;
}
