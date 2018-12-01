/* RC4+ function */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "RC4plus.h"

void swap (uchar *a, uchar *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/*Key scheduling algorithm*/
void KSA (uchar *key, uchar *Sbox)
{
	for (int i = 0; i < 256; i++)
		Sbox[i] = i;
	
	int j = 0;
	for (int i = 0; i < 256; i++)
	{
		j = (j + Sbox[i] + key[i % strlen(key)]) % 256;
		swap (&Sbox[i], &Sbox[j]);
	}
	return;
}

/*Pseudo random generator algorithm*/
void PRGA_RC4plus (uchar *Sbox, uchar *plaintext, uchar *ciphertext)
{
	int i = 0;
	int j = 0;
	
	for (int n = 0; n < strlen(plaintext); n++)
	{
		i = (i + 1) % 256;
		j = (j + Sbox[i]) % 256;
		
		swap (&Sbox[i], &Sbox[j]);

		int c = (Sbox[(i <<= 5)^(j >>= 3)] + Sbox[(j <<= 5)^(i >>= 3)]) % 256;
		int K = ((Sbox[(Sbox[i]+Sbox[j]) % 256] + Sbox[c^0xAA]) % 256)^Sbox[(j+Sbox[j]) % 256];		
		
		ciphertext[n] = K^plaintext[n];
	}
		return;
}

void RC4plus_Encrypt (uchar *plaintext, uchar *RC4plus_Key, uchar *ciphertext)
{
	uchar Sbox[256];
	KSA (RC4plus_Key, Sbox);
	PRGA_RC4plus (Sbox, plaintext, ciphertext);

	return;
}

/*Generating the RC4+_Key randomly*/
uchar *RC4plus_Key ()
{
	srand(time(NULL));
	int key1, key2, count;
	int len_key = rand() % 256 + 5; // Key between 5 to 256 bytes long

	uchar *result = malloc(sizeof(uchar) * len_key);
	assert (result != NULL);

	for (int i = 0; i < len_key; i++)
	{
		count = rand() % 2;
		key1 = rand() % 26;
		key2 = rand() % 26;

		if (count == 0)
			result[i] = (char)((key1 - 65) % 26 + 65);
		else 
			result[i] = (char)((key2 - 97) % 26 + 97);
	}
	return result;
}
