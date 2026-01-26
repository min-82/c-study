#include <stdio.h>

int main()
{
    int al[26];
    char arr[100];
    char *ptr_arr = arr;

    for(int i=0;i<26;i++)
        al[i] = -1;
    scanf("%s", ptr_arr);

    for(int i=0;ptr_arr[i] != '\0';i++){
        if(al[ptr_arr[i] - 'a'] == -1)
            al[ptr_arr[i] - 'a'] = i;
    }

    for(int i=0;i<26;i++)
        printf("%d ", al[i]);

    return 0;
}