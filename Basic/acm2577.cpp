#include <stdio.h>

int count[10];

int main()
{
	int result = 1, num;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &num);
		result *= num;
	}

	int n;
	while (result > 0) {
		n = result % 10;
		count[n]++;
		result = result / 10;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", count[i]);

	return 0;
}
