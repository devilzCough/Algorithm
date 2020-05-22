#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define INF LLONG_MAX

using namespace std;

int n, m;
int start, dest;
long long dis[1001];
vector< vector< pair< int, int > > > edge;


void dijkstra(int s);

int main()
{
    scanf("%d %d", &n, &m);
    edge.resize(n+1);
    int x, y, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        edge[x].push_back(make_pair(y, w));
    }
    scanf("%d %d", &start, &dest);

    dijkstra(start);
    printf("%lld\n", dis[dest]);

    return 0;
}

void dijkstra(int s)
{
    // priority_queue< pair< long long, int >, vector< pair< long long, int > >, greater <> > pq;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    fill(dis, dis+n+1, INF);
    dis[s] = 0;

    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        long long d = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (dis[x] < d)
            continue;

        for (auto e : edge[x]) {
            int next = e.first;
            long long w = e.second;

            if (d + w < dis[next]) {
                dis[next] = d + w;
                pq.push(make_pair(d+w, next));
            }
        }
    }
}
