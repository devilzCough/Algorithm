#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int f, start, goal, up, down;
bool visited[1000001];

int bfs();

int main()
{
    int res;
    scanf("%d %d %d %d %d", &f, &start, &goal, &up, &down);

    res = bfs();
    if (res == -1) {
        printf("use the stairs\n");
    } else {
        printf("%d\n", res);
    }
    return 0;
}

int bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    visited[start] = true;

    while (!q.empty()) {
        int pos = q.front().first;
        int times = q.front().second;
        q.pop();

        if (pos == goal) {
            return times;
        }

        int new_pos;
        new_pos = pos + up;
        if (new_pos <= f && !visited[new_pos]) {
            visited[new_pos] = true;
            q.push(make_pair(new_pos, times+1));
        }

        new_pos = pos - down;
        if (new_pos > 0 && !visited[new_pos]) {
            visited[new_pos] = true;
            q.push(make_pair(new_pos, times+1));
        }
    }

    return -1;
}
