#include <stdio.h>
int main()
{
    int a, b;
    int b1, b2, b3, a1, a2, a3;

    scanf("%d\n%d", &a, &b);

    b1 = b/100;
    b2 = (b - b1*100)/10;
    b3 = (b - b1*100 - b2*10);

    a3 = a*b3;
    a2 = a*b2;
    a1 = a*b1;

    printf("%d\n%d\n%d\n", a3, a2, a1);
    printf("%d\n", a3+a2*10+a1*100);

    return 0;

}