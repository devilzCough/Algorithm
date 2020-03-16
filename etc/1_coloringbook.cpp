#include <iostream>
#include <vector>
#include <algorithm>

// 13 16
// 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0
// 0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0
// 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0
// 0 0 0 1 1 1 1 1 1 1 1 1 1 0 0 0
// 0 0 1 1 1 1 1 1 1 1 1 1 1 1 0 0
// 0 1 1 1 1 2 1 1 1 1 2 1 1 1 1 0
// 0 1 1 1 2 1 2 1 1 2 1 2 1 1 1 0
// 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
// 0 3 3 3 1 1 1 1 1 1 1 3 3 3 1 0
// 0 1 1 1 1 1 2 1 1 2 1 1 1 1 1 0
// 0 0 1 1 1 1 1 2 2 1 1 1 1 1 0 0
// 0 0 0 1 1 1 1 1 1 1 1 1 1 0 0 0
// 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0


using namespace std;


int main()
{
	int m, n;

	scanf("%d %d", &m, &n);

	vector<vector<int>> picture;
	picture.resize(m);
	for(int i=0; i<m; i++)
		picture[i].assign(n, 0);

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			scanf("%d", &picture[i][j]);
	}

	vector<int> ans = solution(m, n, picture);

	printf("%d %d",ans[0], ans[1]);

	return 0;
}
