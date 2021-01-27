#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct tomato {
	int x, y;
	int day;
} tomato;

int M, N;
vector< vector<int> > box;
queue< tomato > Q;

bool complete = true;
int nDays = 0;

void bfs(tomato t);

int main()
{
	scanf("%d %d", &M, &N);
	box.resize(N);
	for (int i = 0; i < M; i++)
		box[i].resize(M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1) {
				tomato tmp;
				tmp.x = i;
				tmp.y = j;
				tmp.day = 0;
				Q.push(tmp);
			}
		}
	}

	while(!Q.empty()) {
		tomato tmp = Q.front();
		nDays = tmp.day;
		Q.pop();
		box[tmp.x][tmp.y] = -1;
		bfs(tmp);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (box[i][j] == 0)
				complete = false;


	if (complete)
		printf("%d\n", nDays);
	else
		printf("-1");

	return 0;
}

void bfs(tomato t)
{
	tomato tmp;
	memset(tmp, 0, sizeof(tomato));
	if (t.x < N-1) {
		if (box[t.x+1][t.y] == 0) {
			box[t.x+1][t.y] = 1;
			tmp.x = t.x + 1;
			tmp.y = t.y;
			tmp.day = t.day+1;
			Q.push(tmp);
		}
	}

	if (t.x > 0) {
		if (box[t.x - 1][t.y] == 0) {
			box[t.x - 1][t.y] = 1;
			tmp.x = t.x - 1;
			tmp.y = t.y;
			tmp.day = t.day+1;
			Q.push(tmp);
		}
	}

	if (t.y < M-1) {
		if (box[t.x][t.y+1] == 0) {
			box[t.x][t.y+1] = 1;
			tmp.x = t.x;
			tmp.y = t.y + 1;
			tmp.day = t.day+1;
			Q.push(tmp);
		}
	}

	if (t.y > 0) {
		if (box[t.x][t.y-1] == 0) {
			box[t.x][t.y-1] = 1;
			tmp.x = t.x;
			tmp.y = t.y - 1;
			tmp.day = t.day+1;
			Q.push(tmp);
		}
	}
}
