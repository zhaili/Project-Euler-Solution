/*
  g++ -o p152 -O2 p152.cpp -Ie:/ntl/include e:/ntl/src/ntl.a
 */

#include <ctime>

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

#include <NTL/ZZ.h>
NTL_CLIENT

using namespace std;

void sum(const ZZ& a, const ZZ& b, int k, ZZ& na, ZZ& nb)
{
    ZZ n = b+a*k*k;
    ZZ d = b*k*k;

    ZZ g = GCD(n,d);

    n /= g;
    d /= g;

    na = n;
    nb = d;
}

#define NUM 80
#define LIM 11
int prime[] = {37, 31, 29, 23, 19, 17, 13, 11, 7, 5, 3};
int p2[6] = {2, 4, 8, 16, 32, 64};

vector<int> sqlist;
vector<vector<int> > sumsqlist;

vector<pair<ZZ,ZZ> > sumsq;
std::set<pair<ZZ, ZZ> > sumsq2;

void dfs(int last, int d, const ZZ& a, const ZZ& b)
{
	if (last>=LIM) {
        sumsq.push_back(pair<ZZ,ZZ>(a,b));

		vector<int> l(sqlist);
		sort(l.begin(), l.end());
        sumsqlist.push_back(l);
		return;
	}
	if (prime[last]*d > NUM) {
		return;
	}

    dfs(last, d+1, a, b);

    bool added = false;
    for (int i=0; i<last; ++i) {
        if (d%prime[i]==0) { added=true; return; }
    }
    if (!added) {           // d not added before
        ZZ na, nb;
        sum(a, b, d*prime[last], na, nb);

        sqlist.push_back(d*prime[last]);
        dfs(last, d+1, na, nb);

        for (int i=last; i<LIM; ++i) {
            if (nb%prime[i]==0) break; 
            dfs(i+1, 1, na, nb);
        }
        sqlist.pop_back();
    }
}

void dfs2(int d, const ZZ& a, const ZZ& b)
{
    if (d==6) {
        sumsq2.insert(pair<ZZ,ZZ>(-a,b));
        return;
    }

    ZZ na, nb;
    sum(a,b, p2[d], na, nb);

    dfs2(d+1, na, nb);
    dfs2(d+1, a, b);
}

int main()
{
    int start = clock();

    dfs2(0, to_ZZ(-1), to_ZZ(2));

	for (int i=0; i<LIM; ++i)
        dfs(i, 1, to_ZZ(0), to_ZZ(1));

    int cnt=0,i=0;
    for (vector<pair<ZZ,ZZ> >::iterator it=sumsq.begin();it!=sumsq.end();++it) {
        if (sumsq2.count(*it)) {
            // for (vector<int>::iterator its=sumsqlist[i].begin();its!=sumsqlist[i].end();++its) {
            //     cout << *its << "," ;
            // }
            // cout << endl;

            ++cnt;
        }
        ++i;
    }
    cout << "cnt=" << cnt << endl;

    int finish = clock();
    cout << "time:" << 1000*((float)finish-start)/CLOCKS_PER_SEC << "ms\n";
    return 0;
}
