/*
  f(2)=2, f(3)=12, f(7)=21, f(42)=210, f(89)=1121222.
*/

#include <stdio.h>

#include <deque>

typedef unsigned __int64 uint64;

#define DIGITS_LIMIT 23

int digits[100] = {0};

uint64 f(int n)
{
    
}

uint64 f(int n)
{
    for (int i=0; i<=DIGITS_LIMIT; ++i)
        digits[i] = 0;
    digits[0] = 1;

    uint64 count = 1;

    for (;;) {

        int c=0;
        for (int i=DIGITS_LIMIT-1; i>=0; --i) {
            c = (c*10+digits[i])%n;
        }
        if (c==0) break;

        next_num(digits);
        count++;
    }
    
    return count;
}

int main()
{
    uint64 s = f(9999);
    printf("%I64u\n", s);

    return 0;
}
