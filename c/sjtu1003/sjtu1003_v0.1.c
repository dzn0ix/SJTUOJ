#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Point
{
    int x;
    int y;
    struct _Point *next;
}Point;

int add_point(Point **h, int x, int y)
{
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    p->next = NULL;

    if( *h == NULL ) *h = p;
    else {
      Point *t = *h;
      while( t->next != NULL )
      {
          t = t->next;
      }
      t->next = p;
    }

    return 0;
}

int main()
{
    int L, i, j, **data, t, output = 0;
    Point *germs = NULL;

// input
    scanf("%d", &L);

    data = (int **)malloc(L*sizeof(int *));
    for( i = 0; i < L; i++ )
    {
        data[i] = (int *)malloc(L*sizeof(int));
    }

    for( i = 0; i < L; i++ )
    {
        for( j = 0; j < L; j++ )
        {
            scanf("%d", &(data[i][j]));
            if( data[i][j] == 1 )
            {
                add_point(&germs, i, j);
            }
        }
    }

// process
    for( i = 0; i < L; i++ )
    {
        for( j = 0; j < L; j++ )
        {
            if( data[i][j] == 0 )
            {
                int min;
                Point *p = germs;
                for( min = 0xffff; p != NULL; p = p->next )
                {
                    t = abs(p->x - i) + abs(p->y - j);
                    if( t < min ) min = t;
                }

                if( min > output ) output = min == 0xffff? 0:min;
            }
        }
    }

// output
    printf("%d", output);
}
