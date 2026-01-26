#include <stdio.h>

int main()
{
    int t;
    int r[1000] = {0};
    char s[1000][21] = {0};

    scanf("%d", &t);
    for(int i=0;i<t;i++){
        scanf("%d %s", &r[i], s[i]);
    }

    for(int i=0;s[i][0] != 0;i++){
        for(int j=0;s[i][j] != 0;j++){
            for(int k=0;k<r[i];k++){
                printf("%c", s[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}