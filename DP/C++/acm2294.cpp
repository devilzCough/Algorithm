#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;
int coins[101];
int dp[10001];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &coins[i]);

    for (int i = 1; i <= k; i++)
        dp[i] = k + 1;

    for (int c = 1; c <= n; c++)
        for (int v = 1; v <= k; v++)
            if (coins[c] <= v)
                dp[v] = min(dp[v-coins[c]]+1, dp[v]);

    if (dp[k] > k)
        printf("%d\n", -1);
    else
        printf("%d\n", dp[k]);

    return 0;
}
