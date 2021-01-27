#include <stdio.h>

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		bool door[101] = {0};
		scanf("%d", &n);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j%i == 0) {
					if (door[j])
						door[j] = false;
					else
						door[j] = true;
				}
			}
		}
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (!door[i])
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
