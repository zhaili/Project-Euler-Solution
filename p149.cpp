#include <stdio.h>
#include <stdlib.h>

#define DIM 2000

// int data[DIM][DIM] = {
//     -2,5,3,2,
//     9,-6,5,1,
//     3,2,7,3,
//     -1,8,-4,8
// };

int data[DIM][DIM];

// int adjsum(int *a, int n)
// {
//     int c = 0, max = 0;
//     for (int i=0; i<n; ++i) {
//         if (c>0)
//             c += a[i];
//         else
//             c = a[i];
//         if (c>max) max = c;
//     }

//     return max;
// }

__int64 antidiag(int m[DIM][DIM])
{
    int x=DIM-1, y=0;
    __int64 max = 0;
    
    while (x>0 || y<DIM) {
        int i=x,j=y;
        
        __int64 c = 0;
        while (i<DIM && j<DIM) {
            if (c>0) c += m[i][j];
            else c = m[i][j];
            if (c>max) max = c;

            ++i;
            ++j;
        }
        
        if (x>0) --x;
        else ++y;
    }

    return max;
}

__int64 diag(int m[DIM][DIM])
{
    int x=0, y=0;
    __int64 max = 0;

    while (x<DIM || y<DIM-1) {
        int i=x,j=y;

        __int64 c = 0;
        while (i<DIM && j>=0) {
            if (c>0) c += m[i][j];
            else c = m[i][j];
            if (c>max) max = c;
            
            ++i;
            --j;
        }
        
        if (y<DIM-1) ++y;
        else ++x;
    }

    return max;
}

__int64 vertical(int m[DIM][DIM])
{
    __int64 max = 0;
    for (int j=0; j<DIM; ++j) {

        __int64 c = 0;
        for (int i=0; i<DIM; ++i) {
            if (c>0) c += m[i][j];
            else c = m[i][j];
            if (c>max) max = c;
        }
    }

    return max;
}

__int64 horizontal(int m[DIM][DIM])
{
    __int64 max = 0;
    for (int i=0; i<DIM; ++i) {

        __int64 c = 0;
        for (int j=0; j<DIM; ++j) {
            if (c>0) c += m[i][j];
            else c = m[i][j];
            if (c>max) max = c;
        }
    }

    return max;
}

void init(int a[DIM][DIM])
{
    int k;

    for (k=0; k<55; ++k) {
        __int64 c = 300007*(k+1);
        c *= k+1;
        c *= k+1;
        c -= 200003*(k+1);
        c += 100003;

        a[0][k] = c % 1000000 - 500000;
    }

    for (; k<4000000; ++k) {
        int i = k/2000;
        int j = k%2000;

        a[i][j] = (a[(k-24)/2000][(k-24)%2000]+a[(k-55)/2000][(k-55)%2000]+1000000) % 1000000;
        a[i][j] -= 500000;
    }
}

int main()
{
    init(data);

    __int64 max;
    max = diag(data);
    printf("max=%I64d\n",max);

    max = antidiag(data);
    printf("max=%I64d\n",max);

    max = vertical(data);
    printf("max=%I64d\n",max);
    
    max = horizontal(data);
    printf("max=%I64d\n",max);

    return 0;
}
