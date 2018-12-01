#ifndef __RC4A_h_
#define __RC4A_h_

void swap (unsigned char *a, unsigned char *b);

void KSA (char *key, unsigned char S[256]);

void PRG (unsigned char S1[256], unsigned char S2[256], unsigned char *plaintext, unsigned char *ciphertext);

void RC4A_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext);

unsigned char *RC4A_Key();

long int bin(int x);

#endif
