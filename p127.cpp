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

#define N  120000
#define PN 11301

// #define N  1000
// #define PN 168

int rad[N] = {0};

typedef __int64 ll;

ll prime[PN];

int gcd(int u, int v)
{
    if(u == v)
        return v;
    if(u == 0)
        return v;
    if(v == 0)
        return u;
    if(u%2 == 0){ // if u is even
        if(v%2 == 0) // if u and v are even
            return (2*gcd(u/2, v/2));
        else // u is even and v is odd
            return  gcd(u/2, v);
    }
    else if(v%2 == 0) // if u is odd and v is even
        return gcd(u, v/2);
    else{ // both are odd
        if(u>=v)
            return gcd((u-v)/2, v);
        else
            return gcd((v-u)/2, u);
    }
}

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
        if (tbl[i]==0) prime[j++] = i;
    }

    delete []tbl;

    return j;
}

void dfs(int prod, int i, int c, int r)
{
    if (i >= PN) return;

    ll t=prod*prime[i];

    if (t < N) {
        if (c==1)
            rad[t] = r*prime[i];
        else
            rad[t] = r;
        dfs(t, i, c+1, rad[t]);
    }

    dfs(prod, i+1, 1, r);
}

int main()
{
    int start = clock();

    // printf("%d\n", gen_prime());
    gen_prime();

    dfs(1, 0, 1, 1);
    rad[1] = 1;

    ll s = 0;

    for (int c=2; c<N; ++c) {
        for (int a=1; a<=c/2; ++a) {
            if (gcd(a,c)!=1) continue;
            int b = c-a;

            ll r = rad[a];
            r *= rad[b];
            if (r < c/rad[c]) {
                s += c;
            }
        }
    }

    printf("%I64d\n", s);

    int finish = clock();
    printf("time:%fms\n", 1000*((float)finish-start)/CLOCKS_PER_SEC);

    return 0;
}
