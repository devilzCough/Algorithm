#include <stdio.h>

int n;
int dp[31];

int main()
{
    scanf("%d", &n);
    dp[0] = 1;
    dp[2] = 3;
    if (n % 2 == 0) {
        for (int i = 4; i <= n; i+=2) {
            dp[i] = dp[i-2] * 3;
            for (int j = 4; i-j >= 0; j+=2)
                dp[i] += dp[i-j] * 2;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
