#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
bool visited[100001];
queue < pair<int, int> > q;

void bfs(int s, int step);

int main()
{
    scanf("%d %d", &n, &k);

    int p, s;
    q.push(make_pair(n, 0));
    while (!q.empty()) {
        p = q.front().first;
        s = q.front().second;
        q.pop();
        if (p == k)
            break;
        if (visited[p])
            continue;
        bfs(p, s);
    }

    printf("%d\n", s);
    return 0;
}

void print()
{
    for (int i = 0; i < k+10; i++)
        printf("%d ", visited[i]);
    printf("\n");
}

void bfs(int s, int step)
{
    visited[s] = true;
    if (s-1 >= 0 && !visited[s-1])
        q.push(make_pair(s-1, step+1));
    if (s+1 <= 100000 && !visited[s+1])
        q.push(make_pair(s+1, step+1));
    if (s*2 <= 100000 && !visited[s*2])
        q.push(make_pair(s*2, step+1));

}
