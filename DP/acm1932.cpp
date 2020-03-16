#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[125300] = {0,};

int main()
{
	scanf("%d", &n);

	int nSize = n * (n + 1) / 2;
	for (int i = 1; i <= nSize; i++)
		scanf("%d", &arr[i]);

	int nCount = 1;
	for (int i = 2; i <= nSize; i++) {
		int tmp = (nCount+1)*(nCount+2)/2;

		if (i == tmp - nCount) {
			arr[i] += arr[i-nCount];
		} else if (i == tmp) {
			nCount++;
			arr[i] += arr[i-nCount];
		} else {
			arr[i] += max(arr[i-nCount-1], arr[i-nCount]);
		}
	}

	// nCount = 1;
	// for (int i = 1; i <= nSize; i++) {
	// 	if (i == nCount*(nCount+1)/2) {
	// 		printf("%d ", arr[i]);
	// 		printf("\n");
	// 		nCount++;
	// 	}
	// 	else {
	// 		printf("%d ", arr[i]);
	// 	}
	// }

	int nMax = arr[nSize-n+1];
	for (int i = nSize-n+1; i < nSize; i++) {
		if (arr[i] < arr[i+1])
			nMax = arr[i+1];
	}

	printf("%d\n", nMax);


	return 0;
}
