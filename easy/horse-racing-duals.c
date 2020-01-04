#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N, diff, diff_min = 10000000;
    int *horse_list;
    
    int max = 0;
    int min = 10000000;
    
    scanf("%d", &N);
    
    fprintf(stderr, "N = %d\n", N);
    
    horse_list = calloc(N, sizeof(int));
  
      for (int i = 0; i < N; i++) {
          
        int pi;
        scanf("%d", &pi);
        horse_list[i] = pi;
        fprintf(stderr, "%d\n", pi);
          
        if (pi > max)
        {
            int diff = pi - max;
            if (diff < diff_min)
                diff_min = diff;
            
            max = pi;
            fprintf(stderr, "max = %d\n", pi);
        }
        else if (pi < min)
        {
            int diff = min - pi;
            if (diff < diff_min)
                diff_min = diff;
            
            min = pi;
            fprintf(stderr, "min = %d\n", pi);
        }
        else
        {
            for (int j = 0; j < i; ++j)
            {
                int diff = horse_list[j] - pi;
                if (diff < 0)
                    diff = -diff;
                
                if (diff < diff_min) {
                    diff_min = diff;
                    fprintf(stderr, "min = %d (%d - %d)\n", diff, horse_list[j], pi);
                }
            }
        }
    }
    
    free(horse_list);

    printf("%d\n", diff_min);

    return 0;
}