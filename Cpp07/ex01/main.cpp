#include "iter.hpp"
#include <iostream>

template <typename T>
void	func(T & value){
	std::cout << value << std::endl;
}

int	main(void){
	char	arr[20] = "Hello this is hell!";
	int		arr2[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	iter(arr, 25, &func);//valore maggiore della grandezza dell'array

	std::cout << std::endl;

	iter(arr2, 15, &func);
}
