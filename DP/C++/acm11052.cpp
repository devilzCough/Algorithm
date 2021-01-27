#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int price[1001];
int dp[1001];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &price[i]);

    for (int i = 1; i <= n; i++)
        dp[i] = price[1] * i;

    for (int c = 2; c <= n; c++) {
        for (int i = 1; i <= n; i++) {
            if (c <= i)
                dp[i] = max(price[c] + dp[i-c], dp[i]);
        }
    }

    printf("%d\n", dp[n]);
    return 0;
}
