#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
	int N;
	scanf("%d", &N);
	int L;
	scanf("%d", &L);
	fgetc(stdin);

	fprintf(stderr, "N=%d, L=%d\n", N, L);
	fprintf(stderr, "\n");

	char tab[N][N];
	int i, j, x, y;

	for (int i = 0; i < N; i++) {
		char line[501];
		memset(line, 0, 501);
		fgets(line, 501, stdin);

		j = 0;
		int done = 0;
		while (done < N) {
			if (j % 2 == 0) {
				if (line[j] == 'X')
					tab[i][done] = 0;
				else
					tab[i][done] = line[j];
				done++;
			}
			j++;
		}
	}

	// showroom
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			fprintf(stderr, "%c ", tab[i][j] == 0 ? 'X' : 'C');
		}
		fprintf(stderr, "\n");
	}

	fprintf(stderr, "\n");
	int candle = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			int Xstart, Xmax, Ystart, Ymax;

			if (tab[i][j] != 'C')
				continue;

			tab[i][j] = 0;

			Xstart = i - L + 1;
			Xmax = 2 * i + 1 - Xstart;
			if (Xstart < 0)
				Xstart = 0;
			if (Xmax >= N)
				Xmax = N;

			Ystart = j - L + 1;
			Ymax = 2 * j + 1 - Ystart;
			if (Ystart < 0)
				Ystart = 0;
			if (Ymax >= N)
				Ymax = N;

			int prev = 0;
			for (x = Xstart; x < Xmax; x++) {
				for (y = Ystart; y < Ymax; y++) {
					if (tab[x][y] != 'C') {
						tab[x][y]++;
					}
				}
			}
		}
	}

	// show shade
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			fprintf(stderr, "%d ", tab[i][j]);
		}
		fprintf(stderr, "\n");
	}

	int shadow = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (tab[i][j] == 0)
				shadow++;
		}
	}

	fprintf(stderr, "\n");
	printf("%d\n", shadow);

	return 0;
}