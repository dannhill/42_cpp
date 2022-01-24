#include "Base.hpp"
#include <ctime>
#include <iostream>

Base	*generate(void){
	return rand() % 3 ? (rand() % 2 ? static_cast<Base *>(new B)
		: static_cast<Base *>(new C))
		: static_cast<Base *>(new A);
}

void	identify(Base *p){
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cerr << "Error: type not recognized." << std::endl;
	return;
}

void	identify(Base & p){
	try{
		A(dynamic_cast<A &>(p));
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception & e){}
	try{
		B(dynamic_cast<B &>(p));
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception & e){}
	try{
		C(dynamic_cast<C &>(p));
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
	return;
}

int	main(void){
	srand(time(NULL));

	Base	*a = new A();
	Base	*b = new B();
	Base	*c = new C();

	Base	*r = generate();

	std::cout << "Identify Class of type A: " << std::endl;
	std::cout << "By pointer: ";
	identify(a);
	std::cout << "By reference: ";
	identify(*a);

	std::cout << std::endl;

	std::cout << "Identify Class of type B: " << std::endl;
	std::cout << "By pointer: ";
	identify(b);
	std::cout << "By reference: ";
	identify(*b);

	std::cout << std::endl;

	std::cout << "Identify Class of type C: " << std::endl;
	std::cout << "By pointer: ";
	identify(c);
	std::cout << "By reference: ";
	identify(*c);

	std::cout << std::endl;

	std::cout << "Identify Class of random type (A/B/C) (Rerun to change value): " << std::endl;
	std::cout << "By pointer: ";
	identify(r);
	std::cout << "By reference: ";
	identify(*r);

	delete r;
	delete c;
	delete b;
	delete a;
}