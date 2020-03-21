#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int house[1000][3], table[1000][3];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);

    for (int c = 0; c < 3; c++)
        table[0][c] = house[0][c];
    for (int i = 1; i < n; i++) {
        table[i][0] = min(table[i-1][1], table[i-1][2]) + house[i][0];
        table[i][1] = min(table[i-1][0], table[i-1][2]) + house[i][1];
        table[i][2] = min(table[i-1][0], table[i-1][1]) + house[i][2];
    }

    int ans;
    ans = min(table[n-1][0], table[n-1][1]);
    ans = min(ans, table[n-1][2]);
    printf("%d\n", ans);
    return 0;
}
