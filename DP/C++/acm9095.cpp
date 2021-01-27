#include <iostream>

int t, N;
int num[12];

int dp(int n);

int main()
{
	scanf("%d", &t);
	num[1] = 1;
	while (t--) {
		scanf("%d", &N);
		printf("%d\n", dp(N));
	}
	return 0;
}

int dp(int n)
{

	if (num[n])
		return num[n];

	for (int i = 3; i > 0; i--) {
		if (!(n-i) || (n-i == 1))
			num[n]++;
		else if (n-i > 1){
			num[n] += dp(n-i);
		}
	}
	return num[n];
}
