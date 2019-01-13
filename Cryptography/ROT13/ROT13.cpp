#include <iostream>
#include <string>
#include "ROT13.h"

string encrypt (string plaintext)
{
	string ciphertext = "";
	
	for (int i = 0; i < plaintext.length(); i++)
	{
		if (isupper(plaintext[i]))
			ciphertext += char((int(plaintext[i] + 13) - 65) % 26 + 65);
		else if (islower(plaintext[i]))
			ciphertext += char((int(plaintext[i] + 13) - 97) % 26 + 97);
		else
			ciphertext += plaintext[i];
	}
	return ciphertext;
}

void print (string text)
{
	for (int x = 0; x < text.length(); x++)
		std::cout << text[x];
	std::cout << endl;
}

