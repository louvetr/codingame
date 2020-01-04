#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

int main()
{ // the X position of the light of power
	int light_x; // the Y position of the light of power
	int light_y; // Thor's starting X position
	int initial_tx; // Thor's starting Y position
	int initial_ty;
	char s1[2], s2[2];

	scanf("%d%d%d%d", &light_x, &light_y, &initial_tx, &initial_ty);

	// game loop
	while (1) { // The remaining amount of turns Thor can move. Do not remove this line.
		int remaining_turns;
		scanf("%d", &remaining_turns);

		memset(s1, 0, 2);
		memset(s2, 0, 2);

		if (initial_ty != light_y) {
			if (initial_ty > light_y) {
				if (initial_ty > 0) {
					s1[0] = 'N';
					initial_ty--;
				}
			} else {
				s1[0] = 'S';
				initial_ty++;
			}
		}

		if (initial_tx != light_x) {
			if (initial_tx > light_x) {
				if (initial_tx > 0) {
					s2[0] = 'W';
					initial_tx--;
				}
			} else if (initial_ty < 38) {
				s2[0] = 'E';
				initial_tx++;
			}
		}

		// A single line providing the move to be made: N NE E SE S SW W or NW
		printf("%s%s\n", s1, s2);
	}

	return 0;
}