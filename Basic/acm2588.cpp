#include <iostream>

int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	int total = num1 * num2;
	while(num2 > 0) {
		int n = num2 % 10;
		num2 /= 10;
		printf("%d\n", num1 * n);
	}
	printf("%d\n", total);
	return 0;
}
