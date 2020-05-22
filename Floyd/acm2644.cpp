#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

int n, m;
int p1, p2;
int rel[101][101];

void floyd();
int main()
{
    int x, y;
    // 전체 초기화 : 처음에는 [0][0]을 써주고, 그 다음 칸에는 [최대 행(값) - 1][최대 열], 다음 칸에는 초기 상태의 값
    fill(&rel[0][0], &rel[99][100], INT_MAX);
    scanf("%d %d %d %d", &n, &p1, &p2, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        rel[x][y] = 1;
        rel[y][x] = 1;
    }

    floyd();
    if (rel[p1][p2] == INT_MAX)
        printf("%d\n", -1);
    else
        printf("%d\n", rel[p1][p2]);
    return 0;
}

void floyd()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i == j || j == k || i == k) continue;
                if (rel[j][i] != INT_MAX && rel[i][k] != INT_MAX) {
                    if (rel[j][i] + rel[i][k] < rel[j][k])
                        rel[j][k] = rel[j][i] + rel[i][k];
                }
            }
        }
    }

}
