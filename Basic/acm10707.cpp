#include <stdio.h>

int main()
{
	int x;
	int yBasic, yThrd, yExtra;
	int used;
	scanf("%d %d %d %d %d", &x, &yBasic, &yThrd, &yExtra, &used);

	int xFare, yFare;
	xFare = x * used;
	if (used <= yThrd)
		yFare = yBasic;
	else
		yFare = yBasic + (used-yThrd)*yExtra;

	if (xFare < yFare)
		printf("%d\n", xFare);
	else
		printf("%d\n", yFare);
	return 0;
}
