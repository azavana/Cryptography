/* Andry Rafam Andrianjafy - January 2019

RC4 - Rivest Cipher 4 Implementation in C++. 

Ubuntu 16.04 LTS - GCC Version 6.5.0 && GDB Version 8.2 */


#include <iostream>
#include <cstring>
#include "header.h"

using namespace std;

int main(int argc, char **argv)
{
	ARC4 *arc4;
		
	if (argc != 3)
	{
		cout << "\n";
		cout << "Usage : " << argv[0] << " < Plaintext > < Key > " << endl;
		cout << "\n";
		return -1;
	}

	uchar *ciphertext = new (nothrow) uchar[strlen(argv[1])];
	
	arc4->encrypt((uchar*)argv[1],argv[2],ciphertext);

	cout << "\n[ Encrypted Text ] >> ";
	for (int i = 0; i < strlen(argv[1]); i++)
		fprintf(stdout, "%02hhX", ciphertext[i]);
	cout << endl << endl;

	delete [] ciphertext;
	return EXIT_SUCCESS;
}	
