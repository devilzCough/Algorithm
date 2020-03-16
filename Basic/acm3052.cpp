#include <stdio.h>

bool flag[42];

int main()
{
	int n, count = 0;
	int tmp;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		tmp = n % 42;
		if (!flag[tmp]) {
			flag[tmp] = true;
			count++;
		}
	}

	printf("%d\n", count);
	return 0;
}
