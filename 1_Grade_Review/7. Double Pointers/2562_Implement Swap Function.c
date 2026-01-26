#include <stdio.h>

void swap(int *a, int *b, int *c)
{
    if(a>b)
        c = a;
    
    else
        c = b;
}

int main()
{
    int big, b_num, num[9];
    int *ptr_num = num;
    for(int i=0;i<9;i++)
        scanf("%d", num+i);

    for(int i=0;i<9-1;i++){
        swap(num+i, num+i+1, &big);
    }
    

    return 0;
}