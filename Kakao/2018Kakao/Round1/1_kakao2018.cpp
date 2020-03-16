#include <iostream>

using namespace std;

int T;
int a, b;

int sum = 0;

int main()
{
	scanf("%d", &T);
	while (T--) {
		sum = 0;
		scanf("%d %d", &a, &b);

		if (a == 0) ;
		else if (a == 1) sum += 500;
		else if (a < 4) sum += 300;
		else if (a < 7) sum += 200;
		else if (a < 11) sum += 50;
		else if (a < 16) sum += 30;
		else if (a < 22) sum += 10;

		if (b == 0) ;
		else if (b == 1) sum += 512;
		else if (b < 4) sum += 256;
		else if (b < 8) sum += 128;
		else if (b < 16) sum += 64;
		else if (b < 32) sum += 32;

		sum *= 10000;

		printf("%d\n", sum);
	}

	return 0;
}
