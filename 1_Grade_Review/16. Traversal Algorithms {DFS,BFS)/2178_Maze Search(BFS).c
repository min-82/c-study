#include <stdio.h>
#include <string.h>

#define MAX 101

int Maze[MAX][MAX];
int visiting_Maze[MAX][MAX];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

typedef struct Queue
{
    int v_x;
    int v_y;
} Queue;

int main()
{
    int row, column, min_count=0;
    scanf("%d %d", &row, &column);
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++)
            scanf("%1d", &Maze[i][j]);
    }

    Queue queue[MAX*MAX];

    int head=-1,rear=-1;
    int x=0,y=0;

    rear++;
    queue[rear].v_x = x;
    queue[rear].v_y = y;
    visiting_Maze[x][y] = 1;

    while(head < rear)
    {
        head++;
        x = queue[head].v_x;
        y = queue[head].v_y;
        for(int i=0;i<4;i++){
            int dir_x = dx[i];
            int dir_y = dy[i];
            if(!visiting_Maze[x + dir_x][y + dir_y] && Maze[x + dir_x][y + dir_y]){
                visiting_Maze[x + dir_x][y + dir_y] = visiting_Maze[x][y] + 1;
                rear++;
                queue[rear].v_x = x + dir_x;
                queue[rear].v_y = y + dir_y;
            }
        }
    }

    printf("%d", visiting_Maze[row-1][column-1]);

    return 0;
}