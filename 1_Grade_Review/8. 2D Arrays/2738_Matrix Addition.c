#include <stdio.h>

void matrix(int n, int m, int (*a)[100])
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &a[i][j]);
        }
    }
}

int main()
{
    int n, m;
    int num1[100][100], num2[100][100];
    scanf("%d %d", &n, &m);

    matrix(n, m, num1);
    matrix(n, m, num2);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d", num1[i][j] + num2[i][j]);

            if (j < n - 1) { 
            printf(" ");
            }  
        }
        printf("\n");
    }

    return 0;
}