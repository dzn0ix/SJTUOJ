#include <stdio.h>

#define MAX_LEN 1000+1

int peanuts[MAX_LEN][MAX_LEN];

int main()
{
    int L, W, a, b, i, j, n, m, tmp, sum;

// input 
    scanf("%d %d", &L, &W);
    for( i = 0; i < L; i++ )
    {
        for( j = 0; j < W; j++ )
	    {
            scanf("%d", &peanuts[i][j]);
	    }
    }
    scanf("%d %d", &a, &b);

// process
    tmp = 0;
    for( i = 0; i <= L-a; i++ )
    {
        for( j = 0; j <= W-b; j++ )
	    {
	        sum = 0;
            for( n = 0; n < a; n++ )
	        {
                for( m = 0; m < b; m++ )
		        {
                    sum += peanuts[i+n][j+m];
		        }
	        }

	        if( sum > tmp ) tmp = sum;
	    }
    }

// output
    printf("%d", tmp);

    return 0;
}
