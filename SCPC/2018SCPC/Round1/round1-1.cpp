#include <iostream>
#include <algorithm>

using namespace std;

int T;
int N, K;
int ability[200005];

int main()
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++)
			scanf("%d", &ability[i]);

		sort(ability, ability+N);

		int max_index = 1;
		int i_index = 0;
		for (int i = 0; i < N-1; i++) {
			i_index = lower_bound(ability, ability+N, ability[i]+K+1) - ability;
			max_index = max(max_index, i_index-i);
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", max_index);
	}
	return 0;
}
