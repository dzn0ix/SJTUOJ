#include <stdio.h>

int main()
{
    char s;
    int M, T, U, F, D, i = 0, d, t;

// input && process
    scanf("%d", &M);
    scanf("%d", &T);
    scanf("%d", &U);
    scanf("%d", &F);
    scanf("%d", &D);

    for( t = 0, d = 0; t <= M && i < T; i++ )
    {
        while( (s = getchar()) == '\n' );

        if( s == 'f' )
            t += 2*F;
        else
            t += (U+D);

        if( t <= M ) d++;
    }

    for( ; i < T; i++ ) 
    {
        while( (s = getchar()) == '\n' );
    }

// output
    printf("%d", d);

    return 0;
}
