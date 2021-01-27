#include <stdio.h>
#include <queue>

using namespace std;

int n, m;
int maze[101][101];
int visited[101][101];

int cnt;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void bfs();

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            scanf("%1d", &maze[i][j]);
    }

    bfs();
    printf("%d\n", visited[n][m]);

    return 0;
}

void bfs()
{
    int x, y;
    queue <pair<int, int>> q, q2;

    q.push(make_pair(1, 1));
    visited[1][1] = 1;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

            if (maze[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = visited[x][y] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
