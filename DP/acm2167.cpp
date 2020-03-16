#include <stdio.h>

int n, m;
int arr[301][301];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
	}

	int k;
	int x1, y1, x2, y2;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int total = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++)
				total += arr[x][y];
		}
		printf("%d\n", total);
	}

	return 0;
}
