/*
  g++ -o p111 -O2 p111.cpp -Ie:/gmp/include -Le:/gmp/lib -lgmpxx -lgmp
*/

#include <stdio.h>
#include <time.h>

#include "gmp.h"

typedef unsigned __int64 int64;

int64 sum = 0;

int rep_lim;
int dep_lim;
bool found = false;

void mpz_set_uj(mpz_t x, int64 y) {
    mpz_import(x,sizeof(int64),-1,1,0,0,&y);
}

void dfs(int rep, int d, int64 last, int dep)
{
    if (d + (dep_lim-dep) < rep_lim) return;

    if (dep == dep_lim) {
        if (rep = rep_lim) {
            // mpz_class n(last);
            mpz_t n;
            mpz_init(n);
            mpz_set_uj(n, last);

            if (mpz_probab_prime_p(n, 5)) {
                //printf("%I64d\n", last);
                found = true;
                sum += last;
            }
        }
        return;
    }

    for (int i=0; i<10; ++i) {
        int64 m = last*10 + i;

        if (i==rep) {
            dfs(rep, d+1, m, dep+1);
        }
        else {
            dfs(rep, d, m, dep+1);
        }
    }
    
}

#define DEPLIM 10

int main()
{
    int start = clock();

    dep_lim = DEPLIM;
    rep_lim = dep_lim-1;

    for (int r=0; r<10; ++r) {
        //printf("r=%d\n", r);

        do {
            for (int i=1; i<10; ++i) {
                if (i==r) dfs(r, 1, i, 1);
                else dfs(r, 0, i, 1);
            }
            rep_lim--;
        } while (!found);
        
        found = false;
        rep_lim = DEPLIM;
    }

    printf("sum=%I64d\n", sum);

    int finish = clock();

    printf("time:%fms\n", 1000*((float)finish-start)/CLOCKS_PER_SEC);
    return 0;
}
