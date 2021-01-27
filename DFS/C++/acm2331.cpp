#include <stdio.h>
#include <cmath>

#define MAX 240000

int a, p;
int dic[10], visited[MAX];

void dfs(int n);
int calc(int n);

int main()
{
    scanf("%d %d", &a, &p);
    for (int i = 1; i < 10; i++)
        dic[i] = (int)pow(i, p);

    dfs(a);

    int count = 0;
    for (int i = 1; i < MAX; i++) {
        if (visited[i] != -1 && visited[i] != 0)
            count ++;
    }
    printf("%d\n", count);
    return 0;
}

void dfs(int n)
{
    if (visited[n] == -1)
        return;
    if (visited[n]) {
        int nextN = visited[n];
        visited[n] = -1;
        dfs(nextN);
    } else {
        visited[n] = calc(n);
        dfs(visited[n]);
    }
}

int calc(int n)
{
    int total = 0;
    while (n > 0) {
        total += dic[n % 10];
        n /= 10;
    }
    return total;
}
