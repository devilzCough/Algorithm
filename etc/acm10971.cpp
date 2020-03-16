#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int start, int cur, int cnt);


int N;
int w[11][11];
int visit[11];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &w[i][j]);

	printf("%d\n", dfs(0, 0, 0));

	return 0;
}

int dfs(int start, int cur, int cnt)
{
	if(cnt == N-1 && cur == start) return 0;

	int minP = 1000001;
	for (int i = 0; i < N; i++) {
		if (i != cur && !visit[i]){
			visit[i] = 1;
			cnt++;
			minP = min(minP, w[cur][i] + dfs(start, i, cnt));
			cnt--;
			visit[i] = 0;
		}
	}
	return minP;
}
