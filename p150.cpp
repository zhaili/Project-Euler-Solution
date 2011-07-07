#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define LIM 6
#define LIM 1000

int trig[LIM][LIM] = {0};

// int trig[LIM][LIM] = {
//    {15},
//    {-14, -7},
//    {20, -13, -5},
//    {-3, 8, 23, -26},
//    {1, -4, -5, -18, 5},
//    {-16, 31, 2, 9, 28, 3}
// };

void gen_trig()
{
    __int64 t = 0;
	int c=0;
    for (int i=0; i<LIM; ++i) {
        for (int j=0; j<=i; ++j) {
            t = (615949*t + 797807) % (1<<20);
            trig[i][j] = t - (1<<19);
        }
    }
}

__int64 parsum[LIM] = {0};
int parlen[LIM] = {0};
__int64 min = 0;


void find_sum(int i, int j, int len)
{
    __int64 s = 0;
    
    for (; len > 0; --len) {

        for (int k=parlen[i]; k<len; ++k) {
            parsum[i] += trig[i][j+k];
        }
        parlen[i] = len;

        s += parsum[i];
        if (s > 0) s = 0;

        // go to up level
        --i;
    }

    if (s < min) min = s;
}

int main()
{
    int start = clock();

    gen_trig();

    for (int j=0; j<LIM; ++j) {
        
        for (int k=0; k<LIM; ++k) {
            parlen[k] = 0;
            parsum[k] = 0;
        }

        for (int len=1; len<=LIM-j; ++len)
            find_sum(LIM-1, j, len);
    }

    printf("%I64d\n", min);

    int finish = clock();
    printf("time:%fms", 1000*((float)finish-start)/CLOCKS_PER_SEC);

    return 0;
}
