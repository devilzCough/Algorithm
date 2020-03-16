#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>

using namespace std;

int T, N;
int s, cnt, sWord;


int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		cnt = 0;
		char Wi[10][55] = {};
		int size[10] = {};
		int check[55][10] = {};
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%s", Wi[j]);
			s = strlen(Wi[j]);
			size[j] = s-1;
		}

		sWord = N;
		char letters[27] = {};
		int alph[27][10] = {0};
		char letter = '\0';
		for (int k = 0; k < sWord; k++) {
				letter = Wi[k][size[k]];
				alph[letter-65]++;
		}


		for (int j = 0; j < N; j++)
			printf("%d ", size[j]);
		// printf("Case #%d: %d\n", i, );
	}
	return 0;
}
