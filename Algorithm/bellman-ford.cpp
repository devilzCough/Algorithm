#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, M,S;
int u, v, d;
vector < vector<pair<int, int> > > edge;

vector<int> bellmanFord(int start) {
	vector<int> upper(N + 1, INF);
	upper[start] = 0;
	bool updated;
	for (int iter = 0; iter < N; iter++) {
		updated = false;
		for (int here = 1; here <= N; here++) {
			for (int i = 0; i < edge[here].size(); i++) {
				int there = edge[here][i].first;
				int	nextcost = upper[here] + edge[here][i].second;
				if (upper[there] > nextcost) {
					upper[there] = nextcost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}


int main() {

	// vertex, edge, start point
	cin >> N >> M >> S;
	edge.resize(N + 1);
	for (int i = 0; i < M; i++) {
		// start v, dest v, weight
		cin >> u >> v >> d;
		edge[u].push_back(make_pair(v, d));
	}
	vector<int> dist = bellmanFord(S);
	if (dist.empty())
		cout << -1 << endl;
	else {
		for (int i = 1; i <= N; i++) {
			cout << dist[i] << endl;
		}
	}
	return 0;
}
