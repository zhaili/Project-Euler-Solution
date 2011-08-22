/*
  g++ -o p156 p156.cpp -O2 --std=c++0x
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <set>

using namespace std;

typedef __int64 int64;

int64 g[20] = {0};
int64 cof[20] = {0};

set<int64> solutions;

// #define S 1000
// int result[S] = {0};

int64 sum = 0;

int digit = 2;

#define LIM 10

int64 ipow(int base, int e)
{
    int64 result = 1;

    if (e<0) return 0;
    while (e)
    {
        if (e & 1)
            result *= base;
        e >>= 1;
        base *= base;
    }

    return result;
}

int init(int n)
{
    g[0] = 0;
    g[1] = 1;
    for (int i=2; i<=20; ++i) {
        g[i] = 10*g[i-1] + ipow(10,i-1);
    }

    cof[0] = 1;
    for (int i=1; i<=20; ++i) {
        cof[i] = ipow(10, i);
    }
}

// void dfs(int dep, int64 n, int64 fn)
// {
//     if (dep > LIM) return;
//     //if ((double)fn / n >1.1) return;

//     if (dep == LIM && fn==n) {
//         solutions.insert(fn);
//         sum += fn;
//         fprintf(stderr, "%I64d\n", fn);
//     }

//     for (int i=0; i<=9; ++i) {
//         if (i < digit) {
//             dfs(dep+1, i*cof[dep] + n, i*g[dep] + fn);
//         }
//         else if (i == digit) {
//             dfs(dep+1, i*cof[dep] + n, i*g[dep] + fn + n + 1);
//         }
//         else {
//             dfs(dep+1, i*cof[dep] + n, i*g[dep] + fn + cof[dep]);
//         }
//     }
// }

int64 h(int64 n, int d)
{
    int64 s = 0, r=n;
    int i=1;
    do {
        int t = r%10;
        s += t * g[i-1];
        if (t==d) s += n % cof[i-1] + 1;
        else if (t>d) s += cof[i-1];
        ++i;
    } while (r /= 10);

    return s;
}

int64 s(int d, int64 m)
{
    int64 sum=0;
    int64 n = 0;
    while (n < m) {
        int64 hn = h(n, d);
        int64 diff = hn-n;

        if (diff == 0) {
            sum += n;
            ++n;
        }
        else if (diff < 0) {
            int64 t=n;
            int l;
            for (l=0; t; ++l) t /= 10;
            n += max((int64)1,(-diff)/l);
        }
        else {
            n += diff;
        }
    }

    return sum;
}

int main(int argc, char** argv)
{
    int start = clock();

    // if (argc == 2) digit = atoi(argv[1]);
    // printf("digit:%d\n",digit);

    init(20);

    int64 sum=0;
    for (int i=1; i<=9; ++i) {
        int64 t = s(i, 10000000000000L);
        printf("%I64d\n", t);
        sum += t;
    }
    printf("sum=%I64d\n", sum);

    // int i;
    // for (i=0; i<digit; ++i)
    //     dfs(1, i, 0);
    // for (; i<=9; ++i)
    //     dfs(1, i, 1);

    //fprintf(stderr, "-----------------------------------\n");

    // for (set<int64>::iterator it=solutions.begin(); it!=solutions.end(); ++it)
    //     printf("%I64d\n", *it);

    // printf("sum=%I64d\n", sum);

    fprintf(stderr, "time:%fms", 1000*((float)clock()-start)/CLOCKS_PER_SEC);

    return 0;
}
