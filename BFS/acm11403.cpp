#include <iostream>

// dfs는 메모리 초과 발생함
// void dfs(int v);
void bfs();

int n, s;
int graph[105][105] = {0};
int isVisited[105][105] = {0};

int queue[105] = {0};
int front, end;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	for (int i = 0; i < n; i++) {
		s = i;
		front = 1;
		end = 2;
		// dfs(i);
		queue[front] = i;
		bfs();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", isVisited[i][j]);
		printf("\n");
	}
	return 0;
}

void bfs()
{
	int v;
	while (front < end) {
		v = queue[front++];
		for (int i = 0; i < n; i++) {
			if (graph[v][i] == 1) {
				if (s != i || isVisited[s][i] != 1)
					queue[end++] = i;
				isVisited[v][i] = 1;
				isVisited[s][i] = 1;
			}
		}
	}
}

/*
void dfs(int v)
{

	for (int i = 0; i < n; i++) {
		if (graph[v][i] == 1) {
			isVisited[v][i] = 1;
			isVisited[s][i] = 1;
			if (s != i)
				dfs(i);
		}
	}
}
*/
