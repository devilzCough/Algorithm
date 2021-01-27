#include <iostream>

void dfs(int s);
void bfs();
void initVisited();

int isVisited[1005] = {0};
int graph[1005][1005] = {0};
int nVertex, nEdge, startV;

int queue[1002] = {0};
int front = 1, end = 2;

int main()
{
	int x, y;
	scanf("%d %d %d", &nVertex, &nEdge, &startV);
	isVisited[startV] = 1;
	for (int i = 0; i < nEdge; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	dfs(startV);
	printf("\n");
	initVisited();

	isVisited[startV] = 1;
	queue[front] = startV;
	bfs();

	return 0;
}

void dfs(int s)
{
	printf("%d ", s);
	for (int i = 1; i <= nVertex; i++) {
		if (graph[s][i] == 1 && isVisited[i] == 0) {
			isVisited[i] = 1;
			dfs(i);
		}
	}
}

void bfs()
{
	int s = queue[front];
	printf("%d ", s);
	for (int i = 1; i <= nVertex; i++) {
		if (graph[s][i] == 1 && isVisited[i] == 0) {
			queue[end++] = i;
			isVisited[i] = 1;
		}
	}
	front++;
	if (front < end)
		bfs();
}

void initVisited()
{
	for (int i = 1; i <= nVertex; i++) {
		isVisited[i] = 0;
	}
}
