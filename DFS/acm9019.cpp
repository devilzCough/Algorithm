#include <stdio.h>
#include <string>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int t, a, b;
char command[4] = {'D', 'S', 'L', 'R'};
bool visited[10000];

void bfs();
int operateNum(int n, int c);

int main()
{
    scanf("%d", &t);
    while (t--) {
        memset(visited, false, sizeof(visited));
        scanf("%d %d", &a, &b);
        bfs();
    }
    return 0;
}

void bfs()
{
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    visited[a] = true;

    while (!q.empty()) {
        int num = q.front().first;
        string str = q.front().second;
        q.pop();

        if (num == b) {
            printf("%s\n", str.c_str());
            break;
        }

        for (int i = 0; i < 4; i++) {
            int new_n = operateNum(num, i);
            string new_s = str + command[i];
            if (!visited[new_n]) {
                visited[new_n] = true;
                q.push(make_pair(new_n, new_s));
            }
        }
    }
}

int operateNum(int n, int c)
{
    int res;
    switch(c) {
        case 0:
            res = (2 * n) % 10000;
            break;
        case 1:
            res = n - 1;
            if (res < 0)
                res = 9999;
            break;
        case 2:
            res = (n % 1000) * 10 + n / 1000;
            break;
        case 3:
            res = (n % 10) * 1000 + (n / 10);
            break;
    }

    return res;
}
