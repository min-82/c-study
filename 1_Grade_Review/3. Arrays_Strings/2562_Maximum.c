#include <stdio.h>

int main()
{
    int max = 0, num;
    int a[9];
    for(int i=0;i<9;i++)
        scanf("%d", &a[i]);

    for(int i=0;i<9;i++){
        if(a[i]>max)
            max = a[i];
    }

    for(int i=0;i<9;i++){
        if(max == a[i])
            num = ++i;
    }

    printf("%d\n%d", max, num);

    return 0;
}