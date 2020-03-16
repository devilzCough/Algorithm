#include <stdio.h>
#include <algorithm>

using namespace std;

int alpha[26];

int main()
{
	char word[1000005];
	scanf("%s", word);

	int i = 0;
	while (word[i]) {
		if (word[i] > 95)
			alpha[word[i]-'a']++;
		else
			alpha[word[i]-'A']++;

		i++;
	}

	int maxC = 0;
	for (int a = 0; a < 26; a++)
		maxC = max(maxC, alpha[a]);

	bool flag = false;
	char maxA;
	for (int a = 0; a < 26; a++) {
		if (alpha[a] == maxC && !flag) {
			maxA = a+'A';
			flag = true;
		} else if (alpha[a] == maxC && flag) {
			maxA = '?';
			break;
		}
	}
	printf("%c\n", maxA);

	return 0;
}
