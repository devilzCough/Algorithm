#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T, l;
queue< pair<int,int> > Q;
pair<int, int> start, goal;
vector< vector<int> > board;

void bfs(int, int);

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &l);
		board.resize(l, 0);
		for (int i = 0; i < l; i++)
			board[i].resize(l, 0);

		scanf("%d %d", &start.first, &start.second);
		scanf("%d %d", &goal.first, &goal.second);


		bfs(start.first, start.second);
	}
	return 0;
}

void bfs(int x, int y)
{
	pair<int, int> tmp;
	if (x-2 > -1 && y-1 > -1) {
		// if (x-2 == goal.first && y-1 == goal.second)
		tmp = make_pair(x-2, y-1);
		Q.push(tmp);
	}

	if (x-1 > -1 && y-2 > -1) {
		tmp = make_pair(x-1, y-2);
		Q.push(tmp);
	}

	if (x+1 < l && y-2 > -1) {
		tmp = make_pair(x+1, y-2);
		Q.push(tmp);
	}

	if (x+2 < l && y-1 > -1) {
		tmp = make_pair();
		Q.push(tmp);
	}

	if (x+2 < l && y+1 < l) {
		tmp = make_pair();
		Q.push(tmp);
	}

	if (x+1 < l && y+2 < l) {
		tmp = make_pair();
		Q.push(tmp);
	}

	if (x-1 > -1 && y+2 < l) {
		tmp = make_pair();
		Q.push(tmp);
	}

	if (x-2 > -1 && y+1 < l) {
		tmp = make_pair();
		Q.push(tmp);
	}
}
