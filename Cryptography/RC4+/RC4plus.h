/* RC4+ function prototype */

#ifndef _RC4plus_h
#define _RC4plus_h

void swap (unsigned char *a, unsigned char *b);

void KSA (unsigned char *key, unsigned char *Sbox);

void PRGA_RC4plus (unsigned char *Sbox, unsigned char *plaintext, unsigned char *ciphertext);

void RC4plus_Encrypt (unsigned char *plaintext, unsigned char *RC4plus_Key, unsigned char *ciphertext);

unsigned char *RC4plus_Key();

#endif
