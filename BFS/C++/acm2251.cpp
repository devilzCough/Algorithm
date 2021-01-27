#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct bottle {
    int a, b, c;
} Bottle;

int A, B, C;
bool visited[201][201][201];
vector<int> ans;
queue<Bottle> q;

void bfs();

int main()
{
    scanf("%d %d %d", &A, &B, &C);
    bfs();

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}

void bfs()
{
    Bottle b = {0, 0, C};
    q.push(b);

    while (!q.empty()) {

        b.a = q.front().a;
        b.b = q.front().b;
        b.c = q.front().c;
        q.pop();

        if (visited[b.a][b.b][b.c])
            continue;
        visited[b.a][b.b][b.c] = true;

        if (b.a == 0)
            ans.push_back(b.c);

        // A -> B
        if (b.a + b.b > B)
            q.push({b.a+b.b-B, B, b.c});
        else
            q.push({0, b.a+b.b, b.c});

        // A -> C
        if (b.a + b.c > C)
            q.push({b.a+b.c-C, b.b, C});
        else
            q.push({0, b.b, b.a+b.c});

        // B -> A
        if (b.a + b.b > A)
            q.push({A, b.a+b.b-A, b.c});
        else
            q.push({b.a+b.b, 0, b.c});

        // B -> C
        if (b.b + b.c > C)
            q.push({b.a, b.b+b.c-C, C});
        else
            q.push({b.a, 0, b.b+b.c});

        // C -> A
        if (b.a + b.c > A)
            q.push({A, b.b, b.a+b.c-A});
        else
            q.push({b.a+b.c, b.b, 0});

        // C -> B
        if (b.b + b.c > B)
            q.push({b.a, B, b.b+b.c-B});
        else
            q.push({b.a, b.b+b.c, 0});

    }
}
