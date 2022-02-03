#include "Span.hpp"
#include <iostream>

int	main(void){
	srand(time(NULL));

	//shortest span
	Span	naps(5);

	naps.addNumber(5);
	naps.addNumber(10);
	naps.addNumber(28);
	naps.addNumber(98);
	naps.addNumber(11);

	std::cout << std::endl;

	std::cout << "Shortest span: " << naps.shortestSpan() << std::endl;

		//rand
	
	Span	raps(7);

	std::cout << std::endl << "raps content:" << std::endl;

	for (int i(0), r(0); i < 7; i++)
	{
		r = rand() % 1000;
		std::cout << r << std::endl;
		raps.addNumber(r);
	}
	
	std::cout << "Shortest span(R): " << raps.shortestSpan() << std::endl;

	std::cout << std::endl;

	//longest span
	Span	nasp(10);

	nasp.addNumber(500);
	nasp.addNumber(600);
	nasp.addNumber(700);
	nasp.addNumber(0);
	nasp.addNumber(97);
	nasp.addNumber(1513);
	nasp.addNumber(7);
	nasp.addNumber(5);
	nasp.addNumber(424);
	nasp.addNumber(11);

	std::cout << "Longest span: " << nasp.longestSpan() << std::endl;

		//rand

	Span	rasp(7);

	std::cout << std::endl << "rasp content:" << std::endl;

	for (int i(0), r(0); i < 7; i++)
	{
		r = rand() % 1000;
		std::cout << r << std::endl;
		rasp.addNumber(r);
	}
	
	std::cout << "Longest span(R): " << rasp.longestSpan() << std::endl;

	//20k test

	std::cout << std::endl << "20k test" << std::endl;

	Span	tk(20000);

	for (int i(0), r(0); i < 20000; i++)
	{
		r = rand() % 1000000;
		tk.addNumber(r);
	}

	std::cout << "Longestest span: " << tk.longestSpan() << std::endl;
	std::cout << "Shortesest span: " << tk.shortestSpan() << std::endl;

	std::cout << std::endl;

	Span				abc(5);
	std::vector<int>	def(5);

	for (int i(0); i < 5; i++)
		def[i] = i;

	abc.addNumber(def.begin(), def.end());

	std::cout << abc.shortestSpan() << std::endl;
	std::cout << abc.longestSpan() << std::endl;

	std::cout << std::endl;

	Span	one(1);

	try{
		std::cout << one.longestSpan() << std::endl;
	}
	catch (Span::NonExistentSpanException & n){
		std::cerr << n.what() << std::endl << std::endl;
	}
	std::cout << one.shortestSpan() << std::endl;

	return 0;
}
