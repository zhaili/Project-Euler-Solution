#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include <vector>

#define N  (1+40000000LL)
#define PN (1+2433654LL)

//#define N  (1+200000)
//#define PN (1+17984)

int  prime[PN];
int  phi[N];

int  f_tbl[N];

void gen_prime()
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
    for (i=2,j=1; i<N; i++) {
        if (tbl[i]==0) prime[j++] = i;
    }

    delete []tbl;
}

void gen_eulerphi()
{
    int i, j;
    for (i=1; i<N; ++i)
        phi[i] = 1;

    for (i=1; i<PN; ++i) {
        unsigned long long p=prime[i];
        
        for (j=p; j<N; j+=p) {
            phi[j] = phi[j]*(p-1);
        }

        unsigned long long pk = p*p;
        for (; pk<N; pk*=p) {
            for (j=pk; j<N; j+=pk) {
                phi[j] = phi[j]*p;
            }
        }
    }
}

void eulerphi2()
{
    int i;
    for (i=1; i<N; i+=2) {
        phi[i] = i;
    }
    for (i=2; i<N; i+=2) {
        phi[i] = i/2;
    }

    int p = 1;
    while (p<N/2) {
        p += 2;
        if (phi[p]!=p) continue;

        int pk;
        for (pk=p+p;pk<N;pk+=p) {
            phi[pk] = phi[pk]/p * (p-1);
        }
    }

    for (i=2; i<N; ++i) {
        if (phi[i] == i) phi[i]--;
    }

    /*for (i=1; i<N; ++i)
        printf("%d\n", phi[i]);
    */
}
/*
int main()
{
    float start, end;
    start = clock();
    eulerphi2();

    end = clock();
    printf("Time=%.2fs", (end-start)/CLK_TCK);
    return 0;
}
*/
int f(int i)
{
    if (f_tbl[i]==0) {
        int j = phi[i];
        f_tbl[i] = f(j)+1;
    }
    return (f_tbl[i]);
}

int main()
{
    float start, end;
    start = clock();

    eulerphi2();

    int i;
    for (i=0; i<N; ++i) {
        f_tbl[i] = 0;
    }
    f_tbl[1] = 1;

    unsigned long long  s=0;
    for (i=1; i<N; ++i) {
        if (phi[i]==i-1 && f(i)==25) s+=i;
    }
    printf("%I64u\n", s);

    end = clock();
    printf("Time=%.2fs", (end-start)/CLK_TCK);
    return 0;
}

/*
int main()
{
    float start, end;
    start = clock();
    
    gen_prime();
    gen_eulerphi();

    int i;
    for (i=0; i<N; ++i) {
        f_tbl[i] = 0;
    }
    f_tbl[1] = 1;

    unsigned long long  s=0;
    for (i=1; i<PN; ++i) {
        int p = prime[i];
        if (f(p)==25) s+= p;
    }
    printf("%I64u\n", s);

    end = clock();
    printf("Time=%.2fs", (end-start)/CLK_TCK);

    return 0;
}
*/
