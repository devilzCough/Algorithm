#include <stdio.h>

int dp(int w, int h);

int main()
{
	int n, m;
	int count;

	scanf("%d %d", &n, &m);
	count = dp(n, m);
	printf("%d\n", count);
	return 0;
}

int dp(int w, int h)
{
	if (w==1 && h==1)
		return 0;
	int c;
	if (w > h)
		c = dp(w/2, h) + dp(w-w/2,h);
	else
		c = dp(w, h/2) + dp(w, h-h/2);
	return c+1;
}
