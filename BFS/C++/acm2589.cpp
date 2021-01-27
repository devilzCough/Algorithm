#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int h, w;
int max_val = 0;
char m[51][51];
bool visited[50][50];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

vector< pair<int, int> > vc;

void bfs(int x, int y);

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> m[i][j];
            if(m[i][j] == 'L') vc.push_back(make_pair(i,j));
        }
    }

    for (int i = 0; i < vc.size(); i++){
        memset(visited, false, sizeof(visited));
        bfs(vc[i].first, vc[i].second);
    }

    cout << max_val-1 << "\n";
    return 0;
}

void bfs(int x, int y)
{
    queue<pair<int, int> > q;

    q.push(make_pair(x, y));
    visited[x][y] = true;

    int cnt = 0;
    while(!q.empty()){
        cnt++;
        queue< pair<int,int> > q2;
        while (!q.empty()) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];

                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

                if (!visited[nx][ny] && m[nx][ny] == 'L') {
                    visited[nx][ny] = true;
                    q2.push(make_pair(nx,ny));
                }
            }
        }
        q = q2;
    }
    max_val = max(max_val, cnt);
}
