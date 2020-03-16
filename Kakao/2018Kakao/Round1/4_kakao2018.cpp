#include <iostream>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

int N, Q;
vector<pair<int, int> > cp;
vector<pair<int, int> > cp;


int main()
{
	scanf("%d %d", &N, &Q);

	int x, y;
	pair<int, int> coor;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		coor = make_pair(x, y);
		cp.push_back(coor);
	}



	return 0;
}
