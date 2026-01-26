#include <stdio.h>

int main()
{
    int t, min, max;
    int a[10000];

    scanf("%d", &t);
    for(int i=0;i<t;i++)
        scanf("%d", &a[i]);

    if(a[0]>a[1]){
        max = a[0];
        min = a[1];
    }
    else{
        max = a[1];
        min = a[0];
    }

    for(int i=2;i<t;i++){
        if(a[i]>max)
            max = a[i];
        else if(a[i]<min)
            min = a[i];
    }

    printf("%d %d", min, max);

    return 0;
}