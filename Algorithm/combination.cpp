#include <stdio.h>

int main()
{
	// nCm -> combination[n][m]
	// make total combination table

	// ex. 2C1 ~ 29C29
	int combination[30][30];
	combination[1][0] = 1;
	combination[1][1] = 1;
	for (int i = 2; i < 30; i++){
		combination[i][0] = 1;
		combination[i][i] = 1;
		for (int j = 1; j < i; j++)
			combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
	}
	return 0;
}
