#include <stdio.h>
#include <string.h>

typedef struct
{
    int student;
    int score[1001];
    double average;
    double percent;
}Grade;

int main()
{
    int n;
    Grade g[1001];

    scanf("%d", &n);

    for(int i=0;i<n;i++){
        int sum=0;
        scanf("%d", &g[i].student);
        for(int j=0;j<g[i].student;j++){
            scanf("%d", &g[i].score[j]);
            sum += g[i].score[j];
        }
        g[i].average = (double)sum/g[i].student;
    }

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<g[i].student;j++){
            if(g[i].score[j] > g[i].average)
                count++;
        }
        g[i].percent = (double)count/g[i].student*100.0;
    }

    for(int i=0;i<n;i++)
        printf("%.3f%%\n", g[i].percent);

    return 0;
}