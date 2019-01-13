#include <iostream>
#include <string>
#include <cassert>
#include "OTP.h"

// OTP encryption fucntion with key random generator
string otp_cipher (string cleartext)
{
	srand(time(NULL));
	string cipher = "";
	int *key_otp = (int*)malloc(sizeof(int) * cleartext.length());
	assert (key_otp != NULL);
	for (int i = 0; i < cleartext.length(); i++)
	{
		key_otp[i] = rand() % 25 + 1; // Generate key randomly
		if (isupper(cleartext[i]))
			cipher += char((int(cleartext[i]^key_otp[i]) - 65)%26 + 65);
		else if (islower(cleartext[i]))
			cipher += char((int(cleartext[i]^key_otp[i]) - 97)%26 + 97);
		else
			cipher += cleartext[i];	
	}
	return cipher;
	free (key_otp);
}

void print (string text)
{
	for (int i = 0; i < text.length(); i++)
		cout << text[i];
	cout << endl;
}		

