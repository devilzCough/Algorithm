#include <stdio.h>

int main()
{
	int n;
	int maxN = 0, maxI;
	for (int i = 1; i < 10; i++) {
		scanf("%d", &n);
		if (n > maxN) {
			maxN = n;
			maxI = i;
		}
	}

	printf("%d\n%d\n", maxN, maxI);

	return 0;
}
