#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char alpha[16];
char code[16];

int lim_l;

void dfs(int s, int pos);
bool isSatisfied();

int main()
{
    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> alpha[i];

    sort(alpha, alpha+c);
    code[l] = '\0';

    lim_l = c - l;
    dfs(0, 0);
    return 0;
}

void dfs(int s, int pos)
{
    int eIndex;
    if (s + lim_l < c)
        eIndex = s+lim_l;
    else
        eIndex = c-1;

    for (int i = s; i <= eIndex; i++) {
        code[pos] = alpha[i];
        if (pos == l-1 && isSatisfied()) {
            printf("%s\n", code);
        } else if (pos < l-1){
            dfs(i+1, pos+1);
        }
    }
}

bool isSatisfied()
{
    int nVow = 0, nCon = 0;
    for (int i = 0; i < l; i++) {
        if (code[i] == 'a' || code[i] == 'e' || code[i] == 'i' || code[i] == 'o' || code[i] == 'u') {
            nVow++;
        } else {
            nCon++;
        }
    }

    if (nVow >= 1 && nCon >= 2)
        return true;
    else
        return false;
}
