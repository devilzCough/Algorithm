#include <stdio.h>

int main()
{
	int vacation;
	int math, korean, maxM, maxK;
	scanf("%d %d %d %d %d", &vacation, &math, &korean, &maxM, &maxK);

	int tmp1, tmp2;
	tmp1 = math/maxM;
	if (math%maxM)
		tmp1++;
	tmp2 = korean/maxK;
	if (korean%maxK)
		tmp2++;

	if (tmp1 > tmp2)
		printf("%d\n", vacation-tmp1);
	else
		printf("%d\n", vacation-tmp2);
	return 0;
}
