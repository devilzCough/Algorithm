#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long sequence[105] = {0};

int main()
{
	scanf("%d", &n);
	sequence[0] = 0;
	sequence[1] = 1;

	for (int i = 2; i <= n; i++) {
		sequence[i] = sequence[i-1] + sequence[i-2];
	}
	printf("%lld\n", sequence[n]);
	return 0;
}
