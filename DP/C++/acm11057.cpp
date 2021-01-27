#include <stdio.h>

int n;
int dp[1001][10];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < 10; j++)
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
    }

    int total = 0;
    for (int i = 0; i < 10; i++)
        total = (total + dp[n][i]) % 10007;
    printf("%d\n", total);

    return 0;
}
