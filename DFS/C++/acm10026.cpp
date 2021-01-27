#include <iostream>

int n;
char image[105][105];
char colors[3] = {'R', 'G', 'B'};
char blind[3] = {'1', '1', '2'};
int mode;

int whichColor(int x, int y);
void dfs(int x, int y, char color);
// void printImage();


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", image[i]);

	int color, count;
	for (mode = 1; mode >= 0; mode--) {
		count = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				color = whichColor(i, j);
				if (color >= 0) {
					dfs(i, j, color);
					count++;
				}
			}
		}
		printf("%d ", count);
	}
	return 0;
}

int whichColor(int x, int y)
{
	int color;
	for (int i = 0; i < 3; i++) {
		if ((mode && image[x][y]==colors[i]) || (!mode && image[x][y]==blind[i])) {
			color = i;
			break;
		}
		else
			color = -1;
	}
	return color;
}

void dfs(int x, int y, char color)
{
	if (mode) {
		image[x][y] = blind[color];
		if (x-1 >= 0 && image[x-1][y] == colors[color]) dfs(x-1, y, color);
		if (x+1 < n && image[x+1][y] == colors[color]) dfs(x+1, y, color);
		if (y-1 >= 0 && image[x][y-1] == colors[color]) dfs(x, y-1, color);
		if (y+1 < n && image[x][y+1] == colors[color]) dfs(x, y+1, color);
	} else {
		image[x][y] = colors[color];
		if (x-1 >= 0 && image[x-1][y] == blind[color]) dfs(x-1, y, color);
		if (x+1 < n && image[x+1][y] == blind[color]) dfs(x+1, y, color);
		if (y-1 >= 0 && image[x][y-1] == blind[color]) dfs(x, y-1, color);
		if (y+1 < n && image[x][y+1] == blind[color]) dfs(x, y+1, color);
	}
}

// void printImage()
// {
// 	printf("\n");
// 	for (int i = 0; i < n; i++)
// 		printf("%s\n", image[i]);
// 	printf("\n");
// }
