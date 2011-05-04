#include <stdio.h>
#include <cmath>

#include <list>

using namespace std;

typedef __int64 int64;

void f(int64 a1, int64 a2, int64 b1, int64 b2, int64* c1, int64* c2)
{
    int64 u = a1*b1 + a2*b2;
    int64 v = abs(a1*b2 - a2*b1);

    *c1 = min(u,v);
    *c2 = max(u,v);
}


void g(int64 a1, int64 a2, int64 b1, int64 b2, int64* c1, int64* c2)
{
    int64 u = a1*b2 + a2*b1;
    int64 v = abs(a1*b1 - a2*b2);

    *c1 = min(u,v);
    *c2 = max(u,v);
}

typedef pair<int64,int64> pair64;

#define lengthof(_array) (sizeof(_array)/sizeof(_array[0]))

void traval(list<pair64> &l, int64 a1, int64 a2)
{
    list<pair64> nl;

    nl.push_back(pair64(a1,a2));

    list<pair64>::iterator it;
    for (it=l.begin();it!=l.end();++it) {
        const pair64& e = *it;
        int64 u,v;

        f(e.first, e.second, a1, a2, &u,&v);
        nl.push_back(pair64(u,v));

        g(e.first, e.second, a1, a2, &u,&v);
        nl.push_back(pair64(u,v));
    }

    l.splice(l.end(), nl);
}

int64 solutions[][2] = {{1, 2}, {2, 3}, {1, 4}, {2, 5}, {1, 6}, {4, 5}, {2, 7}, {5, 6}, {3, 8}, {5, 8}, {4, 9}, {1, 10}, {3, 10}, {7, 8}, {4, 11}, {7, 10}};

int main()
{
    list<pair64> l;
    for (int i=0; i<lengthof(solutions); ++i) {
        traval(l, solutions[i][0], solutions[i][1]);
    }

    unsigned __int64 sum = 0;

    list<pair64>::iterator it;
    for (it=l.begin();it!=l.end();++it) {
        //printf("{%I64d,%I64d},", it->first, it->second);
        sum += it->first;
    }

    printf("sum=%I64d\n", sum);

    return 0;
}
