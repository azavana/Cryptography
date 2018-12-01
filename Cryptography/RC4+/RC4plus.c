/* Andry RAFAM ANDRIANJAFY - December 2018

Implementation of RC4+ in C language, under Linux Ubuntu 16.04 LTS.

GCC version 6.5.0 and GDB version 8.2. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "RC4plus.h"


int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stdout, "\nUsage %s < Clear message > \n\n", argv[0]);
		return -1;
	}

	uchar *ciphertext = malloc(sizeof(int) * strlen(argv[1]));
	assert(ciphertext != NULL);

	RC4plus_Encrypt (argv[1], RC4plus_Key(), ciphertext);
	fprintf(stdout, "\n");

	fprintf(stdout, "Key generated randomly\n");	
	fprintf(stdout, "\n[ Encrypted Message ] >> ");
	for (int k = 0; k < strlen(ciphertext); k++)
		fprintf(stdout, "%02X ", ciphertext[k]);
	fprintf(stdout, "\n\n");

	free (ciphertext);
	return EXIT_SUCCESS;
} 
