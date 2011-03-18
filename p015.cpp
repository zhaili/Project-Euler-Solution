#include <stdio.h>

int main()
{
    unsigned __int64 a[21][21];
    int x,y;

    a[0][0]=0;
    for (x=1;x<21;++x) {
        a[0][x]=1;
        a[x][0]=1;
    }
    for (x=1;x<21;++x) {
        for (y=1;y<=x;++y) {
            a[y][x] = a[x][y] = a[x][y-1]+a[x-1][y];
            printf("%I64u ", a[x][y]);
        }
        printf("\n");
    }
}
