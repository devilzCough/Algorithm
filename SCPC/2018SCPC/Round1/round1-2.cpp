#include <iostream>
#include <algorithm>

using namespace std;

int palindrome[200] = {0};
int T, n;
int tmp[3] = {0}, answer[3] = {0};

void makePalindrome();
int findIndex(int n);

int main()
{
	makePalindrome();
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &n);

		int min_num = 4, num = 0, total = 0;
		for (int i = 0; i < 199; i++) {
			for (int j = 0; j < 199; j++) {
				for (int k = 0; k < 199; k++) {
					num = 0;
					total = palindrome[i] + palindrome[j] + palindrome[k];
					if (total == n) {
						if (i != 0) { tmp[num++] = palindrome[i]; }
						if (j != 0) { tmp[num++] = palindrome[j]; }
						if (k != 0) { tmp[num++] = palindrome[k]; }
					}

					if (num != 0) {
						if (min_num > num) {
							for (int l = 0; l < num; l++)
								answer[l] = tmp[l];
							min_num = num;
						}
					}
				}
			}
		}
		sort(answer, answer+min_num);

		printf("Case #%d\n", test_case);
		if (min_num == 4)
			printf("0\n");
		else {
			printf("%d", min_num);
			for (int i = min_num-1; i > -1; i--)
				printf(" %d", answer[i]);
			printf("\n");
		}
	}

	return 0;
}

void makePalindrome()
{
	int c = 1;
	palindrome[0] = 0;
	for (int i = 1; i < 10; i++) {
		palindrome[c++] = i;
		palindrome[c++] = 10 * i + i;
		for (int j = 0; j < 10; j ++) {
			palindrome[c++] = 100 * i + 10 * j + i;
			palindrome[c++] = 1000 * i + 100 * j + 10 * j + i;
		}
	}
	sort(palindrome, palindrome+199);
}
