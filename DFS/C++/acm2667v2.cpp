#include <iostream>
#include <algorithm>

using namespace std;

int dfs(int x, int y);
void printMap();

int n;
char village[30][30];
int nHouse[315] = {0};

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", village[i]);
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (village[i][j] == '1')
				nHouse[count++] = dfs(i, j);
		}
	}

	printf("%d\n", count);
	sort(nHouse, nHouse+count);
	for (int i = 0; i < count; i++)
		printf("%d\n", nHouse[i]);
	return 0;
}

int dfs(int x, int y)
{
	int count = 0;

	village[x][y] = '0';
	if (x-1 >= 0 && village[x-1][y]=='1')
		count += dfs(x-1, y);
	if (x+1 < n && village[x+1][y]=='1')
		count += dfs(x+1, y);
	if (y-1 >= 0 && village[x][y-1]=='1')
		count += dfs(x, y-1);
	if (y+1 < n && village[x][y+1]=='1')
		count += dfs(x, y+1);

	return count + 1;
}
