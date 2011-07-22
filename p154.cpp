#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define LIM 200000

#define N  4096
#define N2 244140625

// #define LIM 100

// #define N  4
// #define N2 25

typedef long long ll;

int row_2[LIM+1];
int col1_2[LIM+1];
int col2_2[LIM+1];

int row_5[LIM+1];
int col1_5[LIM+1];
int col2_5[LIM+1];

int *col_2;
int *col_o_2;

int *col_5;
int *col_o_5;

void next_r(int* row, int r, int n)
{
    int t1, t2;
    
    t2 = 1;
    row[0] = 1;
    for (int j=1; j<=r; ++j) {
        t1 = row[j];
        row[j] = (t1 + t2) % n;
        t2 = t1;
    }
    row[r+1] = 1;

    // for (int j=0; j<=r+1; ++j)
    //     printf("%d,", row[j]);
    // printf("\n");
}

void next_c(int* &col, int* &col_o, int c, int n)
{
    int *t=col_o;
    col_o = col;
    col = t;

    col[c] = 1;
    for (int j=c; j<LIM-1; ++j) {
        col[j+1] = (col[j] + col_o[j]) % n;
    }

    // for (int j=c; j<LIM; ++j)
    //     printf("%d,", col[j]);
    // printf("\n");
}

int f()
{
    col_o_2 = col1_2;
    col_2 = col2_2;
    
    col_o_5 = col1_5;
    col_5 = col2_5;
    for (int i=0; i<=LIM; ++i) {
        col_2[i] = 1;
        col_5[i] = 1;
    }

    ll c=0;
    for (int i=0; i<LIM; ++i) {
        next_r(row_2, i, N);
        next_c(col_2, col_o_2, i, N);

        next_r(row_5, i, N2);
        next_c(col_5, col_o_5, i, N2);

        for (int j=0; j<=i+1; ++j) {
            int t = (col_2[LIM-1] * row_2[j]) % N;

            //printf("%d,", row_2[j]);

            if (t==0) {
                ll t2 = col_5[LIM-1];
                t2 = (t2*row_5[j]) % N2;
            
                if (t2==0) ++c;
            }
            //printf("%d,", t);
        }
        // printf("\n");

        // for (int j=0; j<LIM; ++j)
        //     printf("%d,", col_2[j]);
        // printf("\n");
        printf("i=%d\n", i);
    }

    printf("%I64d\n", c);
}


int main()
{
    int start = clock();
    f();
    int finish = clock();
    printf("time:%fms", 1000*((float)finish-start)/CLOCKS_PER_SEC);

    return 0;
}
/*479742450*/
