#include <stdio.h>
#include <qrencode.h>
#include "qr.h"

int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("usage: please input the qrdata\n");
		printf("usage: genqr [qrdata].\n");
		return 0;
	}

	qr(argv[1]);

	return 0;
}

