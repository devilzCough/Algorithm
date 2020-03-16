#include <stdio.h>
#include <algorithm>

using namespace std;

int score[1000];

int main()
{
	int n;
	int maxScore = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &score[i]);
		maxScore = max(maxScore, score[i]);
	}

	double total = 0;
	for (int i = 0; i < n; i++)
		total += ((double)score[i]/maxScore*100);

	printf("%lf\n", total/n);
}
