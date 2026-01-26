#include <stdio.h>
#include <math.h>

int main()
{
    int digit, num1=0 ,num2=0;
    char arr[2][3];
    char (*ptr_arr)[3] = arr;

    scanf("%s %s", ptr_arr[0],ptr_arr[1]);

    for(int i=0;i<3;i++){
        digit = ptr_arr[0][2-i] - '0';
        num1 = num1 + digit*100/pow(10,i);
    }

    for(int i=0;i<3;i++){
        digit = ptr_arr[1][2-i] - '0';
        num2 = num2 + digit*100/pow(10,i);
    }

    if(num1>num2)
        printf("%d", num1);

    else
        printf("%d", num2);

    return 0;
}