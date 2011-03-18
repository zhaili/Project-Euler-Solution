#include <stdio.h>
#include <stdlib.h>

int c=0;
unsigned int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
                    59, 61, 67, 71, 73, 79, 83, 89, 97};
int r = 1e9;
int len = 25;

void dfs(unsigned long long prod, unsigned int last)
{
    int k;
    if(prod <= r) {
        c++;
        for (k=last; k<len; ++k) {
            dfs(prod*p[k], k);
        }
    }
}

int main()
{
    dfs(1, 0);
    printf("%d", c);
}
