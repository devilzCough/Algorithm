#include <stdio.h>
#include <cstring>
#include <queue>

using namespace std;

int t, n;
int student[100001];
int visited[100001];
bool finished[100001];

int cnt;
queue <int> q;

void dfs(int s);

int main()
{
    scanf("%d", &t);
    while (t--) {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));

        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &student[i]);

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                while (!q.empty()) {
                    int tmp = q.front();
                    if (finished[tmp]) {
                        q = {};
                        break;
                    }
                    q.pop();
                    finished[tmp] = true;
                }
            }
        }
        printf("%d\n", n-cnt);
    }
    return 0;
}

void dfs(int s)
{

    visited[s]++;
    if (visited[s] == 2) {
        cnt++;
    }
    q.push(s);

    int next = student[s];
    if (visited[next] != 2 && !finished[next]) {
        dfs(next);
    }
}
