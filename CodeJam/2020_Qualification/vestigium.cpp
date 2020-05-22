#include <stdio.h>

int t, n;
int board[101][101];
bool check[101];

void init(bool value);

int main()
{
    scanf("%d", &t);
    for (int count = 0; count < t; count++) {
        int k = 0, r = 0, c = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &board[i][j]);

        int tmp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp = board[i][j];
                if ((i+1)%2 != 0) {
                    if (check[tmp] == false)
                        check[tmp] = true;
                    else {
                        r++;
                        init(true);
                        break;
                    }
                } else {
                    if (check[tmp] == true)
                        check[tmp] = false;
                    else {
                        r++;
                        init(false);
                        break;
                    }
                }
            }
        }

        init(false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tmp = board[j][i];
                if ((i+1)%2 != 0) {
                    if (check[tmp] == false)
                        check[tmp] = true;
                    else {
                        c++;
                        init(true);
                        break;
                    }
                } else {
                    if (check[tmp] == true)
                        check[tmp] = false;
                    else {
                        c++;
                        init(false);
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
            k += board[i][i];

        printf("Case #%d: %d %d %d\n",count+1, k, r, c);

    }
    return 0;
}

void init(bool value)
{
    for (int i = 1; i <= n; i++)
        check[i] = value;
}
