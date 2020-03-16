#include <stdio.h>

int main()
{
	int a, b, c;
	while (true) {
		scanf("%d %d %d", &a, &b, &c);
		if (!a && !b && !c)
			break;
		if (a*a == b*b+c*c || b*b == a*a+c*c || c*c == a*a+b*b)
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}
