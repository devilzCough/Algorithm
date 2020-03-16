#include <iostream>
#include <algorithm>

using namespace std;

int n;
int floors[302];
int dp[302];

int step(int f, int c);

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &floors[i]);

	printf("%d\n", step(0, 0));
	return 0;
}

int step(int f, int c)
{
	// int score = 0;
	if (f == n) return floors[n];
	if (c != 2) {
		if (!dp[f+1])
			dp[f] = step(f+1, c+1);
		else
			dp[f] = dp[f+1];
	}

	if (f+2 > n) return 0;
	if (f+2 <= n && !dp[f+2])
		dp[f] = max(dp[f], step(f+2, 1));
	else
		dp[f] = max(dp[f], dp[f+2]);

	// printf("%d-> %d\n", floor, score);
	return dp[f] + floors[f];
}
