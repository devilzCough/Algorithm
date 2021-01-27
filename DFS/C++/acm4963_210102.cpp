/*
 DFS/acm4963
 Created by Jiniz.ll on 2021/01/02.
*/

#include <iostream>

using namespace std;

int w, h;
int island[55][55];

int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[] = {0, 0, -1, 1, -1, 1, 1, -1};
int numOfIsland;

void input();
void solve();
void output();

void dfs(int x, int y);

int main() {
    input();
    return 0;
}

void input() {
    while(true) {
        scanf("%d %d", &w, &h);
        if (!w) break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++)
                scanf("%d", &island[i][j]);
        }
        solve();
        output();
    }
}

void solve() {
    numOfIsland = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (island[i][j] == 1) {
                dfs(j, i);
                numOfIsland++;
            }
        }
    }
}

void dfs(int x, int y) {
    island[y][x] = 0;
    for (int i = 0; i < 8; i++) {
        int cur_x = x + dx[i];
        int cur_y = y + dy[i];

        if (cur_x < 0 || cur_y < 0 || cur_x >= w || cur_y >= h) continue;
        if (island[cur_y][cur_x]) {
            dfs(cur_x, cur_y);
        }
    }
}

void output() {
    printf("%d\n", numOfIsland);
}
