// #include "Array.hpp"
// #include <iostream>

// int	main(void){
// 	Array<int>	kek(5);
// 	Array<int>	lel(kek);
// 	Array<int>	asd = kek;

// 	std::cout << kek[3] << std::endl;
// 	std::cout << kek[7] << std::endl;

// 	kek[0] = 22;
// 	kek[1] = 44;
// 	kek[2] = 42;
// 	kek[3] = 99;
// 	kek[4] = 666;

// 	for (int i = 0; i < 5; i++)
// 		std::cout << kek[i] << std::endl;

// 	std::cout << std::endl;

// 	std::cout << kek.size() << std::endl;

// 	Array<int>	haha(kek);

// 	kek[3] = 100000;

// 	std::cout << std::endl;

// 	for (int i = 0; i < 5; i++)
// 		std::cout << haha[i] << std::endl;

// 	return 0;
// }


#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}