#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int burger, drink;

	int mbg = 3000, md = 3000;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &burger);
		mbg = min(mbg, burger);
	}

	for (int i = 0; i < 2; i++) {
		scanf("%d", &drink);
		md = min(md, drink);
	}

	printf("%d\n", mbg+md-50);
	return 0;
}
