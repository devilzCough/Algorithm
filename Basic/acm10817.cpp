#include <stdio.h>

int main()
{
	int a, b, c;
	int max, second;
	scanf("%d %d %d", &a, &b, &c);
	if (a >= b) {
		max = a;
		second = b;
	} else {
		max = b;
		second = a;
	}

	if (c >= max)
		second = max;
	else if (c < max && c > second)
		second = c;
	printf("%d\n", second);
	return 0;
}
