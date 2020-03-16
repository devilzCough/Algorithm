#include <stdio.h>

int main()
{
	int a, b;
	// https://takeknowledge.tistory.com/20
	// or, while (scanf("%d %d", &a, &b) == 2)
	while (scanf("%d %d", &a, &b) != EOF)
		printf("%d\n", a+b);
	return 0;
}
