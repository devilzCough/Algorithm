#include <stdio.h>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>

using namespace std;

int t, n;
vector<pair<int,int>> pos;
bool visited[105], flag;

bool isReachable(int p1, int p2);
void dfs(int p);


int main()
{

    int x, y;
    scanf("%d", &t);
    while (t--) {
        flag = false;
        pos.clear();
        memset(visited, false, sizeof(visited));
        scanf("%d", &n);
        for (int i = 0; i < n+2; i++) {
            scanf("%d %d", &x, &y);
            pos.push_back(make_pair(x, y));
        }

        dfs(0);
        if (flag)
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

void dfs(int p)
{
    if (flag || isReachable(p, n+1)) {
        flag = true;
        return;
    }
    visited[p] = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && isReachable(p, i)) {
            dfs(i);
        }
    }
}
