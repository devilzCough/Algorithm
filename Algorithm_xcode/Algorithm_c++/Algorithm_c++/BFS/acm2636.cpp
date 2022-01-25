//
//  acm2636.cpp
//  Algorithm_xcode
//
//  Created by 이승진 on 2021/01/27.
//

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int w, h;
int cheeze[101][101];
bool visited[101][101];

int numberOfCheeze;

void solve();
void checkWhereIsAir();
bool isCheezeWithAir(int x, int y);

//void printVisited() {
//    printf("\n\n");
//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < w; j++) {
//            printf("%d ", visited[i][j]);
//        }
//        printf("\n");
//    }
//}

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j< w; j++) {
            scanf("%d", &cheeze[i][j]);
            if (cheeze[i][j]) { numberOfCheeze++; }
        }
    }
    
    solve();
    return 0;
}

void solve() {
    
    checkWhereIsAir();
    
    int hours = 0;
    int nCheeze1HourAgo = numberOfCheeze;
    while (numberOfCheeze) {
        int nCheeze = 0;
        nCheeze1HourAgo = numberOfCheeze;
        for (int i = 1; i < h-1; i++) {
            for (int j = 1; j < w-1; j++) {
                if (isCheezeWithAir(j, i)) {
                    cheeze[i][j] = 0;
                    nCheeze++;
                }
            }
        }
        
        for (int i = 0; i < h; i++){
            memset(visited[i], false, sizeof(bool)*w);
        }
        checkWhereIsAir();
//        printVisited();
        numberOfCheeze -= nCheeze;
        hours++;
    }
    
    printf("%d\n%d\n", hours, nCheeze1HourAgo);
}

bool isCheezeWithAir(int x, int y) {
    if (!cheeze[y][x])
        return false;
    
    int air_x, air_y;
    for (int i = 0; i < 4; i++) {
        air_x = x + dx[i];
        air_y = y + dy[i];
        if (visited[air_y][air_x])
            return true;
    }
    
    return false;
}

void checkWhereIsAir() {
    
    queue<pair<int, int>> airQueue;
    airQueue.push(make_pair(0, 0));
    
    int x, y;
    while (!airQueue.empty()) {
        x = airQueue.front().first;
        y = airQueue.front().second;
        airQueue.pop();
        
        int cur_x, cur_y;
        for (int i = 0; i < 4; i++) {
            
            cur_x = x + dx[i];
            cur_y = y + dy[i];
            if (cur_x < 0 || cur_x >= w || cur_y < 0 || cur_y >= h) { continue; }
            
            if (!visited[cur_y][cur_x] && cheeze[cur_y][cur_x] == 0) {
                visited[cur_y][cur_x] = true;
                airQueue.push(make_pair(cur_x, cur_y));
            }
        }
    }
}
