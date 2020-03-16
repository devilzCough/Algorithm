#include <iostream>
#include <algorithm>

using namespace std;

int getMaxDenominator(int a, int b);

int T;
int a, b, max_deno;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		max_deno = getMaxDenominator(a, b);
		printf("%d\n", max_deno);
	}

	return 0;
}

int getMaxDenominator(int a, int b)
{
	int share = 0;

	if (b % a == 0) {
		return b / a;
	} else {
		share = b / a + 1;
		a = a * share - b;
		b = b * share;
		max_deno = getMaxDenominator(a, b);
	}
	return max_deno;
}
