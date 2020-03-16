#include <stdio.h>

int main()
{
	int c;
	scanf("%d", &c);
	while (c--) {
		int n;
		int score[1000];
		double avg = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			avg += score[i];
		}
		avg /= n;

		int count = 0;
		for (int i = 0; i < n; i++) {
			if (score[i] > avg)
				count++;
		}
		printf("%.3lf%%\n", (double)count/n*100);

	}
	return 0;
}
