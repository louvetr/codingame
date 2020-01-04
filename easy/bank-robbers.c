#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int main()
{
	int R, V, empty_vaults = 0, time = 0;
	scanf("%d", &R);
	scanf("%d", &V);

	fprintf(stderr, "R = %d, V = %d\n", R, V);

	int robbers[R], vaults[V][2];

	for (int i = 0; i < R; i++)
		robbers[i] = -1;

	for (int i = 0; i < V; i++) {
		int C;
		int N;
		scanf("%d%d", &C, &N);
		vaults[i][0] = -1;
		vaults[i][1] = (int)(pow(10, N) * pow(5, (C - N)));
	}

	while (empty_vaults != V) {
		int min_time = INT_MAX;

		// place robbers
		for (int i = 0; i < R; i++) {
			if (robbers[i] < 0) {
				for (int j = 0; j < V; j++) {
					if (vaults[j][0] < 0 &&
					    vaults[j][1] > 0) {
						vaults[j][0] = i;
						robbers[i] = j;
						break;
					}
				}
			}
		}

		for (int j = 0; j < V; j++) {
			if (vaults[j][0] >= 0 && (vaults[j][1] < min_time)) {
				min_time = vaults[j][1];
				fprintf(stderr,
					"taking min from vault #%d (%d, %d)\n",
					j, vaults[j][0], vaults[j][1]);
			}
		}

		// open vaults
		for (int j = 0; j < V; j++) {
			if (vaults[j][0] >= 0) {
				vaults[j][1] -= min_time;
				if (vaults[j][1] <= 0) {
					empty_vaults++;
					robbers[vaults[j][0]] = -1;
					vaults[j][0] = -1;
				}
			}
		}
		time += min_time;

		fprintf(stderr, "[%d/%d], time = %d\n", empty_vaults, V, time);
		for (int j = 0; j < V; j++) {
			if (vaults[j][1] > 0)
				fprintf(stderr, "vault[%d][1] = %d\n", j,
					vaults[j][1]);
		}
	}

	printf("%d\n", time);

	return 0;
}