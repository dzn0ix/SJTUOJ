#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

int line[10];
int rect[3][10];
int colm[9][10];

int init(char c)
{
    switch(c)
    {
        case 'l':
            memset(line, 0, sizeof(int)*1*10);

            break;
        case 'r':
            memset(rect, 0, sizeof(int)*3*10);

            break;
        case 'c':
            memset(colm, 0, sizeof(int)*9*10);

            break;
        default:
            break;
    }

    return 0;
}

int process()
{
    int i, j, t;
    init('c');

    for( i = 0; i < 9; i++ )
    {
        init('l');
        if( i % 3 == 0 ) init('r');

        for( j = 0; j < 9; j++ )
        {
            scanf("%d", &t);

            if( line[t] || rect[(int)(j/3)][t] || colm[j][t] )
                return FALSE;
            else
            {
                line[t] = t;
                rect[(int)(j/3)][t] = t;
                colm[j][t] = t;
            }
        }
    }

    return TRUE;
}

int main()
{
    int n, k;

// input
    scanf("%d", &n);

// process && output
    for( k = 0; k < n; k++ )
    {
        if( process() == TRUE )
            printf("Right\n");
        else
            printf("Wrong\n");
    }

    return 0;
}
