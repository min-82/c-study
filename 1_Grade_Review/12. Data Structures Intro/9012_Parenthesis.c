#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, *r, check;
    char c[51];

    scanf("%d", &n);

    r = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        memset(c, 0, sizeof(c));
        scanf("%s", c);
        check=0;

        for(int j=0;c[j]!='\0';j++){
            if(c[j] == '(')
                check++;
            else if(c[j] == ')')
                check--;

            if(check < 0)
                break;
        }

        if(check == 0)
            r[i] = 1;
        else
            r[i] = 0;
    }
    
    for(int i=0;i<n;i++){
        if(r[i] == 1)
            printf("%s\n", "YES");
        else
            printf("%s\n", "NO");
    }

    free(r);

    return 0;
}