#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int T;
int n, a, b;
int tmp[15] = {0};

int splitNum(int n);

int main()
{
	scanf("%d", &T);
	for (int i = 1 ; i <= T; i++) {
		scanf("%d", &n);
		a = n / 2;
		b = n - a;

		int hasAFour = splitNum(a);
		int hasBFour = splitNum(b);
		while (hasAFour != -1 || hasBFour != -1) {
			if (hasAFour != -1) {
				a = a + pow(10, hasAFour);
				b = b - pow(10, hasAFour);
			} else {
				a = a + pow(10, hasBFour);
				b = b - pow(10, hasBFour);
			}

			hasAFour = splitNum(a);
			hasBFour = splitNum(b);
		}

		printf("Case #%d: %d %d\n", i, a, b);
	}

	return 0;
}

int splitNum(int n)
{
	int cnt = 0;
	while (n > 0) {
		tmp[cnt++] = n % 10;
		n = n / 10;
	}

	for (int i = 0; i < cnt; i++) {
		if (tmp[i] == 4) { return i; }
	}

	return -1;
}
