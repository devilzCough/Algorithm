#include <stdio.h>
#include <cstring>

int t, n;
int seq[1001];
bool visited[1001];

void dfs(int s);

int main()
{
    scanf("%d", &t);
    while (t--) {
        memset(visited, false, sizeof(visited));
        int count = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &seq[i]);

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                count ++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}

void dfs(int s)
{
    visited[s] = true;

    int next = seq[s];
    if (!visited[next])
        dfs(next);
}
