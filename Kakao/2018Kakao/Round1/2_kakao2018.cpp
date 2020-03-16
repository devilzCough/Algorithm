#include <iostream>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

int N, K;
double nArr[505] = {0};

double m, v, stde;

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%lf", &nArr[i]);

	double minStd = numeric_limits<double>::max();
	for (int k = K; k <= N; k++) {
		double sum = 0, vSum = 0;
		for (int i = 0; i < k; i++)
			sum += nArr[i];

		for (int j = 0; j <= N - k; j++) {
			// Average
			if (j != 0)
				sum = sum - nArr[j-1] + nArr[j+k-1];
			m = sum / k;
			// printf("sum : %lf\n", sum);
			// printf("m : %lf\n", m);

			// Variance
			vSum = 0;
			for (int vj = j; vj < j + k; vj++) {
				vSum += pow(nArr[vj] - m, 2);
			}
			v = vSum / k;
			// printf("v : %lf\n", v);
			// Standard Deviation
			stde = sqrt(v);
			// printf("std : %lf\n", stde);
			minStd = min(minStd, stde);
			// printf("\n");
		}
	}

	printf("%.11lf\n", minStd);

	return 0;
}
