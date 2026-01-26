#include <stdio.h>
#include <string.h>

void fill(int c, int r, int (*a)[100])
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            a[c+i][r+j] = 1;
        }
    }
}

int main()
{
    int arr[100][100];
    int n, column, row, count = 0;

    memset(arr, 0, sizeof(arr));

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &column, &row);
        fill(column, row, arr);
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j] == 1)
                count++;
        }
    }

    printf("%d", count);

    return 0;
}