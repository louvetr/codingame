#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void int2bin(int n, char *p)
{
	if (p == NULL)
		return;

	do {
		if (n % 2 == 0)
			*p = '0';
		else
			*p = '1';
		p++;
		n = n / 2;
	} while (n > 0);
}

int main()
{
	char MESSAGE[101];
	char output[101 * 7];
	char tmpbin[100];
	char binary[101 * 7];
	int i, j = 0, k = 0;

	memset(MESSAGE, 0, 101);
	memset(binary, 0, 101 * 7);
	memset(tmpbin, 0, 101 * 7);

	fgets(MESSAGE, 101, stdin);

	//fprintf (stderr, "MESSAGE = '%s' (len = %d)\n", MESSAGE, strlen(MESSAGE));

	for (i = 0; i < strlen(MESSAGE) - 1; i++) {
		char tmp[8];
		int delta = 0, len;

		memset(tmp, 0, 8);
		int2bin(MESSAGE[i], tmp);
		len = strchr(tmp, '\0') - tmp;

		/* ensure each char is 7 bits long */
		delta = 7 - len;
		for (j = 0; j < delta; j++) {
			binary[k++] = '0';
			//fprintf(stderr, "binary[%d] = %c (0x%x)\n", k-1, binary[k-1], binary[k-1]);
		}

		for (j = strlen(tmp) - 1; j >= 0; j--) {
			binary[k++] = tmp[j];
			//fprintf(stderr, "binary[%d] = %c (0x%x)\n", k-1, binary[k-1], binary[k-1]);
			//fprintf(stderr, "%c",  binary[k-1]);
		}
	}

	i = 0;
	do {
		if (i > 0)
			printf(" ");
		j = 0;
		if (binary[i] == '1')
			printf("0 ");
		else
			printf("00 ");

		do {
			j++;
			printf("0");
		} while (binary[i + j] == binary[i]);
		i = i + j;

	} while (i < k);

	return 0;
}