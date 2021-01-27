#include <iostream>
#include <algorithm>

using namespace std;

void checkUnsubmergedArea(int height);
void dfs(int x, int y);

int n;
int minH = 100, maxH = 0;
int maxSafeArea = 1;
int area[105][105];
int unSubmergedArea[105][105];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &area[i][j]);
			minH = min(minH, area[i][j]);
			maxH = max(maxH, area[i][j]);
		}
	}

	for (int h = minH; h < maxH; h++) {
		int count = 0;
		checkUnsubmergedArea(h);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (unSubmergedArea[i][j]) {
					dfs(i, j);
					count++;
				}
			}
		}
		maxSafeArea = max(maxSafeArea, count);
	}

	printf("%d\n", maxSafeArea);
	return 0;
}

void checkUnsubmergedArea(int height)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] <= height) {
				unSubmergedArea[i][j] = 0;
			} else {
				unSubmergedArea[i][j] = 1;
			}
		}
	}
}

void dfs(int x, int y)
{
	unSubmergedArea[x][y] = 0;
	if (x-1 >= 0 && unSubmergedArea[x-1][y]) dfs(x-1, y);
	if (x+1 < n && unSubmergedArea[x+1][y]) dfs(x+1, y);
	if (y-1 >= 0 && unSubmergedArea[x][y-1]) dfs(x, y-1);
	if (y+1 < n && unSubmergedArea[x][y+1]) dfs(x, y+1);
}
