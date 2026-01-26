#include <stdio.h>

int pow_(int a)
{
    int p = 1;
    for(int i=1;i<a;i++){
        p = p*10;
    }
    return p;
}

int self_number(int a)
{
    int sum = a;

    int m = 0;
    for(int i=1;a/i != 0;i*=10){
        m++;
    }
    for(int i=pow_(m);i != 0;i/=10){
        sum = sum + a/i;
        a = a - a/i*i;
    }

    return sum;
}

int main()
{
    int num[10001], check;
    
    for(int i=1;i<10001;i++){
        check = self_number(i);
        if(check<10001)
            num[check] = 1;
    }

    for(int i=1;i<10001;i++){
        if(num[i] != 1)
        printf("%d\n", i);
    }

    return 0;
}