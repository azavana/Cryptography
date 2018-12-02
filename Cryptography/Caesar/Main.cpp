#include <iostream>
#include <cstring>
#include "Caesar.h"
using namespace std;

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stdout, "\nUsage : %s < Clear text > \n\n", argv[0]);
		return -1;
	}
	fprintf(stdout, "\nKey generated randomly\n");
	fprintf(stdout, "\n[ Encrypted Text ] >> ");
	encrypt (argv[1]);

	print(encrypt(argv[1]));
	fprintf(stdout, "\n"); 
	return EXIT_SUCCESS;
}
