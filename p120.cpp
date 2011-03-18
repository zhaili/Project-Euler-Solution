#include <stdio.h>
#include <stdlib.h>

int f(int a)
{
    int k,r;
    int max = 0;
    int sa  = a*a;;
    int kn  = (a*a-1)/2;
    r = 2*a;
    for (k=1; k<kn; ++k) {
        r += 4*a;
        r %= sa;
        if (r > max) max = r;
    }
    return max;
}

int main()
{
    int i;
    unsigned int sum=0;
    for (i=3; i<=1000; ++i) {
        sum += f(i);
    }
    printf("sum=%d", sum);
    return 0;
}
