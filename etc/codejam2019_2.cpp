#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int T, N;
char P[100000] = {};
int main()
{
	scanf("%d", &T);
	for (int i = 1;  i <= T; i++) {
		char newP[100000] = {};

		scanf("%d", &N);
		scanf("%s", P);

		for (int j = 0; j < 2*N-2; j++) {
			if (P[j] == 'E') {
				newP[j] = 'S';
			} else {
				newP[j] = 'E';
			}
		}
		printf("Case #%d: %s\n", i, newP);
	}

	return 0;
}
