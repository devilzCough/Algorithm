#include <stdio.h>

int main()
{
	int m, s;
	int time, total = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &time);
		total += time;
	}
	m = total / 60;
	s = total % 60;
	printf("%d\n%d\n", m, s);
	return 0;
}
