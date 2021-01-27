#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, nVillage = 0;
vector< vector<int> > field;

int villages[330] = {0};

int dfs(int x, int y);

int main()
{
	scanf("%d", &n);
	field.resize(n);
	for (int i = 0; i < n; i++)
		field[i].resize(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &field[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (field[i][j] == 1) {
				villages[nVillage] = dfs(i, j);
				nVillage++;
			}

	printf("%d\n", nVillage);
	sort(villages, villages + nVillage);
	for (int i = 0; i < nVillage; i++)
		printf("%d\n", villages[i]);

	return 0;
}

int dfs(int x, int y)
{
	field[x][y] = 0;

	int totalHouse = 0;
	if (x-1 >= 0 && field[x-1][y]==1) totalHouse += dfs(x-1, y);
	if (x+1 < n && field[x+1][y]==1) totalHouse += dfs(x+1, y);
	if (y-1 >= 0 && field[x][y-1]==1) totalHouse += dfs(x, y-1);
	if (y+1 < n && field[x][y+1]==1) totalHouse += dfs(x, y+1);

	return totalHouse + 1;
}
