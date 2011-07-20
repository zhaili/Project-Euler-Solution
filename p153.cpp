#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

// __int64 f(int n)
// {
//     __int64 s = 0;

//     for (int a=1; a<=n; ++a) {
//         s += n/a * a;
//     }

//     for (int a=1; a<=sqrt(n); ++a) {

//         int blim = sqrt(n-a*a);

//         for (int b=1; b<=blim; ++b) {

//             if (gcd(a,b)==1) {

//                 int c = n/(a*a+b*b);
//                 for (int j=1; j<=c; ++j) {
//                     s += j*(c/j)*(a)*2;
//                 }
//             }
//         }
//     }

//     return s;
// }

__int64 f(int n)
{
    __int64 s = 0;

    for (int a=1; a<=n; ++a) {
        s += n/a * a;
    }

    for (int a=1; a<=sqrt(n); ++a) {

        for (int b=a; b<=sqrt(n-a*a); ++b) {
            if (gcd(a,b)!=1) continue;

            int c = n/(a*a+b*b);
            for (int j=1; j<=c; ++j) {
                if (a==b) s += j*(c/j)*a*2;
                else s += j*(c/j)*(a+b)*2;
            }
        }
    }

    return s;
}


int main()
{
    int start = clock();

    printf("%I64d\n", f(100000000));
    //printf("%I64d\n", f(5));
    
    int finish = clock();
    printf("time:%fms", 1000*((float)finish-start)/CLOCKS_PER_SEC);

    return 0;
}
