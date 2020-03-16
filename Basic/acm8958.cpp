#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);
	while (n--) {
		char answer[90];
		int score = 0, count = 0;
		scanf("%s", answer);

		int i = 0;
		while(answer[i]) {
			if (answer[i] == 'O')
				count++;
			else
				count = 0;
			score += count;
			i++;
		}
		printf("%d\n", score);
	}
	return 0;
}
