#include <cstdio>
#include <cmath>

int istriangle(int r)
{
    double x = (-1 + sqrt(1.0+8*r))/2;
    if (abs(x-(int)x) < 1e-6) return 1;
    return 0;
}

int getascii(char* s)
{
    char *p=s;
    int sum=0;
    while (*p) {
        sum += *p-'A'+1;
        p++;
    }
    return sum;
}

int main()
{
    int i, cnt;
    char words[1024];
    FILE* fp = fopen("words.txt", "r");

    cnt = 0;
    for (i=0; i<2000; ++i) {
        fscanf(fp, "%s", words);
        cnt += istriangle(getascii(words));
    }
    printf("cnt=%d\n", cnt);
    fclose(fp);
    return 0;
}
