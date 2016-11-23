# include <stdio.h>

# define N 105

int A[N][N], L;
int m;

const int d[][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

int x[N*N], y[N*N], top;
int s[N*N], t[N*N], cnt;

int main()
{
    scanf("%d", &L);
    top = 0;
    for (int i = 1; i <= L; ++i) {
        for (int j = 1; j <= L; ++j) {
            scanf("%d", &A[i][j]);
            if (A[i][j] == 1) {
                x[top] = i;
                y[top] = j;
                ++top;
            }
        }
    }

    m = 0;
    while (1) {
        cnt = 0;
        for (int i = 0; i < top; ++i) {
            for (int j = 0; j < 4; ++j) {
                int nx = x[i]+d[j][0];
                int ny = y[i]+d[j][1];
                if (0>=nx||nx>L||0>=ny||ny>L) continue;
                if (A[nx][ny] == 0) {
                    s[cnt] = nx;
                    t[cnt] = ny;
                    ++cnt;
                    A[nx][ny] = 1;
                }
            }
        }
        if(cnt <= 0) break;
        for (int i = 0; i < cnt; ++i) {
            x[i] = s[i];
            y[i] = t[i];
        }
        top = cnt;
        ++m;
    }

    printf("%d\n", m);

    return 0;
}
