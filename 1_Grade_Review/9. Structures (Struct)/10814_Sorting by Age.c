#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int age;
    char name[101];
    int Reg_num;
} Member;

int compare_ages(const void *a, const void *b)
{
    Member *ma = (Member*)a;
    Member *mb = (Member*)b;

    if(ma->age != mb->age)
        return ma->age - mb->age;

    else
        return ma->Reg_num - mb->Reg_num;
}

int main()
{
    int n;

    Member m[1000];

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        scanf("%d %s", &m[i].age, m[i].name);
        m[i].Reg_num = i+1;
    }

    qsort(m, n, sizeof(Member), compare_ages);

    for(int i=0;i<n;i++)
        printf("%d %s\n", m[i].age, m[i].name);

    return 0;
}