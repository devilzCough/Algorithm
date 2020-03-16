#include <iostream>

void dfs(int p, int next);
void printValue();

int k;
int num[15];
int visited[6];
int main()
{
	do {
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			scanf("%d", &num[i]);

		dfs(0, 0);
		printf("\n");
	} while (k);
	return 0;
}

void dfs(int p, int next)
{
	for (int i = next; i <= p+(k-6); i++) {
		visited[p] = num[i];
		if (p == 5) {
			printValue();
		} else {
			dfs(p+1, i+1);
		}
	}
}

void printValue()
{
	for (int i = 0; i < 6; i++)
		printf("%d ", visited[i]);
	printf("\n");
}
