//
//  acm2573.cpp
//  Algorithm_c++
//
//  Created by 이승진 on 2021/02/18.
//

#include <iostream>

using namespace std;

int row, col;
int iceberg[300][300];
bool visited[300][300];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void init();
void dfs(int x, int y);
int meltingIce(int x, int y);

//void printIce() {
//
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++){
//            printf("%d ", iceberg[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}

int main()
{
    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++){
            scanf("%d", &iceberg[i][j]);
        }
    }
    
    int meltingYear = 0;
    int numberOfIceberg = 1;
    while (numberOfIceberg == 1) {
        init();
        numberOfIceberg = 0;
        
        for (int i = 1; i < row-1; i++) {
            for (int j = 1; j < col-1; j++) {
                if (iceberg[i][j] && !visited[i][j]) {
                    dfs(j, i);
                    numberOfIceberg++;
                }
            }
        }
        meltingYear++;
    }
    
    if (numberOfIceberg == 0) {
        printf("0\n");
    } else {
        // 하나 빼는 이유는, 2개 이상이 되기 이전에는 얼음을 녹이는 과정이어서 한 덩어리 이기 때문
        printf("%d\n", meltingYear-1);
    }
    return 0;
}

void init() {
    for (int i = 1; i < row-1; i++) {
        for (int j = 1; j < col-1; j++){
            visited[i][j] = false;
        }
    }
}

void dfs(int x, int y) {
    
    visited[y][x] = true;
    
    int meltingHeight = meltingIce(x, y);
    iceberg[y][x] = iceberg[y][x]-meltingHeight < 0 ? 0 : iceberg[y][x]-meltingHeight;
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        
        if (iceberg[new_y][new_x] && !visited[new_y][new_x]) {
            dfs(new_x, new_y);
        }
    }
}

int meltingIce(int x, int y) {
    
    int numberOfWater = 0;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        
        if (!visited[new_y][new_x] && iceberg[new_y][new_x] == 0) {
            numberOfWater++;
        }
    }
    return numberOfWater;
}
