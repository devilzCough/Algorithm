// 분할정복
#include <iostream>
#include <algorithm>

int n;
int image[65][65] = {0};

void compress(int xs, int xe, int ys, int ye);

int main()
{
	// input
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &image[i][j]);

	compress(0, n-1);
	return 0;
}

void compress(int xs, int xe, int ys, int ye)
{
	compress(xs, xe/2, ys, ye/2);
	compress(xs, xe/2, ye/2+1, ye);
	compress(xe/2+1,xe, ys, ye/2);
	compress(xe/2+1,xe, ye/2+1, ye);
}
