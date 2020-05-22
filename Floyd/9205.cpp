#include <stdio.h>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>

using namespace std;

int t, n;
vector<pair<int,int>> pos;
bool visited[105][105];

bool isReachable(int p1, int p2);
void floyd();

int main()
{

    int x, y;
    scanf("%d", &t);
    while (t--) {
        pos.clear();
        memset(visited, false, sizeof(visited));
        scanf("%d", &n);
        for (int i = 0; i < n+2; i++) {
            scanf("%d %d", &x, &y);
            pos.push_back(make_pair(x, y));
        }

        for (int i = 0; i < n+2; i++) {
            for (int j = 0; j < n+2; j++) {
                if (i == j) continue;
                else {
                    if (isReachable(i, j))
                        visited[i][j] = true;
                }
            }
        }

        floyd();
        if (visited[0][n+1])
            printf("happy\n");
        else
            printf("sad\n");
    }

    return 0;
}

bool isReachable(int p1, int p2)
{

    int dis = abs(pos[p1].first - pos[p2].first) + abs(pos[p1].second - pos[p2].second);
    if (dis > 1000)
        return false;

    return true;
}

void floyd()
{
    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j < n+2; j++) {
            for (int k = 0; k < n+2; k++) {
                if (i == j || j == k || i == k) continue;
                if (visited[j][i] && visited[i][k])
                    visited[j][k] = true;
            }
        }
    }
}
