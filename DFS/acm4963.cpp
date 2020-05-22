#include <stdio.h>

int w, h;
int m[50][50];

void dfs(int y, int x);

int main()
{
    while (1) {
        scanf("%d %d", &w, &h);
        if (!w)
            break;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                scanf("%d", &m[i][j]);

        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }
    return 0;
}

void dfs(int y, int x)
{
    m[y][x] = 0;
    if (y-1 >= 0 && m[y-1][x]) dfs(y-1, x);
    if (y+1 < h && m[y+1][x]) dfs(y+1, x);
    if (x-1 >= 0 && m[y][x-1]) dfs(y, x-1);
    if (x+1 < w && m[y][x+1]) dfs(y, x+1);
    if (y-1 >= 0 && x-1 >= 0 && m[y-1][x-1]) dfs(y-1, x-1);
    if (y-1 >= 0 && x+1 < w && m[y-1][x+1]) dfs(y-1, x+1);
    if (y+1 < h && x-1 >= 0 && m[y+1][x-1]) dfs(y+1, x-1);
    if (y+1 < h && x+1 < w && m[y+1][x+1]) dfs(y+1, x+1);
}
