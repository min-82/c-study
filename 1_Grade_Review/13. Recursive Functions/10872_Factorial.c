#include <stdio.h>

int Factorial(int num)
{
    if(num==0)
        return 1;
    if(num==1)
        return 1;
    else
        return Factorial(num-1)*num;
}

int main()
{
    int num;
    scanf("%d", &num);

    printf("%d", Factorial(num));

    return 0;
}