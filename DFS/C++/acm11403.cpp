#include <iostream>

void dfs(int v);
void printVisited();
void initVisited();

int n;
int graph[105][105] = {0};
int isVisited[105] = {0};

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);

	for (int i = 0; i < n; i++) {
		dfs(i);
		printVisited();
		initVisited();
	}

	return 0;
}

void dfs(int v)
{
	for (int i = 0; i < n; i++) {
		if (graph[v][i] && !isVisited[i]) {
			isVisited[i] = 1;
			dfs(i);
		}
	}
}

void printVisited()
{
	for (int i = 0; i < n; i++)
		printf("%d ", isVisited[i]);
	printf("\n");
}

void initVisited()
{
	for (int i = 0; i < n; i++)
		isVisited[i] = 0;
}
