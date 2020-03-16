#include <stdio.h>

int t, n;
int nZero[42], nOne[42];

int main()
{
	nZero[0] = 1;
	nOne[1] = 1;
	scanf("%d", &t);
	for(int i = 2; i <= 40; i++){
		nZero[i] = nZero[i-1] + nZero[i-2];
		nOne[i] = nOne[i-1] + nOne[i-2];
	}
	while (t--) {
		scanf("%d", &n);
		printf("%d %d\n", nZero[n], nOne[n]);
	}
}
