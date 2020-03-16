#include <stdio.h>

int main()
{
	int h, m, total;
	scanf("%d %d", &h, &m);
	total = h * 60 + m;
	total -= 45;
	if (total < 0) {
		h = 23;
		m = 60 + total;
	} else {
		h = total / 60;
		m = total % 60;
	}
	printf("%d %d\n", h, m);
	return 0;
}
