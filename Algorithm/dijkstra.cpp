#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M,u,v,d,S;
vector< vector<pair<int, int> > > edge;
vector<int> Dijkstra(int start) {
    vector<int> dist(N+1, -1);
    priority_queue<pair<int, int> > pq; // first : dist , second : vertex_pos
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start)); // Min-Heap처럼 사용하기 위해 앞의 거리 인자에 -값을 곱해줌.
    while (!pq.empty()) {
        int here = pq.top().second;
        int heredist = -pq.top().first;
        pq.pop();
        if (heredist > dist[here]) continue;
        for (int i = 0; i < edge[here].size(); i++) {
            int there = edge[here][i].first;
            int nextdist = heredist + edge[here][i].second;
            if (dist[there] == -1 || dist[there] > nextdist) { //최단 거리 갱신
                dist[there] = nextdist;
                pq.push(make_pair(-nextdist, there));
            }
        }
    }
    return dist;
}

int main() {
    cin >> N >> M >> S;
    edge.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> d;
        edge[u].push_back(make_pair(v, d));
    }
    vector<int> dist = Dijkstra(S);
    for (int i = 1; i <= N; i++) {
        cout << dist[i] << endl;
    }
    return 0;
}
	
