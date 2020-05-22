#include <stdio.h>

int n, m;
int g[101][101];

void floyd();

int main()
{
    int x, y;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        g[x][y] = 1;
        g[y][x] = 1;
    }

    floyd();
    int count = 0;
    for (int i = 2; i <= n; i++)
        if (g[1][i])
            count ++;

    printf("%d\n", count);
    return 0;
}

void floyd()
{
    // 경유
    for (int i = 1; i <= n; i++) {
        // start
        for (int j = 1; j <= n; j++) {
            // 도착
            for (int k = 1; k <= n; k++) {
                if (i==j || j==k || k==i)
                    continue;
                // 시작 -> 도착 ? 시작 -> 경유 + 경유 -> 도착
                // edge 거리가 있을 때
                // if (g[j][k] > g[j][i] + g[i][k]) {
                //     g[j][k] = g[j][i] + g[i][k];
                // }

                if (g[j][k] || (g[j][i] && g[i][k]))
                    g[j][k] = 1;
            }
        }
    }
}
