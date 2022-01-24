#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

int main(int c, char **v){
	//check if the number of arguments is 4, otherwise print an error message
	if (c != 4){
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return 1;
	}
	if (strlen(v[2]) <= 0 || strlen(v[3]) <= 0){
		std::cerr << "Error: empty string value" << std::endl;
		return 1;
	}
	//open a file with the name of the first argument
	std::string	fileName(v[1]);
	fileName.append(".replace");
	std::ifstream ifile(v[1]);
	//check if the file is open, otherwise print an error message
	if (!ifile.is_open()){
		std::cerr << "Error: file " << v[1] << " not found" << std::endl;
		return 1;
	}
	std::ofstream ofile(fileName.c_str());
	if (!ofile.is_open()){
		std::cerr << "Error: can't open file " << fileName << std::endl;
		ifile.close();
		return 1;
	}
	//scan every word of the file and compare to the second argument
	std::string word;
	while (!ifile.eof()){
		//a quanto pare, su wsl, il peek non rileva il carattere \n
		if (ifile.peek() == ' ' || ifile.peek() == '\t' || ifile.peek() == '\n')
		{
			ofile << (char)ifile.peek();
			ifile.seekg(ifile.tellg() + (std::streampos)1);
			continue;
		}
		ifile >> word;
		if (word == v[2])
			word = v[3];
		ofile << word;
	}
	ifile.close();
	ofile.close();
	return 0;
}