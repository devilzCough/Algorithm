#include <stdio.h>

int n;
int tile[1001];

int main()
{
    scanf("%d", &n);
    tile[1] = 1;
    tile[2] = 3;
    for (int i = 3; i <= n; i++)
        tile[i] = (tile[i-1] + tile[i-2]*2)%10007;
    printf("%d\n", tile[n]);
    return 0;
}
