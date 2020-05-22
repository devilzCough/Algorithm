#include <stdio.h>

int n, k;
int coins[101];
int dp[10001];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &coins[i]);

    dp[0] = 1;

    for (int c = 1; c <= n; c++)
        for (int v = 1; v <= k; v++)
            if (coins[c] <= v)
                dp[v] += dp[v-coins[c]];

    printf("%d\n", dp[k]);
    return 0;
}
