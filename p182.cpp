#include <stdio.h>
#include <stdlib.h>

#define TBLSZ   60

#define PHI 3671136

int tbl[TBLSZ];
int tbl_weigh[TBLSZ];

int gcd(int u, int v)
{
    if(u == v)
        return v;
    if(u == 0)
        return v;
    if(v == 0)
        return u;
    if(u%2 == 0){ // if u is even
        if(v%2 == 0) // if u and v are even
            return (2*gcd(u/2, v/2));
        else // u is even and v is odd
            return  gcd(u/2, v);
    }
    else if(v%2 == 0) // if u is odd and v is even
        return gcd(u, v/2);
    else{ // both are odd
        if(u>=v)
            return gcd((u-v)/2, v);
        else
            return gcd((v-u)/2, u);
    }
}

int read_tbl()
{
    FILE *fp = fopen("e:\\t.csv", "r");
    int i=0;
    while (!feof(fp)) {
        fscanf(fp, "%d,%d", &tbl[i], &tbl_weigh[i]);
        ++i;
    }
    fclose(fp);
}

int check(int e)
{
    int c=0;

    for (int j=0; j<TBLSZ; ++j) {
        if (e % tbl[j] != 1) {
            c += tbl_weigh[j];
        }
    }
    return c;
}

int main()
{
    read_tbl();

    for (int i=2; i<PHI; ++i) {
        if (gcd(i,PHI)==1) {
            int c = check(i);
            printf("%d,%d\n", i, c);
        }
    }
}
