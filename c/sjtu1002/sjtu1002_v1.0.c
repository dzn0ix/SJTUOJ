#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int L, W, a, b, i, j, tmp, sum, **peanuts;

// input
    scanf("%d %d", &L, &W);

    peanuts = (int **)malloc((L+1)*sizeof(int *));
    for( i = 0; i <= L; i++ )
    {
        peanuts[i] = (int *)malloc((W+1)*sizeof(int));
        memset(peanuts[i], 0, (W+1)*sizeof(int));
    }

    for( i = 1; i <= L; i++ )
    {
        sum = 0;
        for( j = 1; j <= W; j++ )
        {
            scanf("%d", &tmp);
            peanuts[i][j] = tmp + peanuts[i][j-1] + peanuts[i-1][j] - peanuts[i-1][j-1];
        }
    }

    scanf("%d %d", &a, &b);

// process
    sum = 0;
    for( i = 0; i <= L-a; i++ )
    {
        for( j = 0; j <= W-b; j++ )
        {
            tmp = peanuts[i+a][j+b] - peanuts[i+a][j] - peanuts[i][j+b] + peanuts[i][j];

            if( tmp > sum ) sum = tmp;
        }
    }

// output

    printf("%d", sum);

    return 0;
}
