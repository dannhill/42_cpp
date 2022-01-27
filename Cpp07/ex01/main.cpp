#include "iter.hpp"
#include <iostream>

template <typename T>
void	func(T & value){
	std::cout << value << std::endl;
}

int	main(void){
	char	arr[20] = "Hello this is hell!";

	iter(arr, 25, &func);
}
