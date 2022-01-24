#include "Converter.hpp"

int	main(int c, char** v){
	if (c != 2)
	{
		std::cerr << "Error: invalid number of arguments (accepted: 1)"
			<< std::endl;
		return 1;
	}

	Converter	con(v[1]);

	con.detectConvert();

	return 0;
}
