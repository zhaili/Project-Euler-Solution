// #include <stdio.h>
#include <iostream>

#include <deque>
#include <list>

#include <gmpxx.h>

// typedef unsigned __int64 uint64;

#define NUMBER_LIMIT 1000

mpz_class table[NUMBER_LIMIT+1] = {0};

std::deque<mpz_class> queue;

std::list<int> rest;

void init()
{
    for (int i=1; i<=NUMBER_LIMIT; ++i)
        rest.push_back(i);
}

bool check(mpz_class c)
{
    std::list<int>::iterator it;

    for (it=rest.begin(); it!=rest.end(); ) {
        int elem = *it;
        if (c % elem==0) {
            table[elem] = c;

            it = rest.erase(it);
        }
        else {
            ++it;
        }
    }

    return rest.empty();
}

// bool check(mpz_class c)
// {
//     bool flag = false;
//     for (int i=1; i<=limit; ++i) {
//         if (table[i]==0) {
//             flag = true;
//             if (c%i==0) table[i] = c;
//         }
//     }

//     return flag;
// }

void f()
{
    init();
    queue.push_back(1);
    queue.push_back(2);

    unsigned __int64 count=0;
    
    for (;;) {

        if (queue.empty()) break;

        mpz_class c = queue.front();
        queue.pop_front();

        if (check(c)) break;

        if (count <= 28697814)
        {
            c = c*10;
            queue.push_back(c);
            queue.push_back(c+1);
            queue.push_back(c+2);
        }
        count++;
    }
}

int main()
{
    f();

    std::cout << "----------------------------------------------------------------\n";

    mpz_class sum(0);
    for (int i=1; i<=NUMBER_LIMIT; ++i) {
        sum += table[i]/i;

        std::cout << table[i] << "\n";
    }

    std::cout << "----------------------------------------------------------------\n";

    std::cout << sum << "\n";

    return 0;
}
