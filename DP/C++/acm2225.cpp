#include <stdio.h>

int n, k;
int dp[201][201];

void init();

int main()
{
    scanf("%d %d", &n, &k);
    init();

    for (int k_i = 3; k_i <= k; k_i++) {
        dp[k_i][0] = 1;
        for (int n_i = 1; n_i <= n; n_i++) {
            for (int i = 0; i <= n_i; i++) {
                dp[k_i][n_i] = (dp[k_i][n_i] + dp[k_i - 1][n_i - i]) % 1000000000;
            }
        }
    }

    printf("%d\n", dp[k][n]);

    return 0;
}

void init()
{
    for (int i = 0; i <= n; i++) {
        dp[1][i] = 1;
        dp[2][i] = i+1;
    }
}
