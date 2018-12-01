/* Andry RAFAM ANDRIANJAFY - October 2018

Implementation of RC4A.

Linux Ubuntu 16.04 LTS - GCC Version 6.5.0 && Gnu Debugger GDB Version 8.2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include "RC4A.h"

// Main program
int main (int argc, char **argv)
{
	if (argc < 2) 
	{
		printf("\nUsage : %s  < plaintext >\n\n", argv[0]);
		return -1;
	}
	int n, c, k;	
	unsigned char *ciphertext = malloc(sizeof(int) * strlen(argv[1]));
	assert (ciphertext != NULL);

	RC4A_Encrypt (argv[1], RC4A_Key(), ciphertext);
	printf("\n\n");
	printf("========== RC4A ==========\n\n");

	printf("[ Your encrypted Text ] >> ");
	
	for (int x = 0; x < strlen(argv[1]); x++) 
		printf("%ld", bin((int)(ciphertext[x])));
	
	
	printf("\n\n");
	
	free (ciphertext);
	return EXIT_SUCCESS;
}



	
				
