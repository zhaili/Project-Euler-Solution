#include <stdio.h>
#include <map>

#if (0)

std::map<int, int> mem_g;

int g(int n, int m)
{
    unsigned __int64 r=0;

    if (mem_g.count(n) > 0)
        return mem_g[n];

    if (n==0) {
        mem_g[n] = 1;
        return 1;
    }

    if (n%2==1) {
        r = (10*g(n-1, m)) % m;
    } else {
        r = g(n/2,m);
        r = (r*r) % m;
    }

    mem_g[n] = r;
    return r;
}

std::map<int, int> mem_f;

int f(int n, int m)
{
    unsigned __int64 r=0;

    if (mem_f.count(n) > 0)
        return mem_f[n];

    if (n==1) {
        mem_f[n] = 1;
        return 1;
    }

    if (n%2==1) {
        r = (10*f(n-1, m) + 1) % m;
    } else {
        r = f(n/2,m);
        int gv = g(n/2, m);
        //int gv = mem_g[n/2];
        r = (r*(1+gv)) % m;
    }
    
    mem_f[n] = r;
	return r;
}

int a(int n)
{
    if (n%2==0 || n%5==0)
        return -1;

    mem_g.clear();
    mem_f.clear();

    int k = 1;
    while (1) {
        if (f(k,n) == 0)
            break;
        ++k;
    }
    return k;
}

// int main()
// {
//     int n = 3;

//     while (1) {
//         n += 2;
//         if (n%5==0) continue;
//         int v = a(n);
//         if (v >= 1000000) {
//             printf("n=%d,a=%d\n", n,v);
//             break;
//         }
//         if (n % 2047 == 0)
//             printf("n=%d,a=%d\n", n,v);
//     }
// }

int main()
{
    printf("a=%d", a(1000023));
    printf("a=%d", a(1000171));
}

#endif

#if (1)
int a(int n)
{
    __int64 r = 1;
    int c = 1;
    while (r) {
        r = (r*10 + 1) % n;
        ++c;
    }
    return c;
}

int main()
{
    // printf("a=%d\n", a(1000171));
    // printf("a=%d\n", a(1000023));
    // printf("a=%d\n", a(333341));

    //int n = 3;
    int n = 999999;             // a(n) < n
    while (1) {
        n += 2;
        if (n%5==0) continue;
        int v = a(n);
        if (v >= 1000000) {
            printf("n=%d,a=%d\n", n,v);
            break;
        }
    }

    // for (int i=0; i<99997; ++i) {
        
    //     int n = primes[i];

    //     //if (n%5==0) continue;

    //     int v = a(n);
        
    //     if (v >= 1000000) {
    //         printf("found!:n=%d,a=%d\n", n,v);
    //         break;
    //     }
    // }
}
#endif
