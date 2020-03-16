#include <iostream>
#include <algorithm>

using namespace std;

int H, W, n;
int x1, y1, x2, y2;
int area[105][105];
int areaSize[5005];

void drawRectangle();
int dfs(int x, int y);

int main()
{
	scanf("%d %d %d", &H, &W, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		drawRectangle();
	}

	int nArea = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!area[i][j]) {
				areaSize[nArea++] = dfs(i, j);
			}
		}
	}

	printf("%d\n", nArea);
	sort(areaSize, areaSize+nArea);
	for (int i = 0; i < nArea; i++)
		printf("%d ", areaSize[i]);

	return 0;
}

void drawRectangle()
{
	for (int x = x1; x < x2; x++) {
		for (int y = y1; y < y2; y++) {
			area[x][y] = 1;
		}
	}
}

int dfs(int x, int y)
{
	area[x][y] = 1;

	int count = 0;
	if (x-1 >= 0 && !area[x-1][y])
		count += dfs(x-1, y);
	if (x+1 < H && !area[x+1][y])
		count += dfs(x+1, y);
	if (y-1 >= 0 && !area[x][y-1])
		count += dfs(x, y-1);
	if (y+1 < W && !area[x][y+1])
		count += dfs(x, y+1);

	return count + 1;
}
