#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nCom, nConnect;
vector<int> infra[10001];
bool isVisited[10003];

int dfs(int c);
void initVisited();

int main()
{
	int c1, c2;
	scanf("%d %d", &nCom, &nConnect);
	for (int i = 0; i < nConnect; i++) {
		scanf("%d %d", &c1, &c2);
		infra[c2].push_back(c1);
	}

	int maxCom = 0;
	int hackCount[10003];
	for (int i = 1; i <= nCom; i++) {
		hackCount[i] = dfs(i);
		maxCom = max(maxCom, hackCount[i]);
		initVisited();
	}

	for (int i = 1; i <= nCom; i++) {
		if (hackCount[i] == maxCom)
			printf("%d ", i);
	}

	return 0;
}

int dfs(int c)
{
	int count = 0, next;
	isVisited[c] = true;
	for (int i = 0; i < infra[c].size(); i++) {
		next = infra[c][i];
		if (!isVisited[next]) {
			count += dfs(next);
		}
	}

	return count + 1;
}

void initVisited()
{
	for (int i = 1; i <= nCom; i++)
		isVisited[i] = false;
}
