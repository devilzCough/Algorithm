#include <stdio.h>

int main()
{
	// Accept Code
	int n, newN;
	int n1, n2, sum;
	int count = 0;
	scanf("%d", &n);
	newN = n;
	while (1) {
		n1 = newN / 10;
	    n2 = newN % 10;
		sum = (n1+n2) % 10;
		newN = (n2*10) + sum;
		count++;

		if (n == newN) break;
	}
	printf("%d\n",count);
	/* Wrong Code: I don't know why...
	int n;
	int n1, n2;
	int sum, newN = 0, count = 0;
	scanf("%d", &n);
	while (n != newN) {
		if (!count)
			newN = n;
		n1 = newN / 10;
		n2 = newN % 10;
		sum = n1 + n2;
		newN = (n2 * 10) + (sum % 10);
		count++;
	}
	printf("%d\n", count);
	*/
}
