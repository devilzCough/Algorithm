#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
long long arr[100000];
long long dp[100000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    dp[0] = arr[0];
    long long ans = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
}
