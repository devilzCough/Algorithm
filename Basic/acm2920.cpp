#include <stdio.h>

// 8 2 6 5 4 3 7 1

int main()
{
	int note, scale = 3;
	int tmp;
	for (int i = 1; i < 9; i++) {
		scanf("%d", &note);
		if (i == 1) {
			tmp = note;
			if (note == 1)
				scale = 1;
			else if (note == 8)
				scale = 2;
			else
				scale = 0;
		} else {
			if (scale == 1 && note == tmp+1)
				tmp++;
			else if (scale == 2 && note == tmp-1)
				tmp--;
			else
				scale = 0;
		}
	}

	if (scale == 1)
		printf("ascending\n");
	else if (scale == 2)
		printf("descending\n");
	else
		printf("mixed\n");

	return 0;
}
