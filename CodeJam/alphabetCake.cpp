#include <iostream>

int T, R, C;
char cake[30][30] = {0};
int alph[30] = {0};

void checkCake(int i, int j);

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				scanf("%c", &cake[i][j])

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				char tmp = cake[i][j];
				if (tmp != '?' && alph[tmp-65] == 0) {
					checkCake(i, j);
				}
			}
		}

	}

	return 0;
}

void checkCake(int i, int j)
{
	int sRow = i, eRow = i, sCol = j, eCol = j;

	// left
	while (j > 0)
	// up

	// right

	// down
}
