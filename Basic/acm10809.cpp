#include <stdio.h>
#include <algorithm>

using namespace std;

int alpha[26];

int main()
{
	char word[105];
	fill(alpha, alpha+26, -1);
	scanf("%s", word);

	int i = 0, tmp;
	while (word[i]) {
		tmp = word[i]-'a';
		if (alpha[tmp] == -1)
			alpha[tmp] = i;

		i++;
	}

	for (int a = 0; a < 26; a++)
		printf("%d ", alpha[a]);
	return 0;
}
