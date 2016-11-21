#include <stdio.h>

#define MAX_LEN 1000+1

int peanuts[MAX_LEN][MAX_LEN];

int main()
{
    int L, W, a, b, i, j, tmp, sum;

// input
    scanf("%d %d", &L, &W);
    for( i = 0; i < L; i++ )
    {
        sum = 0;
        for( j = 0; j < W; j++ )
        {
            scanf("%d", &tmp);
            sum += tmp;
            peanuts[i][j] = i==0? sum:sum+peanuts[i-1][j];
        }
    }
    scanf("%d %d", &a, &b);

// process
    sum = 0;
    for( i = 0; i < L-a; i++ )
    {
        for( j = 0; j < W-b; j++ )
        {
            tmp = peanuts[i+a][j+b] - peanuts[i+a][j] - peanuts[i][j+b] + peanuts[i][j];

            if( tmp > sum ) sum = tmp;
        }
    }

// output

    printf("%d", sum);

    return 0;
}
