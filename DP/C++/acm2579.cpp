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

	dp[1] = floors[1];
	dp[2] = floors[1] + floors[2];
	for (int i = 3; i <= n; i++)
		dp[i] = max(dp[i-2], dp[i-3] + floors[i-1]) + floors[i];

	printf("%d\n", dp[n]);
	return 0;
}
