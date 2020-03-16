#include <stdio.h>

int t, n;
bool flag;

int main()
{
	scanf("%d", &t);
	short px, py, x, y;
	int dis;
	while (t--) {
		flag = true;
		scanf("%d", &n);
		for (int i = 0; i < n+2; i++) {
			scanf("%hd %hd", &x, &y);
			if (i) {
				dis = (x-px) + (y-py);
				if (dis / 50 > 20)
					flag = false;
			}
			px = x;
			py = y;
		}

		if (flag)
			printf("happy\n");
		else
			printf("sad\n");
	}
	return 0;
}
