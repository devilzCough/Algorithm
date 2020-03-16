#include <iostream>

using namespace std;

int n, m;
int isConnected;
int cities[205] = {0};

int findRoot(int index);

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < n+1; i++)
		cities[i] = i;

	for (int city_i = 1; city_i < n+1; city_i++) {
		for (int city_j = 1; city_j < n+1; city_j++) {
			scanf("%d", &isConnected);
			if (city_i < city_j && isConnected) {
				int aRoot = findRoot(city_i);
				int bRoot = findRoot(city_j);

				if (cities[aRoot] <= cities[bRoot])
					cities[bRoot] = cities[aRoot];
				else
					cities[aRoot] = cities[bRoot];
			}
		}
	}

	int prev_city = 0, city = 0;
	int flag = 1;
	for (int i = 0; i < m; i++) {
		scanf("%d", &city);
		if (i > 0) {
			int aRoot = findRoot(prev_city);
			int bRoot = findRoot(city);

			if (aRoot != bRoot) {
				flag = 0;
				break;
			}
		}
		prev_city = city;
	}

	if (flag)
		printf("%s\n", "YES");
	else
		printf("%s\n", "NO");

	return 0;
}

int findRoot(int index)
{
	int root = cities[index];
	while (index != root) {
		index = root;
		root = cities[index];
	}

	return root;
}
