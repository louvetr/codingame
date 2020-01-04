#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

//#define alphabet "ABCDEFGHIJKLMNOPKRSTUVWXYZabcdefghijklmnopkrstuvwxyz@?"
#define alphabet "ABCDEFGHIJKLMNOPQRSTUVWXYZ?"

int main()
{
	int L, H;
	char T[257];
	char **tabb = NULL;

	scanf("%d", &L);
	scanf("%d", &H);
	fgetc(stdin);
	fgets(T, 257, stdin);

	tabb = malloc(sizeof(char *) * H);
	for (int i = 0; i < H; i++) {
		tabb[i] = calloc(1, 1025);
		fgets(tabb[i], 1025, stdin);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < strlen(T) - 1; j++) {
			int k, found = 0;
			for (k = 0; k < strlen(alphabet); k++) {
				if (alphabet[k] == toupper(T[j])) {
					found = 1;
					break;
				}
			}
			if (found == 0)
				k = 26;
			printf("%.*s", L, tabb[i] + k * L);
		}
		if (i < H - 1)
			printf("\n");
	}

	return 0;
}