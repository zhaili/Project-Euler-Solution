#include <set>
#include <cstdio>

using namespace std;

const int N = 10000;

int fraglen(int p)
{
    int a, cnt;
    set<int> remain;

    a = 1, cnt=0;
    do {
        remain.insert(a);
        cnt++;
        a = (a*10)%p;
    } while(a && remain.count(a)==0);
    return cnt;
}

int main()
{
    int i, maxlen=0, maxpos;
    for (i=1; i<N; ++i) {
        int l = fraglen(i);
        if (l>maxlen) {
            maxlen = l;
            maxpos = i;
        }
        //printf("%d\n", l);
    }
    printf("maxpos:%d,maxlen:%d", maxpos, maxlen);
    return 0;
}
