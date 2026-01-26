#include <stdio.h>

int main()
{
    int n, arr[1000];
    int *ptr_n = &n;
    int *ptr_arr = arr;

    scanf("%d", ptr_n);

    for(int i=0;i<*ptr_n;i++)
        scanf("%d", ptr_arr+i);

    printf("%d\n", *ptr_n);
    for(int i=0;i<*ptr_n;i++)
        printf("%d ", *(ptr_arr+i));

    return 0;
}