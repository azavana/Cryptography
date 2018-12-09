/* Andry RAFAM ANDRIANJAFY - December 2018

Blowfish prototype */

#ifndef _Blowfish_h
#define _Blowfish_h

#include <stdint.h>

typedef unsigned char uchar;
typedef unsigned short ushort;

	
class Blowfish
{
	public:
		void Blowfish_Init (uchar *key, int keybytes);
		void Blowfish_Encipher (uint32_t *L, uint32_t *R);
		void *crack_text (uchar *text, uint32_t *Left, uint32_t *Right, int text_len);		
		uchar *Blowfish_key();
		
	protected:
		uint32_t F (uint32_t x);
};

#endif
