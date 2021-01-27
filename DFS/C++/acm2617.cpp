#include <stdio.h>
#include <vector>

using namespace std;

int n, m, k;
vector<int> heavy[100], light[100];
bool isVisited[2][100];

void init();
int dfsHeavier(int bead);
int dfsLighter(int bead);

int main()
{
	int b1, b2;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &b1, &b2);
		heavy[b1].push_back(b2);
		light[b2].push_back(b1);
	}

	int c1, c2, result = 0;
	for (int b = 1; b <= n; b++) {
		init();
		c1 = dfsHeavier(b);
		c2 = dfsLighter(b);
		if (c1 > n/2 || c2 > n/2)
			result++;
	}

	printf("%d\n", result);
	return 0;
}
void init ()
{
	for (int i = 1; i <= n; i++) {
		isVisited[0][i] = false;
		isVisited[1][i] = false;
	}
}

int dfsHeavier(int bead)
{
	isVisited[0][bead] = true;
	int c = 0, next;
	int size = heavy[bead].size();
	for (int i = 0; i < size; i++) {
		next = heavy[bead][i];
		if (!isVisited[0][next])
			c += dfsHeavier(next) + 1;
	}
	return c;
}

int dfsLighter(int bead)
{
	isVisited[1][bead] = true;
	int c = 0, next;
	int size = light[bead].size();
	for (int i = 0; i < size; i++) {
		next = light[bead][i];
		if (!isVisited[1][next])
			c += dfsLighter(next) + 1;
	}
	return c;
}
