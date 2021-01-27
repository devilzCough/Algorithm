#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[1000];
int dp[1000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int ans = dp[0] = 1, iMax;
    for (int i = 1; i < n; i++) {
        iMax = 0;
        for(int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                iMax = max(iMax, dp[j]);

        dp[i] = iMax+1;
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}
