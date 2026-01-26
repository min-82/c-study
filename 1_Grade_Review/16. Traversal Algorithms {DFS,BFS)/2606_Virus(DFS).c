#include <stdio.h>
#include <string.h>

#define MAX 101

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

void Virus_count(int c, int s, int *count);

int main()
{
    int com, net, count=0;
    scanf("%d", &com);
    scanf("%d", &net);

    int x,y;
    for(int i=0;i<net;i++){
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    Virus_count(com, 1, &count);
    printf("%d", count);

    return 0;
}

void Virus_count(int c, int s, int *count)
{
    visited[s] = 1;
    
    for(int i=2;i<=c;i++){
        if(graph[s][i] == 1 && visited[i] == 0){
            (*count)++;
            Virus_count(c, i, count);
        }
    }
}