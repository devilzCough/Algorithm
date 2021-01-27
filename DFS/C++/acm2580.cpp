#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int sudoku[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];

bool finishFlag = false;

vector<pair<int, int>> empty;

void dfs(int n);
bool isPossible(int x, int y, int v);
void checkSudoku(int x, int y, int v, bool state);
void print();

int main()
{
    for (int i = 1; i < 10; i ++) {
        for (int j = 1; j < 10; j++) {
            scanf("%d", &sudoku[i][j]);
            if (sudoku[i][j]) {
                checkSudoku(i, j, sudoku[i][j], true);
            } else {
                empty.push_back(make_pair(i, j));
            }
        }
    }

    dfs(0);
    return 0;
}

void dfs(int n)
{
    int x = empty[n].first;
    int y = empty[n].second;

    for (int i = 1; i < 10; i++) {
        if (isPossible(x, y, i)) {
            checkSudoku(x, y, i, true);
            if (n+1 < empty.size() && !finishFlag) {
                dfs(n+1);
            } else if (finishFlag){
                break;
            } else if (n+1 == empty.size()) {
                finishFlag = true;
                print();
                break;
            }
            checkSudoku(x, y, i, false);
        }
    }
}

bool isPossible(int x, int y, int v)
{
    bool flag = true;
    if (row[x][v])
        flag = false;
    if (col[y][v])
        flag = false;
    if (square[(x-1)/3 * 3 + (y-1)/3 + 1][v])
        flag = false;

    return flag;
}

void checkSudoku(int x, int y, int v, bool state)
{
    row[x][v] = state;
    col[y][v] = state;
    square[(x-1)/3 * 3 + (y-1)/3 + 1][v] = state;
    if (state)
        sudoku[x][y] = v;
    else
        sudoku[x][y] = 0;
}

void print()
{
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}
