#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int n, num;
	int nMax = -1000001, nMin = 1000001;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		nMax = max(nMax, num);
		nMin = min(nMin, num);
	}

	printf("%d %d\n", nMin, nMax);
	return 0;
}
