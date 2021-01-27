#include <iostream>

int t, N;
int nZero[42], nOne[42];

void dp(int n);

int main()
{
	nZero[0] = 1;
	nOne[1] = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		dp(N);
		printf("%d %d\n", nZero[N], nOne[N]);
	}
	return 0;
}

void dp(int n)
{
	if (nZero[n] || nOne[n])
		return;

	for (int i = 2; i > 0; i--) {
		dp(n-i);
		nZero[n] += nZero[n-i];
		nOne[n] += nOne[n-i];
	}
}
