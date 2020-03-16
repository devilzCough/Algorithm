#include <iostream>

using namespace std;

int n;
int cases[1002] = {0};

int main()
{
	scanf("%d", &n);

	cases[0] = 1;
	cases[1] = 2;

	for (int i = 2; i < n; i++) {
		cases[i] = (cases[i-1] + cases[i-2]) % 10007;
		// printf("%d\n", cases[i]);
	}

	printf("%d\n", cases[n-1]);
	return 0;
}
