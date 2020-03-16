#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int T;
int N, M, nBase;

vector<int> capsule[200001];

int main()
{
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &M);
		nBase = N;
		int n1, n2;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &n1, &n2);
			capsule[n1].push_back(n2);
			capsule[n2].push_back(n1);
		}

	 	// vector<int>::iterator iter1, iter2, iter_i;
		int c1, c2;
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < capsule[i].size()-1; j++) {

				c1 = capsule[i].at(j);
				c2 = capsule[i].at(j+1);

				for (int k = 0; k < capsule[c1].size(); k++) {
					if (capsule[c1].at(k) == c2) {
						capsule[i].erase(c1);
						capsule[i].erase(c2);
						capsule[c1].erase(i);
						capsule[c2].erase(i);
						nBase--;
						break;
					}
				}

			}
		}

		printf("%d\n", nBase);

	}

	return 0;
}
