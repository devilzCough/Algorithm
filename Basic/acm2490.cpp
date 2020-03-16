#include <stdio.h>

int main()
{
	for (int j = 0; j < 3; j++) {
		int yut, result = 0;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &yut);
			result += yut;
		}
		if (result == 4)
			printf("E\n");
		else
			printf("%c\n", 'D'-result);
	}
	return 0;
}
