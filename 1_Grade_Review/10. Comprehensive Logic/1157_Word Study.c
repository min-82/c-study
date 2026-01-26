#include <stdio.h>

int main()
{
    int max = -1, max_num, Alphabet[26] = {0};
    char arr[1000];
    scanf("%s", arr);

    // UNICODE: (A~Z -> 65~90), (a~z -> 97~122)
    for(int i=0; arr[i] != '\0'; i++){
        char c = arr[i];

        if(c >= 'A' && c <= 'Z')
            Alphabet[c - 'A']++;

        else if(c >= 'a' && c <= 'z')
            Alphabet[c - 'a']++;        
    }

    for(int i=0;i<26;i++){
        if(Alphabet[i]>max){
            max_num = 65+i;
            max = Alphabet[i];
        }

        else if(Alphabet[i]==max){
            max_num = 63;
        }
    }

    printf("%c", max_num);

    return 0;
}