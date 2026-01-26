#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    for(int i=num;i>0;i--){
        for(int a=i-1;a>0;a--){
            printf(" ");
        }
        for(int b=num-i+1;b>0;b--){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}