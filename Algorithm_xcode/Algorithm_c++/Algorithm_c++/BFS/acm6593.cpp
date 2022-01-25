//
//  acm6593.cpp
//  Algorithm_c++
//
//  Created by 이승진 on 2021/06/01.
//

#include <iostream>
#include <queue>

using namespace std;

typedef struct position {
    int f, r, c;
} position;

int L, R, C;
char building[35][35][35];
bool visited[35][35][35];

position start, dest;

bool canEscape;

// up, down, north, south, west, east
int dh[] = {-1, 1, 0, 0, 0, 0};
int dr[] = {0, 0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, 0, -1, 1};

int bfs();

int main()
{
    while (true) {
        canEscape = false;
        scanf("%d %d %d", &L, &R, &C);
        if (L == 0) break;
        
        for (int h = 0; h < L; h++) {
            
            for (int r = 0; r < R; r++) {
                scanf("%s", building[h][r]);
                for (int c = 0; c < C; c++) {
                    if (building[h][r][c] == 'S')
                        start = {h, r, c};
                    else if (building[h][r][c] == 'E')
                        dest = {h, r, c};
                }
            }
            getchar();
        }
        
        int movedCount = bfs();
        if (canEscape) {
            printf("Escaped in %d minute(s).\n", movedCount);
        } else {
            printf("Trapped!\n");
        }
    }
    
    return 0;
}

int bfs()
{
    int count = 0;
    queue<position> moveQueue;
    moveQueue.push(start);
    
    while (!moveQueue.empty()) {
        
        count++;
        queue<position> tmpQ;
        
        while (!moveQueue.empty()) {
            int h = moveQueue.front().f;
            int r = moveQueue.front().r;
            int c = moveQueue.front().c;
            moveQueue.pop();
            
//            if (h == dest.f && r == dest.r && c == dest.c) {
//                canEscape = true;
//                break;
//            }
            
            for (int i = 0; i < 6; i++) {
                int new_h = h + dh[i];
                int new_r = r + dr[i];
                int new_c = c + dc[i];
                
                if (new_h < 0 || new_h >= L || new_r < 0 || new_r >= R || new_c < 0 || new_c > C) continue;
                
                if (!visited[new_h][new_r][new_c]) {
                    if (building[new_h][new_r][new_c] == '.') {
                        visited[new_h][new_r][new_c] = true;
                        tmpQ.push({new_h, new_r, new_c});
                    } else if (building[new_h][new_r][new_c] == 'E') {
                        canEscape = true;
                        moveQueue = {};
                        tmpQ = {};
                        break;
                    }
                }
            }
        }
        moveQueue = tmpQ;
    }
    
    return count;
}
