#include <stdio.h>
#include <queue>

using namespace std;

int w, h;
int box[1000][1000];

int nDay;
queue<pair<int, int>> q;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void bfs();
bool isUnripeTomato();

int main()
{
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &box[i][j]);
            if (box[i][j] == 1)
                q.push(make_pair(i, j));
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
        queue<pair<int, int>> q2;

        while (!q.empty()) {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i ++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

                if (!box[nx][ny]) {
                    box[nx][ny] = 1;
                    q2.push(make_pair(nx, ny));
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
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!box[i][j])
                res = true;
        }
    }

    return res;
}
