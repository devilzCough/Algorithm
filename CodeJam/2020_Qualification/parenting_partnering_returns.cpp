#include <stdio.h>
#include <cstring>

int t, n;
int sch[1000][2];
char str[1005];

bool isPossible(char p, int cIndex);

int main()
{
    scanf("%d", &t);
    for (int c = 0; c < t; c++) {

        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &sch[i][0], &sch[i][1]);

        str[0] = 'C';
        str[n] = '\0';
        char cur = 'C';
        for (int i = 1; i < n; i++) {

            if (!isPossible(cur, i)) {
                if (cur == 'C')
                    cur = 'J';
                else
                    cur = 'C';

                if (!isPossible(cur, i)) {
                    strcpy(str, "IMPOSSIBLE");
                    // str[10] = '\0';
                    break;
                }
            }
            str[i] = cur;
        }

        printf("Case #%d: %s\n", c+1, str);
    }
    return 0;
}

bool isPossible(char p, int cIndex)
{
    for (int i = 0; i < cIndex; i++) {
        if (str[i] == p) {
            if ((sch[cIndex][0] < sch[i][1] && sch[cIndex][0] > sch[i][0]) || (sch[cIndex][1] > sch[i][0] && sch[cIndex][1] < sch[i][1]))
                return false;
            if ((sch[cIndex][0] < sch[i][0] && sch[cIndex][1] > sch[i][0]) || (sch[cIndex][0] < sch[i][1] && sch[cIndex][1] > sch[i][1]))
                return false;
            if ((sch[cIndex][0] == sch[i][0]) && (sch[cIndex][1] == sch[i][1]) && (sch[i][0] != sch[i][1]))
                return false;

        }
    }
    return true;
}
