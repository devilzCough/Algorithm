#include <iostream>
#include <algorithm>

using namespace std;

int T, N, K, L;
int bridge[50000] = {0};

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &N, &K, &L);
		for (int i = 1; i <= N; i++)
			bridge[i] = 1;

		int bomb = 0;
		while (L--) {
			scanf("%d", &bomb);
			bridge[bomb] = 0;
		}


	}

	return 0;
}
