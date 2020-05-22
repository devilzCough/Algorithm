#include <stdio.h>
#include <algorithm>

using namespace std;

int n, s;
int g[11][11];
int visited[11];

int dfs(int c);

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    int min_p = 10000000;
    for (s = 1; s <= n; s++)
        min_p = min(min_p, dfs(s));
        
    printf("%d\n", min_p);
    return 0;
}

int dfs(int c)
{
    int fee = 10000000;
    visited[c] = 1;
    visited[0]++;
    if (visited[0] == n && g[c][s])
        fee = g[c][s];
    else {
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && g[c][i])
                fee = min(fee, dfs(i) + g[c][i]);
        }
    }

    visited[c] = 0;
    visited[0]--;
    return fee;
}
