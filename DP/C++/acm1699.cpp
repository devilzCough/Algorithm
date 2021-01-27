#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int dpTable[100001];

void dp(int n);

int main()
{
	dpTable[1] = 1;

	int n;
	scanf("%d", &n);
	dp(n);
	printf("%d\n", dpTable[n]);
	return 0;
}

void dp(int n)
{
	int maxS, squr;
	dpTable[n] = n;
	maxS = sqrt(n);
	for (int i = maxS; i >= 1; i--) {
		squr = i*i;
		if (!dpTable[n-squr])
			dp(n-squr);
		dpTable[n] = min(dpTable[n], dpTable[n-squr]+1);
	}
}
