#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int n, m;
int start, dest, takeTime;
vector < vector<pair<int, int> > > edge;

vector<int> bellmanFord(int s);

int main()
{
	scanf("%d %d", &n, &m);
	edge.resize(n + 1);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &start, &dest, &takeTime);
		edge[start].push_back(make_pair(dest, takeTime));
	}

	vector<int> sh_dist = bellmanFord(1);
	if (sh_dist.empty())
		printf("%d\n", -1);
	else {
		for (int i = 2; i <= n; i++) {
			if (sh_dist[i] == INF)
				printf("%d\n", -1);
			else
				printf("%d\n", sh_dist[i]);
		}
	}
	return 0;
}

// cf. codeground note
vector<int> bellmanFord(int s)
{
	vector<int> dist(n + 1, INF);
	dist[s] = 0;
	bool updated;
	for (int iter = 0; iter < n; iter++) {
		updated = false;
		for (int here = 1; here <= n; here++) {
			for (int i = 0; i < edge[here].size(); i++) {
				int there = edge[here][i].first;
				int	nextcost = dist[here] + edge[here][i].second;
				if (dist[there] > nextcost) {
					dist[there] = nextcost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) dist.clear();
	return dist;
}
