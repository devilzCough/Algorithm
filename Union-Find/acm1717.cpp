#include <iostream>

using namespace std;

int n, m;
int q, a, b;
int myRoot[1000005] = {0};

int findRoot(int index);

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n+1; i++)
		myRoot[i] = i;

	for (int i = 0; i < m; i++) {
		
		scanf("%d %d %d", &q, &a, &b);

		int aRoot = findRoot(a);
		int bRoot = findRoot(b);
		if (q == 0) {

			if (myRoot[aRoot] <= myRoot[bRoot])
				myRoot[bRoot] = myRoot[aRoot];
			else
				myRoot[aRoot] = myRoot[bRoot];

		} else {

			if (aRoot == bRoot)
				printf("%s\n", "YES");
			else
				printf("%s\n", "NO");
		}
	}
	return 0;
}

int findRoot(int index)
{
	int root = myRoot[index];
	while (index != root) {
		index = root;
		root = myRoot[index];
	}

	return root;
}
