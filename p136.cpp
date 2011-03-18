/*
  ans = 2544559
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int uint;

const int g_count = 50*1000000+1;

int c[g_count];

void g(uint m, uint s)
{
    uint k = (uint)sqrt(3*m);
    for (uint a=s; a<k; a+=4) {
        //uint b = (a/3&~0xF) + 4-(a%4);
        uint b = (a+1)/3;
        b = b+4-(a+b)%4;
        if (a >= 3*b) b+=4;
        for (; a*b<m; b+=4) {
            c[a*b]++;
        }
    }
}

int main()
{
    g(g_count, 1);
    g(g_count, 2);
    g(g_count, 3);
    g(g_count, 4);

//    printf("%d\n", c[1155]);
    int count=0;
    for (uint i=1; i<g_count; ++i) {
        if (c[i]==1) ++count;
    }
    printf("%d\n", count);
    return 0;
}
