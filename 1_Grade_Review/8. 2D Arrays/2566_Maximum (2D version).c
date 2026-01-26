#include <stdio.h>

void find(int *c, int *r, int *m, int a[9][9])
{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j] >= *m){
                *m = a[i][j];
                *c = i+1;
                *r = j+1;
            }
        }
    }
}

int main()
{
    int column, row, max = 0;
    int num[9][9];

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d", &num[i][j]);
        }
    }

    find(&column, &row, &max, num);

    printf("%d\n%d %d", max, column, row);

    return 0;
}