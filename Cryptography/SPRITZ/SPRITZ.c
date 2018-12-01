/* Andry RAFAM ANDRIANJAFY - October 2018.

SPRITZ is an updated version of RC4 by Ronald Rivest (Ron Rivest). 

Linux Ubuntu 16.04 LTS - GCC Version 6.5.0  && Gnu Debugger Version 8.2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "SPRITZ.h"

// Main program
int main (int argc, char **argv)
{
	if (argc < 2) {
		printf("\nUsage : %s < Plaintext >\n\n", argv[0]);
		return -1;
	}

	unsigned char *ciphertext = malloc(sizeof(int) * strlen(argv[1]));
	assert (ciphertext != NULL);

	SPRITZ_Encrypt (argv[1], SPRITZ_Key(), ciphertext);
	printf("\n\n");

	printf("========== SPRITZ ============\n\n");
	printf("[ Your encrypted Text ] >> ");
	for (int p = 0; p < strlen(argv[1]); p++)
		printf("%02X%c", ciphertext[p], p < (strlen(argv[1]) - 1) ? ' ' : '\n');
	printf("\n\n");

	free (ciphertext);
	return EXIT_SUCCESS;
}



			
 
