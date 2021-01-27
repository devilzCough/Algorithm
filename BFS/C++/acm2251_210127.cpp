/*
 BFS/acm2251
 Created by Jiniz.ll on 2021/01/27.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct bottle {
    int a, b, c;
} Bottle;

int A, B, C;
queue<Bottle> q;
bool visited[201][201][201];
vector<int> ans;

void bfs();

int main() {

    scanf("%d %d %d", &A, &B, &C);

    bfs();
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}

void bfs() {

    Bottle bottle = {0, 0, C};
    q.push(bottle);

    while (!q.empty()) {
        bottle.a = q.front().a;
        bottle.b = q.front().b;
        bottle.c = q.front().c;
        q.pop();

        if (visited[bottle.a][bottle.b][bottle.c])
            continue;

        visited[bottle.a][bottle.b][bottle.c] = true;
        if (bottle.a == 0)
            ans.push_back(bottle.c);

        // A -> B
        int bottleSum = bottle.a + bottle.b;
        if (bottleSum > B) {
            q.push({bottleSum-B, B, bottle.c});
        } else {
            q.push({0, bottleSum, bottle.c});
        }

        // B -> A
        if (bottleSum > A) {
            q.push({A, bottleSum-A, bottle.c});
        } else {
            q.push({bottleSum, 0, bottle.c});
        }

        // A -> C
        bottleSum = bottle.a + bottle.c;
        if (bottleSum > C) {
            q.push({bottleSum-C, bottle.b, C});
        } else {
            q.push({0, bottle.b, bottleSum});
        }

        // C -> A
        if (bottleSum > A) {
            q.push({A, bottle.b, bottleSum-A});
        } else {
            q.push({bottleSum, bottle.b, 0});
        }

        // B -> C
        bottleSum = bottle.b + bottle.c;
        if (bottleSum > C) {
            q.push({bottle.a, bottleSum-C, C});
        } else {
            q.push({bottle.a, 0, bottleSum});
        }

        // C -> B
        if (bottleSum > B) {
            q.push({bottle.a, B, bottleSum-B});
        } else {
            q.push({bottle.a, bottleSum, 0});
        }
    }
}
