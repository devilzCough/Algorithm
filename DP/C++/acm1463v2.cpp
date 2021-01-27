#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[1000002];

void dp(int n);

int main()
{
	scanf("%d", &N);
	dp(N);

	printf("%d\n", num[N]);
	return 0;
}

void dp(int n)
{
	if (n == 1) {
		num[n] = 0;
	}
	else {
		int minC = 1000000;
		if (n%3 == 0) {
			int tmp = n/3;
			if (!num[tmp])
				dp(tmp);
			minC = min(minC, num[tmp]);
		}
		if (n%2 == 0) {
			int tmp = n/2;
			if (!num[tmp])
				dp(tmp);
			minC = min(minC, num[tmp]);
		}

		if (!num[n-1])
			dp(n-1);
		minC = min(minC, num[n-1]);

		num[n] = minC + 1;
	}
}
