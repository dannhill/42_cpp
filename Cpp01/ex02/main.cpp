#include <string>
#include <iostream>

int main(void){
    std::string str("HI THIS IS BRAIN");
    std::string *stringPTR(&str);
    std::string &stringREF(str);

	stringREF.append("ciao");

    std::cout << "String memory address: " << &str << std::endl;
    std::cout << "String memory address(PTR): " << stringPTR << std::endl;
    std::cout << "String memory address(REF): " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "String value(PTR): " << *stringPTR << std::endl;
    std::cout << "String value(REF): " << stringREF << std::endl;
    return 0;
}