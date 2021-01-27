#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int glass[10003];
int dp[10003];

int main()
{
    scanf("%d", &n);
    for (int i = 3; i < n+3; i++)
        scanf("%d", &glass[i]);
    for (int i = 3; i < n+3; i++) {
        dp[i] = max(dp[i-3]+glass[i-1], dp[i-2]) + glass[i];
        dp[i] = max(dp[i], dp[i-1]);
    }
    printf("%d\n", dp[n+2]);
    return 0;
}
