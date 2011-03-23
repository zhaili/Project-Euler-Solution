/*
  g++ -o p146 -O2 p146.cpp -Ie:/gmp/include -Le:/gmp/lib -lgmpxx -lgmp
*/

#include <stdio.h>

#include "gmpxx.h"

int f(int n)
{
    for (int i=4; i<=n; i+=2) {
        mpz_class n2(i);
        n2 *= i;

        n2 += 1;
        if (!mpz_probab_prime_p(n2.get_mpz_t(), 5)) continue;
        n2 += 2;
        if (!mpz_probab_prime_p(n2.get_mpz_t(), 5)) continue;
        n2 += 4;
        if (!mpz_probab_prime_p(n2.get_mpz_t(), 5)) continue;
        n2 += 2;
        if (!mpz_probab_prime_p(n2.get_mpz_t(), 5)) continue;
        n2 += 4;
        if (!mpz_probab_prime_p(n2.get_mpz_t(), 5)) continue;
        n2 += 14;
        if (!mpz_probab_prime_p(n2.get_mpz_t(), 5)) continue;

        printf("%d,\n", i);
    }
}

int main()
{
    int n = 150000000;
    f(n);

}
