#include <stdio.h>

int hansu(int a)
{
    int s[4]={0}, i=3;

    while(i>=0)
    {
        s[i] = a%10;
        a /= 10;

        i--;
    }

    if(s[1] != 0){
        if(2*s[2] == s[1]+s[3])
            return 1;

        else
            return 0;
    }

    if(s[0]==1)
        return 0;

    return 1;
}

int main()
{
    int num, count=0;
    scanf("%d", &num);

    for(int i=1;i<=num;i++){
        count += hansu(i);
    }

    printf("%d", count);

    return 0;
}