#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000002] = {0};

int dp(int n);

int main()
{
	scanf("%d", &n);
	printf("%d\n", dp(n));

	return 0;
}

int dp(int n)
	{
	if (n == 1) {
		return 0;
	} else {
		if (arr[n] != 0)
			return arr[n];

		arr[n] = dp(n - 1) + 1;
		if (n % 3 == 0)
			arr[n] = min(arr[n], dp(n / 3) + 1);

		if (n % 2 == 0)
			arr[n] = min(arr[n], dp(n / 2) + 1);

		return arr[n];
	}
}
