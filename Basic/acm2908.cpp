#include <stdio.h>
#include <math.h>

int main()
{
	int n1, n2, m1 = 0, m2 = 0;
	int tmp1, tmp2;
	scanf("%d %d", &n1, &n2);
	for (int i = 2; i >= 0; i--) {
		tmp1 = n1 % 10;
		tmp2 = n2 % 10;

		n1 /= 10;
		n2 /= 10;

		m1 += tmp1 * pow(10, i);
		m2 += tmp2 * pow(10, i);
	}

	if (m1 > m2)
		printf("%d\n", m1);
	else
		printf("%d\n", m2);

	return 0;
}
