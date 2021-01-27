#include <stdio.h>
#include <queue>

using namespace std;

typedef struct pos {
    int x, y, z;
} Pos;

int m, n, h;
int box[102][102][102];

int nDay;
queue<Pos> q;

int dx[] = {-1,1,0,0,0,0};
int dy[] = {0,0,-1,1,0,0};
int dz[] = {0,0,0,0,-1,1};

void bfs();
bool isUnripeTomato();

int main()
{
    scanf("%d %d %d", &m, &n, &h);
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                scanf("%d", &box[z][y][x]);
                if (box[z][y][x] == 1)
                    q.push({x, y, z});
            }
        }
    }

    bfs();
    if (isUnripeTomato())
        printf("%d\n", -1);
    else
        printf("%d\n", nDay);
    return 0;
}

void bfs()
{
    while (!q.empty()) {

        nDay++;
        queue<Pos> q2;

        while (!q.empty()) {

            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            q.pop();

            for (int i = 0; i < 6; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;

                if (!box[nz][ny][nx]) {
                    box[nz][ny][nx] = 1;
                    q2.push({nx, ny, nz});
                }
            }
        }
        q = q2;
    }

    nDay--;
}

bool isUnripeTomato()
{
    bool res = false;
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (!box[z][y][x])
                    res = true;
            }
        }
    }

    return res;
}
