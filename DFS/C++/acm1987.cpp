#include <stdio.h>
#include <algorithm>

using namespace std;

int r, c;
char board[25][25];
bool visited[25][25], alpha[30];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y);

int main()
{
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++)
        scanf("%s", board[i]);

    printf("%d\n", dfs(0, 0));

    return 0;
}

int dfs(int x, int y)
{
    int maxCnt = 0;
    char alp = board[x][y];
    visited[x][y] = true;
    alpha[alp-'A'] = true;

    for (int i = 0; i < 4; i++) {
        int cur_x = x + dx[i];
        int cur_y = y + dy[i];

        if (cur_x < 0 || cur_y < 0 || cur_x >= r || cur_y >= c) continue;
        char c_alp = board[cur_x][cur_y];
        if (!visited[cur_x][cur_y] && !alpha[c_alp-'A']) {
            maxCnt = max(maxCnt, dfs(cur_x, cur_y));
        }
    }
    visited[x][y] = false;
    alpha[alp-'A'] = false;

    return maxCnt + 1;
}
