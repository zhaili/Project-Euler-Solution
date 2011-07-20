/*
  g++ -o p193 p193.cpp -O2 -Ie:/ntl/include e:/ntl/src/ntl.a
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// #include <NTL/ZZ.h>
// NTL_CLIENT

#define LIM 1125899906842624LL
#define N  33554432LL
#define PN 2063689

// #define LIM 100
// #define N 10
// #define PN 4

// #define LIM 1048576
// #define N 1024
// #define PN 172

typedef __int64 ll;

ll prime2[PN];

int gen_prime()
{
    int i, j, s;

    char* tbl = new char[N];
    memset(tbl, 0, sizeof(tbl[0])*N);

    s = sqrt((float)N);
    for (i=2*2; i<N; i+=2) {
        tbl[i] = 1;
    }
    for (j=3; j<=s; j+=2) {
        for (i=j*j; i<N; i+=j) {
            tbl[i] = 1;
        }
    }
    for (i=2,j=0; i<N; i++) {
        if (tbl[i]==0) prime2[j++] = i;
    }

    delete []tbl;

    return j;
}

ll s;
ll n;

void dfs(int i, ll prod, int c)
{
    if (i >= PN) return;

    if (n/prime2[i] >= prod) {

        ll t = prod*prime2[i];

        s += (1-2*(c%2))*(n/t);

        dfs(i+1, t, c+1);

        dfs(i+1, prod, c);
    }
}

int main()
{
    int start = clock();

    s = LIM;
    n = LIM;

    printf("%d\n", gen_prime());

    for (int i=0; i<PN; ++i)
        prime2[i] *= prime2[i];

    dfs(0, 1, 1);

    printf("%I64d\n",s);

    int finish = clock();
    printf("time:%fms\n", 1000*((float)finish-start)/CLOCKS_PER_SEC);

    return 0;
}
