#ifndef __SPRITZ_h
#define __SPRITZ_h

int GCD (int a, int b);

void swap (unsigned char *a, unsigned char *b);

void KSA (char *key, unsigned char S[256]);

void PRG (unsigned char S[256], unsigned char *plaintext, unsigned char *ciphertext);

void SPRITZ_Encrypt (unsigned char *plaintext, char *key, unsigned char *ciphertext);

unsigned char *SPRITZ_Key();

#endif
