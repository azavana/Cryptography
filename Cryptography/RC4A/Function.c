// All functions used in the program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>


void swap (unsigned char *a, unsigned char *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void KSA (char *key, unsigned char S[256])
{
	for (int i = 0; i < 256; i++) 
		S[i] = i;

	int j = 0;

	for (int i = 0; i < 256; i++) 
	{
		j = (j + S[i] + key[i % strlen(key)]) % 256;
		swap (&S[i],&S[j]);
	}
	return;
}

void PRG (unsigned char S1[256], unsigned char S2[256], unsigned char *plaintext, unsigned char *ciphertext)
{
	int i = 0;
	int j1 = 0, j2 = 0;
	
	for (int n = 0; n < strlen(plaintext); n++) 
	{
		i = (i + 1) % 256;
		
		j1 = (j1 + S1[i]) % 256;
		swap (&S1[i],&S1[j1]);
		int K1 = S2[(S1[i] + S1[j1]) % 256];		
		
		ciphertext[n] = K1^plaintext[n];
	
			
	}
	
	for (int k = 0; k < strlen(ciphertext); k++)
	{
		i = (i + 1) % 256;

		j2 = (j2 + S2[i]) % 256;
		swap (&S2[i],&S2[j2]);
		int K2 = S1[(S2[i] + S2[j2]) % 256];

		ciphertext[k] = K2^ciphertext[k];
	}		
	
	return;
}

void RC4A_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext)
{
	unsigned char S1[256];
	unsigned char S2[256];

	KSA (key, S1);
	KSA (key, S2);

	PRG (S1, S2, plaintext, ciphertext);

	return;
}

// Generate a 256 Bytes (2048 bits) key long
unsigned char *RC4A_Key()
{
	srand(time(NULL));
	int key, count;
	
	unsigned char *result = malloc(sizeof(unsigned char) * 256);
	assert (result != NULL);

	for (int i = 0; i < 256; ++i)
	{
		count = rand() % 2;
		key = rand() % 26;
		if (count == 0)
			result[i] = (char)((key-65) % 26 + 65);
		else if (count == 1)
			result[i] = (char)((key-97) % 26 + 97);
	}
	return result;
}

long int bin(int x)
{
	long int binaryNumber = 0;
	int remainder, i = 1;

	while (x != 0)
	{
		remainder = x%2;
		x /= 2;
		binaryNumber += remainder*i;
		i *= 10;
	}
	return binaryNumber;
}

