/* RC4+ function prototype */

#ifndef _RC4plus_h
#define _RC4plus_h

typedef unsigned char uchar;

void swap (uchar *a, uchar *b);

void KSA (uchar *key, uchar *Sbox);

void PRGA_RC4plus (uchar *Sbox, uchar *plaintext, uchar *ciphertext);

void RC4plus_Encrypt (uchar *plaintext, uchar *RC4plus_Key, uchar *ciphertext);

uchar *RC4plus_Key();

#endif
