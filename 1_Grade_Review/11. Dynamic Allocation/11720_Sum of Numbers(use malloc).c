#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum=0;
    char *s;

    scanf("%d", &n);

    s = (char*)malloc(sizeof(char)*(n+1));

    scanf("%s", s);

    for(int i=0;i<n;i++){
        sum += (s[i] - '0');
    }

    printf("%d", sum);

    free(s);

    return 0;
}