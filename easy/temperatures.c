#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{ // the number of temperatures to analyse
	int n;
	int delta = 10000;
	int prev_delta = 10000;
	int min = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		// a temperature expressed as an integer ranging from -273 to 5526
		int t;
		scanf("%d", &t);

		if (t > 0)
			delta = t;
		else
			delta = -t;

		if (delta < prev_delta) {
			prev_delta = delta;
			min = t;
		} else if (delta == prev_delta) {
			if (t > min)
				min = t;
		}
	}

	printf("%d\n", min);

	return 0;
}