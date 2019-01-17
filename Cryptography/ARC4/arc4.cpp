#include <utility> // For swap function
#include <cstring>
#include "header.h"

using namespace std;

ARC4::ARC4() { }

void ARC4::KSA (char *key, uchar *Sbox)
{
	int len = strlen(key);
	int j = 0;

	for (int i = 0; i < 256; i++)
		Sbox[i] = i;

	for (int i = 0; i < 256; i++)
	{
		j = (j + Sbox[i] + key[i % len]) % 256;
		swap(Sbox[i], Sbox[j]);
	}
}

void ARC4::PRGA (uchar *Sbox, uchar *plaintext, uchar *ciphertext)
{
	int i = 0;
	int j = 0;

	for (size_t n = 0, len = strlen((const char*)plaintext); n < len; n++)
	{
		i = (i+1) % 256;
		j = (j+Sbox[i]) % 256;

		swap (Sbox[i], Sbox[j]);
		int K = Sbox[(Sbox[i] + Sbox[j]) % 256];

		ciphertext[n] = K^plaintext[n];
	}
}

void ARC4::encrypt (uchar *plaintext, char *key, uchar *ciphertext)
{
	uchar Sbox[256];
	KSA (key,Sbox);
	PRGA (Sbox,plaintext,ciphertext);
}
 
