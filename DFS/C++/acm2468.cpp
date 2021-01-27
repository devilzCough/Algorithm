#include <iostream>
#include <algorithm>

using namespace std;

int N;
int area[102][102] = {0};
bool isVisited[102][102];

int numList[102] = {0};

// void printMap();
void flagSetting(int h);
void dfs(int x, int y);

int main()
{
	scanf("%d", &N);

	int x, y;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &area[i][j]);
			numList[area[i][j]] = 1;
		}

	int count, maxCnt = 0;
	for (int i = 1; i <= 100; i++) {
		if (numList[i]) {
			count = 0;
			flagSetting(i);
			for (int x = 0; x < N; x++)
				for (int y = 0; y < N; y++)
					if (!isVisited[x][y]) {
						dfs(x, y);
						count++;
					}
			// printf("%d\n", count);
			maxCnt = max(count, maxCnt);
		}
	}

	printf("%d\n", maxCnt);

	return 0;
}

void flagSetting(int h)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (area[i][j] <= h)
				isVisited[i][j] = true;
			else
				isVisited[i][j] = false;

}

void dfs(int x, int y)
{
	isVisited[x][y] = true;
	// printMap();
	if (x-1 >= 0 && !isVisited[x-1][y]) dfs(x-1, y);
	if (x+1 < N && !isVisited[x+1][y]) dfs(x+1, y);
	if (y-1 >= 0 && !isVisited[x][y-1]) dfs(x, y-1);
	if (y+1 < N && !isVisited[x][y+1]) dfs(x, y+1);
}
/*
void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", isVisited[i][j]);

		printf("\n");
	}
	printf("\n");
}
*/
