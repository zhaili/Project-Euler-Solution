#include <stdio.h>
#include <time.h>
#include <math.h>

#include <vector>
#include <set>
#include <complex>

using namespace std;

#define LIM 1000000

int min_sum=((1u<<31)-1);

#define ARYLIM 10000

int ma[ARYLIM], mb[ARYLIM];
int size=0;

// struct mycmp {
//     bool operator() (const pair<int,int>& a, const pair<int,int>& b)
//     {
//         if (a.second == b.second) return (a.first < b.first);
//         else return (a.second < b.second);
//     }
// };

void triple()
{
    int sqlim = sqrt(LIM);
    set<pair<int,int> > tpset;

    for (int n=1; n<sqlim; ++n)
    {
        for (int m=n+1; m<sqlim; ++m)
        {
            int a = m*m-n*n;
            int b = 2*m*n;
            int c = m*m+n*n;

            int ka=a,kb=b,kc=c;
            while (kc < sqlim) {
                tpset.insert(pair<int,int>(kc,ka));
                tpset.insert(pair<int,int>(kc,kb));

                ka += a;
                kb += b;
                kc += c;
            }
        }
    }

    int cnt=0;
    set<pair<int,int> >::iterator it = tpset.begin();
    for (; it!=tpset.end(); ++it) {
        mb[cnt] = (it->first)*(it->first);
        ma[cnt] = (it->second)*(it->second);
        ++cnt;
    }
    size = cnt;
}

bool issq(int n)
{
    int sq = (int)sqrt(n);
    return (sq*sq == n);
}

void search()
{
    for (int z=1; z<=LIM-2;++z)
    {
        for (int i=0; i<size; ++i)
        {
            int x = z+mb[i];
            if (x>LIM) break;

            int y = z+ma[i];

            if (issq(x+y) &&
                issq(x+z) &&
                issq(y+z))
            {
                printf("%d,%d,%d\n", x,y,z);
                int sum = x+y+z;
                if (sum < min_sum) min_sum=sum;
            }
        }
    }
}

int main()
{
    int start = clock();

    triple();
    //printf("size=%d\n", size);

    search();
    printf("min=%d\n",min_sum);

    int finish = clock();
    printf("time:%fms\n", 1000*((float)finish-start)/CLOCKS_PER_SEC);

    return 0;
}
