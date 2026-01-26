#include <stdio.h>

int main()
{
    int a,b,c,d;
    scanf("%d %d\n%d", &a,&b,&c);
    d = b+c;

    for(;d >= 60;d -= 60){
        a++;
    }

    if(a >= 24)
        printf("%d %d", a-24,d);

    else
        printf("%d %d", a,d);
    
    return 0;
}