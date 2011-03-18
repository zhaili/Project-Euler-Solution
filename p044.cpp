#include <cstdio>
#include <cstdlib>

#include <set>

using namespace std;

typedef unsigned __int64 uint64;

const int N=10000;
uint64 P[2*N+1];
set<uint64> s;

void BuildP(int n)
{
    int i;
    for (i=1; i<n; ++i) {
        P[i]=i*(3*i-1)/2;
        s.insert(P[i]);
    }
}

int main()
{
    BuildP(2*N);

    int i,j;
    for (i=1; i<N; ++i) {
        //int d = (P[i]-1)/3 + 1;
        for (j=1; j<i; ++j) {
            int m = P[i]+P[j];
            int n = P[i]-P[j];
            if (s.count(m)&&s.count(n)) printf("%d,%d\n", i, j);
        }
    }

    return 0;
}
