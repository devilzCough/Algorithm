#include <stdio.h>
#include <algorithm>

using namespace std;

int t, n;
int sticker[2][100001], dp[2][100001];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &sticker[i][j]);

        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        for (int i = 2; i <= n; i++) {
            dp[0][i] = sticker[0][i] + max(dp[1][i-2], dp[1][i-1]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-2], dp[0][i-1]);
        }
        int res = max(dp[0][n], dp[1][n]);
        printf("%d\n", res);
    }
    return 0;
}
