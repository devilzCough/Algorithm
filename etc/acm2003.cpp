#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int sequences[10005] = {0};

int s, e, sum, cnt;


int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &sequences[i]);

	s = e = 0;
	while (e < N) {

		if (sum == 0) sum = sequences[s];

		if (sum >= M) {
			if (sum == M) cnt++;

			sum -= sequences[s];
			s++;
			if (e < s) e++;
		}
		else {
			if (++e == N) break;
			sum += sequences[e];
		}
	}

	printf("%d\n", cnt);
	return 0;
}
