#include <iostream>
#include <algorithm>

int n, m, s;
int connects[105][105];
int isVisited[105];

void dfs(int v);
int sumConnects();
void initVisited();

int main()
{
	int n1, n2;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &n1, &n2);
		connects[n1][n2] = 1;
		connects[n2][n1] = 1;
	}

	int total, minCB = 9999, minId;
	for (s = 1; s <= n; s++) {
		dfs(s);
		total = sumConnects();
		if (minCB > total) {
			minCB = total;
			minId = s;
		}
		initVisited();
	}

	printf("%d\n", minId);
	return 0;
}

void dfs(int v)
{
	for (int i = 1; i <= n; i++) {
		if (connects[v][i] && i != s) {
			if (!isVisited[i] || (isVisited[i] && isVisited[i] > isVisited[v]+1)) {
				isVisited[i] = isVisited[v] + 1;
				dfs(i);
			}
		}
	}
}

int sumConnects()
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += isVisited[i];

	return sum;
}

void initVisited()
{
	for (int i = 1; i <= n; i++)
		isVisited[i] = 0;
}
