#include <stdio.h>
#include <string.h>

#define MAX 1001

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

void DFS(int n, int v);
void BFS(int n, int v);

int main()
{
    int n, m, v;
    scanf("%d %d %d", &n, &m, &v);

    int x, y;
    for(int i=0;i<m;i++){
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

	DFS(n, v);
	printf("\n");
	memset(visited, 0, sizeof(int) * (n + 1));
	BFS(n, v);

    return 0;
}

void DFS(int n, int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for(int i=1;i<=n;i++){
        if(visited[i] == 0 && graph[v][i])
            DFS(n, i);
    }
    return;
}

void BFS(int n, int v) {
	int front = -1, rear = -1, pop;
	printf("%d ", v);
	visited[v] = 1;
	queue[++rear] = v;

	while (front < rear) {
		pop = queue[++front];
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 && graph[pop][i]) {
				printf("%d ", i);
				visited[i] = 1;
				queue[++rear] = i;
			}
		}
	}
	return;
}
