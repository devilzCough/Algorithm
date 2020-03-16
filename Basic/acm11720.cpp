#include <stdio.h>

int main()
{
	int n;
	char num[105];
	scanf("%d", &n);
	scanf("%s", num);

	int total = 0;
	for (int i = 0; i < n; i++)
		total += num[i]-'0';
		
	printf("%d\n", total);
	return 0;
}
