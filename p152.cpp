#include <stdio.h>
#include <stdlib.h>

#include <list>

//#define b 35

/* (s, i) */
typedef std::pair<int, int> elem;
typedef std::list<elem> tbl;

int v[] = {1587600, 705600, 396900, 254016, 176400, 129600, 99225, 78400, 63504};

void print(const tbl& l)
{
    for (tbl::const_iterator it=l.begin(); it!=l.end(); ++it) {
        printf("(%d,%d)-", it->first, it->second);
    }
    printf("\n");
}

void trans(tbl& a, int j)
{
    tbl c;
    for (tbl::iterator it=a.begin(); it!=a.end(); ++it) {
        c.push_back(elem(it->first+j, it->second));
    }

    //print(c);

    tbl::iterator ita = a.begin();
    tbl::iterator itc = c.begin();

    for (; ita!=a.end(); ++ita) {
        for (; itc!=c.end(); ++itc) {
            if (itc->first < ita->first) {
                a.insert(ita, *itc);
            }
            else if (itc->first == ita->first) {
                ita->second += itc->second;
            }
            else {
                break;
            }
        }
    }
    if (itc!=c.end())
        a.insert(ita, itc, c.end());
}

int main()
{
    tbl a;
    a.push_back(elem(0,1));

    for (int j=0; j<9; ++j)
        trans(a, v[j]);

    print(a);
}
