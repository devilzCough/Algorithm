#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[1000];
int dp[2][1000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int iMax;
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        iMax = 0;
        for(int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                iMax = max(iMax, dp[0][j]);

        dp[0][i] = iMax + 1;
        // ans = max(ans, dp[i]);
    }

    dp[1][n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        iMax = 0;
        for (int j = n-1; j > i; j--)
            if (arr[i] > arr[j])
                iMax = max(iMax, dp[1][j]);

        dp[1][i] = iMax + 1;
    }

    int ans = dp[0][0] + dp[1][0];
    for (int i = 1; i < n; i++)
        ans = max(ans, dp[0][i] + dp[1][i]);

    printf("%d\n", ans-1);
}
