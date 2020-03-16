#include <iostream>
#include <algorithm>

using namespace std;

int findMax(int n);
int dp(int num, int maxN);

int N;
int dpT[100001] = {0};

int main()
{
	scanf("%d", &N);

	dpT[1] = 1;
	// dpT[2] = 2;

	int maxN = findMax(N);
	printf("maxN : %d\n", maxN);
	if (N - maxN*maxN == 0) {
		dpT[N] = 1;
	} else {
		int minN = 0;
		for (int i = maxN; i > 1; i--) {
			if (i == maxN)
				minN = dp(N, i) + 1;
			else
				minN = min(dp(N, i) + 1, minN);
		}
		dpT[N] = minN;
	}
	// dpT[2] = 2;
	printf("%d\n", dpT[N]);
	return 0;
}

int dp(int num, int maxN)
{
	if (dpT[num] != 0) {
		return dpT[num];
	}

	int newN = num - maxN*maxN;
	if (dpT[newN] != 0) {
		return dpT[newN];
	} else {
		dpT[maxN*maxN] = 1;
		int newM = findMax(newN);
		return dp(newN, newM) + 1;
	}
}

int findMax(int n)
{
	int i = 1;
	while(true) {
		if (i*i == n) {
			break;
		}

		if (i*i < n) {
			i++;
		} else {
			i--;
			break;
		}
	}
	return i;
}
