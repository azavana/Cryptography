#include <iostream>
#include "ROT13.h"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\nUsage " << argv[0] << " < Plaintext >\n\n";
		return -1;
	}
	std::cout << endl;
	std::cout << "[ Encrypted text ] >> ";
	print(encrypt(argv[1]));
	std::cout << endl;
	return EXIT_SUCCESS;
}
