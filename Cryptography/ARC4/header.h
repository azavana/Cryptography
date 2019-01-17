#ifndef _header_h
#define _header_h

typedef unsigned char uchar;

class ARC4 {
	public:
		ARC4(); // Constructor
		void encrypt (uchar *plaintext, char *key, uchar *ciphertext);
	
	private:
		void KSA (char *key, uchar *Sbox);
		void PRGA (uchar *Sbox, uchar *plaintext, uchar *ciphertext);
};

#endif
