#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> city_map);

int MOD = 20170805;

int main()
{
	int m, n;
	vector<vector<int>> cm;

	scanf("%d %d", &m, &n);
	cm.resize(m);
	for(int i=0; i<m; i++)
		cm[i].assign(n, 0);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin >> cm[i][j];
	auto a = solution(m, n, cm);

	printf("%d", a);

	return 0;
}

int solution(int m, int n, vector<vector<int>> city_map)
{
    int answer = 0;



    return answer;
}
