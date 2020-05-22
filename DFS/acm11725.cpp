#include <stdio.h>
#include <vector>

using namespace std;

int n;
int parent[100001];
vector< vector<int> > t;

void dfs(int n);

int main()
{
    scanf("%d", &n);
    t.resize(n+1);

    int v1, v2;
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &v1, &v2);
        t[v1].push_back(v2);
        t[v2].push_back(v1);
    }

    dfs(1);
    for(int i = 2; i <= n; i++)
        printf("%d\n", parent[i]);
    return 0;
}

void dfs(int n)
{
    int size = t[n].size();
    int next;

    for (int i = 0; i < size; i++) {
        next = t[n][i];
        if (next != 1 && parent[next] == 0) {
            parent[next] = n;
            dfs(next);
        }
    }
}
