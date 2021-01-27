#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector< vector<int> > board;
int n, count_q = 0, total = 0;
vector<bool> flag_x, flag_y, flag_dx, flag_dy;

// int flag_x[] = {0}, flag_y[9] = {0}, flag_dx[9] = {0}, flag_dy[9] = {0};

void dfs(int x, int y);

int main()
{
	scanf("%d", &n);
	// board.resize(n);
	// for (int i = 0; i < n; i++)
	// 	board[i].resize(n);
	flag_x.resize(n, true);
	flag_y.resize(n, true);
	flag_dx.resize(2*n-1, true);
	flag_dy.resize(2*n-1, true);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			count_q++;
			dfs(i, j);
			count_q--;
		}
	}

	printf("%d\n", total);
	return 0;
}

void dfs(int x, int y)
{
	flag_x[x] = false;
	flag_y[y] = false;
	flag_dx[x+y] = false;
	flag_dy[n-1-y+x] = false;

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		if (flag_x[i] && flag_y[j] && flag_dx[i+j] && flag_dy[n-1-j+i]) {
	// 			count_q++;
	// 			if (count_q == n)
	// 				total++;
	// 			dfs(i, j);
	// 			count_q--;
	// 		}
	// 	}
	// }
	// problem : when x value start at x>0, i have to check under x row.
	// this code not check under x row, just after x row
	for (int j = 0; j < n; j++) {
		if (flag_y[j] && flag_dx[x+1+j] && flag_dy[n-j+x]) {
			count_q++;
			if (count_q == n)
				total++;
			dfs(x+1, j);
			count_q--;
		}
	}

	flag_x[x] = true;
	flag_y[y] = true;
	flag_dx[x+y] = true;
	flag_dy[n-1-y+x] = true;

}
