#include <stdio.h>

long long sum(int *a, int n)
{
    long long hap = 0;
    for(int i=0;i<sizeof(a)/sizeof(int);i++){
        hap = hap+= a[i];
    }

    return hap;
}

int main()
{
    int a[1000];
    printf("%d", sizeof(a)/sizeof(int));

    return 0;
}