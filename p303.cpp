/*
  f(2)=2, f(3)=12, f(7)=21, f(42)=210, f(89)=1121222.
*/

#include <stdio.h>

#include <deque>

typedef unsigned __int64 uint64;

#define DIGITS_LIMIT 23

int digits[100] = {0};

void next_num(int *digits)
{
    int carry = 1;
    for (int i=0; i<=DIGITS_LIMIT; ++i) {
        int e = digits[i] + carry;
        
        digits[i] = e % 3;
        carry = e / 3;
    }
}

void print_num(int *digits)
{
    for (int i=0; i<=DIGITS_LIMIT; ++i) {
        printf("%d", digits[i]);
    }
    printf("\n");
}

uint64 f(int n)
{
    for (int i=0; i<=DIGITS_LIMIT; ++i)
        digits[i] = 0;
    digits[0] = 1;

    uint64 count = 1;

    for (;;) {
        //print_num(digits);

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

    // uint64 sum(0);
    // for (int i=1; i<=NUMBER_LIMIT; ++i) {
    //     sum += table[i]/i;

    //     std::cout << table[i] << "\n";
    // }

    return 0;
}
