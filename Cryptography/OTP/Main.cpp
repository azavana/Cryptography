#include <iostream>
#include <string>
#include "OTP.h"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stdout, "\nUsage : %s < Plaintext > \n\n", argv[0]);
		return -1;
	}

	otp_cipher (argv[1]);
	fprintf(stdout, "\n[ Encrypted Message ] >> ");
	print(otp_cipher(argv[1]));
	cout << endl;
	return EXIT_SUCCESS;
}
