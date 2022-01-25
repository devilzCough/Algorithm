//
//  acm1260.cpp
//  Algorithm_c++
//
//  Created by 이승진 on 2021/02/18.
//

#include <iostream>
#include <queue>

using namespace std;

int n, m, startNode;
bool graph[1005][1005];
bool visited[1005];

void init();
void dfs(int start);
void bfs();

int main()
{
    scanf("%d %d %d", &n, &m, &startNode);
    int n1, n2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &n1, &n2);
        graph[n1][n2] = true;
        graph[n2][n1] = true;
    }
    
    dfs(startNode);
    printf("\n");
    init();
    bfs();
    
    return 0;
}

void init() {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

void dfs(int start) {
    
    visited[start] = true;
    printf("%d ", start);
    
    for (int i = 1; i <= n; i++) {
        if (graph[start][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs() {
    
    queue<int> q;
    q.push(startNode);
    while (!q.empty()) {
        
        int node = q.front();
        q.pop();
        
        if (visited[node]) continue;
        
        printf("%d ", node);
        visited[node] = true;
        
        for (int i = 1; i <= n; i++) {
            if (graph[node][i] && !visited[i]) {
                q.push(i);
            }
        }
    }
    printf("\n");
}
