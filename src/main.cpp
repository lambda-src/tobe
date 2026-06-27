#include "include/util.hpp"
#include <iostream>

// TODO: Meowwowowowow

int main(int argc, char **argv) {
	if (argc == 1) 
		panic("No input file was passed into the program");
	const std::string file_path = argv[1];
	std::cout << file_path << std::endl;
	return 0;
}
