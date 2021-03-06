#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <algorithm>

//using namespace std;

using std::vector;

typedef unsigned __int64 int64;

#define N 6

int tbl[] = {10, 5, 2, 1, 1, 1};

unsigned int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 53, 61, 67, 71, \
73, 79, 89, 97, 101, 109, 113, 127, 131, 151, 157, 163, 181, 193, \
199, 211, 241, 257, 271, 281, 313, 331, 337, 353, 379, 397, 401, 421, \
433, 449, 463, 487, 521, 541, 547, 577, 601, 617, 631, 641, 661, 673, \
701, 757, 769, 811, 859, 881, 911, 937, 991, 1009, 1051, 1093, 1153, \
1171, 1201, 1249, 1297, 1301, 1321, 1409, 1601, 1621, 1783, 1801, \
1873, 1951, 2003, 2017, 2081, 2113, 2161, 2269, 2311, 2341, 2377, \
2521, 2593, 2689, 2731, 2801, 2861, 2971, 3121, 3169, 3301, 3329, \
3361, 3433, 3457, 3511, 3697, 3851, 3889, 4051, 4159, 4201, 4481, \
4621, 4801, 4861, 4951, 4993, 5281, 5347, 5851, 6007, 6301, 6337, \
6481, 6553, 7129, 7151, 7393, 7489, 7561, 7681, 7723, 8009, 8101, \
8191, 8317, 8581, 8641, 8737, 9241, 9601, 9721, 9829, 9857, 9901, \
10369, 10531, 10753, 11551, 11701, 12097, 12601, 12637, 13313, 13441, \
13729, 14081, 14401, 14561, 14851, 15121, 15361, 15401, 15601, 16381, \
16633, 17011, 17551, 17921, 18481, 19009, 19441, 19801, 20021, 20161, \
20593, 21061, 21121, 21601, 21841, 23041, 23167, 23297, 23761, 24571, \
25601, 25741, 26209, 26731, 26881, 27457, 28081, 28351, 28513, 29569, \
30241, 32257, 32401, 33601, 34651, 35201, 36037, 37423, 37441, 38611, \
39313, 39937, 42901, 43201, 45361, 47521, 48049, 49921, 50051, 51481, \
54601, 55441, 56701, 57601, 62401, 63361, 64513, 65521, 66529, 68041, \
69499, 70201, 72073, 72577, 76801, 77761, 79201, 81901, 84481, 89101, \
92401, 93601, 96097, 96769, 98561, 99793, 100801, 101089, 101377, \
103681, 103951, 105601, 106921, 108109, 109201, 110881, 115201, \
115831, 117937, 118273, 118801, 119809, 120121, 123553, 131041, \
134401, 138241, 140401, 145601, 149689, 150151, 151201, 155521, \
157951, 161281, 168481, 170101, 172801, 174721, 177409, 180181, \
183041, 187111, 192193, 193051, 196561, 200201, 210601, 216217, \
218401, 219649, 228097, 231661, 232961, 241921, 257401, 259201, \
267301, 270271, 277993, 279553, 285121, 299521, 300301, 311041, \
314497, 316801, 329473, 332641, 336961, 340201, 345601, 368551, \
393121, 394241, 411841, 414721, 415801, 419329, 427681, 432433, \
436801, 450451, 453601, 456193, 463321, 498961, 534601, 540541, \
549121, 576577, 589681, 600601, 604801, 617761, 628993, 648649, \
673921, 680401, 684289, 739201, 748441, 748801, 760321, 786241, \
800801, 838657, 898561, 950401, 960961, 982801, 985601, 988417, \
1010881, 1029601, 1088641, 1105651, 1108801, 1153153, 1158301, \
1201201, 1247401, 1281281, 1297297, 1389961, 1397761, 1425601, \
1451521, 1621621, 1647361, 1684801, 1747201, 1769041, 1830401, \
1853281, 1921921, 1995841, 2073601, 2138401, 2177281, 2223937, \
2358721, 2395009, 2402401, 2534401, 2702701, 2903041, 3088801, \
3144961, 3474901, 3548161, 3742201, 3843841, 3991681, 4324321, \
4354561, 4612609, 4633201, 5241601, 5660929, 5702401, 5913601, \
5930497, 6652801, 6842881, 7484401, 7603201, 7783777, 7983361, \
8236801, 8709121, 8845201, 8870401, 9225217, 9609601, 10108801, \
10378369, 10483201, 10886401, 11119681, 11531521, 11860993, 12579841, \
12812801, 13305601, 13478401, 13899601, 14414401, 18869761, 19768321, \
22239361, 22643713, 22809601, 27675649, 28304641, 28828801, 29652481, \
29937601, 34594561, 37739521, 39916801, 40435201, 43243201, 46126081, \
47900161, 59875201, 76876801, 97297201, 98841601, 111196801, \
113218561, 141523201, 172972801, 194594401, 389188801, 566092801, \
    1037836801, 1556755201, 3113510401U};

int count = 0;

int check()
{
    int c = 0;
    for (int i=0; i<N; ++i) {
        if (tbl[i] < 0) {
            return -1;
        }
        else if (tbl[i] == 0) {
            ++c;
        }
    }

    return ((c==N) ? 0 : 1);
}

bool uptbl_1(unsigned int p)
{
    while (p%2==0) {
        p /= 2;
        tbl[0]--;
    }
    while (p%3==0) {
        p /= 3;
        tbl[1]--;
    }
    while (p%5==0) {
        p /= 5;
        tbl[2]--;
    }
    while (p%7==0) {
        p /= 7;
        tbl[3]--;
    }
    while (p%11==0) {
        p /= 11;
        tbl[4]--;
    }
    while (p%13==0) {
        p /= 13;
        tbl[5]--;
    }

    return (p==1);
}

bool uptbl_2(unsigned int p)
{
    while (p%2==0) {
        p /= 2;
        tbl[0]++;
    }
    while (p%3==0) {
        p /= 3;
        tbl[1]++;
    }
    while (p%5==0) {
        p /= 5;
        tbl[2]++;
    }
    while (p%7==0) {
        p /= 7;
        tbl[3]++;
    }
    while (p%11==0) {
        p /= 11;
        tbl[4]++;
    }
    while (p%13==0) {
        p /= 13;
        tbl[5]++;
    }

    return (p==1);
}

vector<int64> ll;

void dfs(int i, int c, int64 prd)
{
    if (i < 6) {
        if (c==1) {             // c == 1
            int succ = uptbl_1(p[i]-1);
            
            if (succ) {
                int v = check();
                if (v==0) {
                    ll.push_back(prd*p[i]);
                    ++count;
                }
                else if (v>0) {
                    dfs(i, c+1, prd*p[i]);
                    dfs(i+1, 1, prd*p[i]);
                }
            }
            uptbl_2(p[i]-1);

            dfs(i+1, 1, prd);
        }
        else {       // c > 1
            tbl[i]--;

            int v = check();
            if (v>0) {
                dfs(i, c+1, prd*p[i]);
                dfs(i+1, 1, prd*p[i]);
            }
            else if (v==0) {
                //printf("%I64d\n", prd*p[i]);
                ll.push_back(prd*p[i]);
                ++count;
            }

            tbl[i]++;
        }
    }
    else if (i < 459) {
        int succ = uptbl_1(p[i]-1);

        if (succ) {
            int v = check();
            if (v>0) {
                dfs(i+1, 1, prd*p[i]);
            }
            else if (v==0) {
                //printf("%I64d\n", prd*p[i]);
                ll.push_back(prd*p[i]);
                ++count;
            }
        }
        
        uptbl_2(p[i]-1);

        dfs(i+1, 1, prd);
    }

}

int main()
{
    dfs(0, 1, 1);
    printf("count=%d\n", count);

    sort(ll.begin(), ll.end());

    //for (vector<int64>::iterator it=ll.begin(); it!=ll.end(); ++it) {
    //    printf("%I64d\n", *it);
    //}

    printf("ans:%I64d\n", *(ll.begin() + 150000-1));

    return 0;
}
