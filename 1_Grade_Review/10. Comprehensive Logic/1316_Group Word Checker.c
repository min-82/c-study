#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0, n, Alphabet[26];
    char arr[101][101];

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%s", arr[i]);
    }

    for(int i=0;i<n;i++){
        memset(Alphabet,0,sizeof(Alphabet));
        Alphabet[arr[i][0] - 'a'] = 1;
        for(int j=1;arr[i][j] != '\0';j++){
            if(arr[i][j] == arr[i][j-1])
                continue;
            else if(Alphabet[arr[i][j] - 'a'] == 1){
                count++;
                break;
            }
            else
                Alphabet[arr[i][j] - 'a'] = 1; 
        }
    }

    printf("%d", n-count);

    return 0;
}