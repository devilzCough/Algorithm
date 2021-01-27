#include <iostream>

int nVertex, nEdge;
int graphs[1005][1005];
int isVisited[1005];
int count;

void dfs(int v);

int main()
{
	scanf("%d %d", &nVertex, &nEdge);
	int v1, v2;
	for (int i = 0; i < nEdge; i++) {
		scanf("%d %d", &v1, &v2);
		graphs[v1][v2] = 1;
		graphs[v2][v1] = 1;
	}

	for (int i = 1; i <= nVertex; i++) {
		if (!isVisited[i]) {
			dfs(i);
			count++;
		}
	}

	printf("%d\n", count);
	return 0;
}

void dfs(int v)
{
	isVisited[v] = 1;
	for (int i = 1; i <= nVertex; i++) {
		if (graphs[v][i] && !isVisited[i]) {
			dfs(i);
		}
	}
}
