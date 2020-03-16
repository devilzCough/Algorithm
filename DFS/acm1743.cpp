#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;
int passage[102][102] = {0};

void init(int width, int height);
int dfs(int x, int y);

// void printMap();

int main()
{

	scanf("%d %d %d", &N, &M, &K);
	init(M, N);

	int x, y;
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		passage[x][y] = 1;
	}
	int nFood = 0, maxFood = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (passage[i][j] == 1) {
				nFood = dfs(i, j);
				// printf("%d\n", nFood);
				maxFood = max(nFood, maxFood);
			}

	printf("%d\n", maxFood);

	return 0;
}

void init(int width, int height) {
	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= width; j++)
			passage[i][j] = 0;
}

int dfs(int x, int y)
{
	passage[x][y] = 2;
	// printMap();
	int totalFood = 0;
	if (x-1 > 0 && passage[x-1][y]==1) { totalFood += dfs(x-1, y); }
	if (x+1 <= N && passage[x+1][y]==1) { totalFood += dfs(x+1, y); }
	if (y-1 > 0 && passage[x][y-1]==1) { totalFood += dfs(x, y-1); }
	if (y+1 <= M && passage[x][y+1]==1) { totalFood += dfs(x, y+1); }

	// printf("x : %d, y : \n", );
	return totalFood + 1;
}
/*
void printMap() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			printf("%d ", passage[i][j]);

		printf("\n");
	}
	printf("\n");
}
*/
