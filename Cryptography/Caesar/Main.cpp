/* Andry RAFAM ANDRIANJAFY - December 2018

Implementation of Caesar cipher in C++, under Linux Ubuntu 16.04 LTS

GCC version 6.5.0 and GDB version 8.2 */

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

	for (int i = 0; i < strlen(argv[1]); i++)
		cout << encrypt(argv[1])[i];
	fprintf(stdout, "\n\n"); 
	return EXIT_SUCCESS;
}
