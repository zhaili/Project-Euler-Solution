#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

typedef __int64 int64;

#define lengthof(_array) (sizeof(_array)/sizeof(_array[0]))

int64 solutions[][2] = {{1, 2}, {2, 3}, {1, 4}, {2, 5}, {1, 6}, {4, 5}, {2, 7}, {5, 6}, {3, 8}, {5, 8}, {4, 9}, {1, 10}, {3, 10}, {7, 8}, {4, 11}, {7, 10}};

int64 sum = 0;

void traval(int pos, int64 u, int64 v)
{
    if (pos==16) {
        sum += min(abs(u),abs(v));
        //printf("u=%I64d,v=%I64d\n", u, v);
        return;
    }
    traval(pos+1, u, v);

    int64 a = solutions[pos][0];
    int64 b = solutions[pos][1];

    int64 x = a*u - b*v;
    int64 y = a*v + b*u;
    traval(pos+1, x, y);

    x = a*u + b*v;
    y = b*u - a*v;
    traval(pos+1, x, y);
}

int main()
{
    for (int i=0; i<16; ++i)
        traval(i+1, solutions[i][0], solutions[i][1]);

    printf("sum=%I64d\n", sum);

    return 0;
}
