#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int N, M;
vector< vector<int> > maze;
queue< pair<int, int> > Q;

void bfs(int x, int y);

int main()
{
	scanf("%d %d", &N, &M);

	maze.resize(N);
	for (int i = 0; i < N; i++)
		maze[i].resize(M);

	for (int i = 0; i < N; i++)
		for (int j = 0 ; j < M; j++)
			scanf("%d", maze[i][j]);


	bfs(0, 0);


	return 0;
}

void bfs(int x, int y)
{
	pair<int, int> coor = make_pair(x, y);
	Q.push(coor);

	if (x > 0) {
		if (x - 1 == 1) {
			maze[x - 1][y] = 
			bfs(x - 1, y);
		}
	}

	if (x < N-1) {
		if (x + 1 == 1) bfs(x + 1, y);
	}

	if (y > 0) {
		if (y - 1 == 1) bfs(x, y - 1);
	}

	if (y < M-1) {
		if (y + 1 == 1) bfs(x, y + 1);
	}



}
