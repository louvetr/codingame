#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{
	int highest;
	int highest_idx;
	char line[512];
	int cpt = 0;

	while (1) {
		highest = 0;
		highest_idx = 0;

		for (int i = 0; i < 8;
		     i++) { // represents the height of one mountain.
			int mountain_h;
			scanf("%d", &mountain_h);
			//printf("mountain #%d : %d\n", i, mountain_h);

			if (mountain_h > highest) {
				highest = mountain_h;
				highest_idx = i;
			}
		}

		printf("%d\n",
		       highest_idx); // The index of the mountain to fire on.
	}

	return 0;
}