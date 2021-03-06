#include <iostream>

#define MAX 105
#define INT_MAX 0x7fffffff

using namespace std;

int n, d[MAX][MAX];

void floyd_warwhall() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == INT_MAX || d[k][j] == INT_MAX) continue;

				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
			if (d[i][j] == 0) d[i][j] = INT_MAX;
		}

	floyd_warwhall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cout << d[i][j] << " ";
		cout << endl;
	}
}
	
