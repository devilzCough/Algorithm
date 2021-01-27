#include <stdio.h>

int r, c;
char field[255][255];
bool visited[255][255];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int nLamb, nWolf;
int survivedLamb, survivedWolf;

void dfs(int x, int y);

int main()
{
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", field[i]);
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (field[i][j] != '#' && !visited[i][j]) {
                nLamb = nWolf = 0;
                dfs(i, j);
                if (nLamb > nWolf)
                    survivedLamb += nLamb;
                else
                    survivedWolf += nWolf;
            }
        }
    }

    printf("%d %d\n", survivedLamb, survivedWolf);
    return 0;
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    if (field[x][y] == 'k')
        nLamb++;
    else if (field[x][y] == 'v')
        nWolf++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;

        if (field[nx][ny] != '#' && !visited[nx][ny])
            dfs(nx, ny);
    }
}
