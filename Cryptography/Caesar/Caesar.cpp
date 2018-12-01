/* Caesar function */

#include <iostream>
#include <string>
#include "Caesar.h"
using namespace std;

int caesar_key()
{
	srand(time(NULL));
	int key = rand() % 25 + 1;
	return key;
}


string encrypt (string plaintext)
{
	string ciphertext = "";

	for (int i = 0; i < plaintext.length(); i++)
	{
		if (isupper(plaintext[i]))
			ciphertext += char((int(plaintext[i] + caesar_key()) - 65) % 26 + 65);
		else if (islower(plaintext[i]))
			ciphertext += char((int(plaintext[i] + caesar_key()) - 97) % 26 + 97);
	}
	return ciphertext;
}
