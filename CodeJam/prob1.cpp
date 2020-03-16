#include <iostream>
#include <string>

using namespace std;

int T;
int nDamage, maxDamage;
string strCommand;

int getCurrentDamage(string p);

int main()
{
	scanf("%d", &T);
	while(T--) {
		// maxDamage = 0;
		scanf("%d ", &nDamage);
		// scanf("%s", strCommand);
		getline(cin, strCommand, '\n');
		// printf("%s\n", strCommand.c_str());

		maxDamage = getCurrentDamage(strCommand);
		// printf("%d\n", maxDamage);
	}
	return 0;
}

int getCurrentDamage(string p)
{
	int strth = 1, totalDmg = 0;
	int i = 0;
	while(p[i]) {
		// printf("%c ", p[i]);
		if (p[i] == 'C') {
			strth *= 2;
		} else {
			totalDmg += strth;
		}

		i++;
	}

	return totalDmg;
}
