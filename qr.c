#include <stdio.h>
#include <qrencode.h>

#define PRINT_BLACK_SQUARE() printf("\033[40m  \033[0m")
#define PRINT_WHITE_SQUARE() printf("\033[47m  \033[0m")

void print_qrcode(QRcode *qr)
{
	int i, j, width;

	width = qr->width + 2;
	for (i = 0; i < width; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == (width - 1) || 
				j == 0 || j == (width  -1)) {
				PRINT_WHITE_SQUARE();
				continue;
			}
			if (qr->data[(i - 1) * (width - 2) + (j - 1)] & 0x01)
				PRINT_BLACK_SQUARE();
			else 
				PRINT_WHITE_SQUARE();
		}
		printf("\n");
	}
	printf("\n");
}

void qr(char *qrdata)
{
	QRcode *qrcode;
	qrcode = QRcode_encodeString(qrdata, 2, QR_ECLEVEL_L, QR_MODE_8, 1);

	print_qrcode(qrcode);

}
