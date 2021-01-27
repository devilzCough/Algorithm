#include <iostream>

void dfs(int x, int y);
void initField();

int T, W, H, N;
int field[55][55] = {0};

int main()
{
	scanf("%d", &T);
	while (T--) {
		int x, y;
		int count = 0;
		scanf("%d %d %d", &H, &W, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &x, &y);
			field[x][y] = 1;
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (field[i][j]) {
					dfs(i, j);
					count++;
				}
			}
		}

		printf("%d\n", count);
		initField();
	}

	return 0;
}

void dfs(int x, int y)
{
	field[x][y] = 0;
	if (x-1 >= 0 && field[x-1][y]) dfs(x-1, y);
	if (x+1 < H && field[x+1][y]) dfs(x+1, y);
	if (y-1 >= 0 && field[x][y-1]) dfs(x, y-1);
	if (y+1 < W && field[x][y+1]) dfs(x, y+1);
}

void initField()
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			field[i][j] = 0;
	}
}
