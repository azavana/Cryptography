/* Andry RAFAM ANDRIANJAFY - December 2018

Implementation of Blowfish in C++. Linux Ubuntu 16.04 - LTS

GCC 6.5.0 && GDB 8.2 */

#include <iostream>
#include <new>
#include <stdint.h>
#include <cstring>
#include "Blowfish.h"
#include "ORIG_S_P.h"

using namespace std;

main (int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stdout, "\nUsage : %s < Plaintext >\n\n", argv[0]);
		exit(0);
	}

	Blowfish *B = new (nothrow) Blowfish;	
	
	uint32_t L, R;
	int block_len;	
	
	int len_Blowfish_key = strlen((const char*)B->Blowfish_key());
	uchar *key_temp_Blowfish = new (nothrow) uchar[len_Blowfish_key];
	memcpy (key_temp_Blowfish, B->Blowfish_key(), len_Blowfish_key);
	
	system("clear");

	/* Performing Blowfish */
	fprintf(stdout, "\n\n\t[ BLOWFISH ENCRYPTION PROGRAM ]");
	B->Blowfish_Init (key_temp_Blowfish, len_Blowfish_key);
	B->crack_text ((uchar*)argv[1], &L, &R, strlen((const char*)argv[1])); // Crack the text string into two 32-bit block; pad with zeros if necessary
	B->Blowfish_Encipher (&L, &R);	
	fprintf(stdout, "\n\n\t>> %08X %08X\n\n", L, R);	
	
	delete B;
	
}
