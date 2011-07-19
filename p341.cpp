#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIM 11000000

__int64 a[LIM+1] = {0};
__int64 b[LIM+1] = {0};

__int64 find(__int64 low, __int64 high, __int64 v)
{
    __int64 l = low;
    __int64 h = high;

    while (l < h-1) {
        __int64 m = (l+h)/2;
        if (v < a[m])
            h = m;
        else
            l = m;
    }
    return l;
}

__int64 g(__int64 n)
{
    a[1] = 1;

    __int64 k;
    for (k=2; k<LIM; ++k) {
        __int64 t = find(1, k, k-1);

        a[k] = a[k-1] + t;
    }
    return k;
}

void init(__int64 n, __int64 k)
{
    __int64 s = 1;
    __int64 t = find(1,n,k-1);

    for (__int64 i=0; i<t; ++i) {
        s += i*(a[i+1]-a[i]);

        b[i] = s;
    }
}

__int64 a_by_g(__int64 k)
{
    __int64 s = 1;
    __int64 t = find(1,LIM-1,k-1);

    s = b[t-1];
    s += (k-a[t]) * t;

    return s;
}


__int64 find_by_a(__int64 low, __int64 high, __int64 v)
{
    __int64 l = low;
    __int64 h = high;

    while (l < h-1) {
        __int64 m = (l+h)/2;
        if (v < a_by_g(m))
            h = m;
        else
            l = m;
    }
    return l;
}


int main()
{
    int start = clock();
    
    __int64 pos = g(LIM);

    printf("a[max]=%I64d\n", a[pos-1]);
    init(pos-1, a[pos-1]);
    printf("a_by_g[max]=%I64d\n", a_by_g(a[pos-1]));

    __int64 s = 0;
    for (__int64 i=1; i<1000000; ++i) {
        __int64 t = i*i*i;
        
        __int64 v = find_by_a(1, a[pos-1], t);

        s += v;
    }
    printf("ans=%I64d\n", s);

    int finish = clock();
    printf("time:%fms\n", 1000*((float)finish-start)/CLOCKS_PER_SEC);

    return 0;
}
