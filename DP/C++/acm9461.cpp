#include <stdio.h>

int t, n;
long long dp[100] = {1, 1, 1, 2, 2};

int main()
{
    for (int i = 5; i < 100; i++)
        dp[i] = dp[i-5] + dp[i-1];

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%lld\n", dp[n-1]);
    }
    return 0;
}
