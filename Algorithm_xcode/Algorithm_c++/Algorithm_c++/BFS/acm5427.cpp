//
//  acm5427.cpp
//  Algorithm_c++
//
//  Created by 이승진 on 2021/06/01.
//

#include <iostream>
#include <queue>

using namespace std;

int N, w, h;
char map[1005][1005];

bool canEscape;

// up, down, left, right
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs();
void expandFire();
void move();

queue<pair<int, int>> fireQueue;
queue<pair<int, int>> moveQueue;

//void printMap() {
//    for (int i = 0; i < h; i++) {
//        for (int j = 0; j < w; j++) {
//            printf("%c ", map[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}


int main()
{
    scanf("%d", &N);
    while (N--) {
        
        canEscape = false;
        fireQueue = {};
        moveQueue = {};
        
        scanf("%d %d", &w, &h);
        for (int i = 0; i < h; i++) {
            scanf("%s", map[i]);
            
            for (int j = 0; j < w; j++) {
                if (map[i][j] == '*') {
                    fireQueue.push(make_pair(j, i));
                } else if (map[i][j] == '@') {
                    moveQueue.push(make_pair(j, i));
                }
            }
        }
        
        int movedCount = bfs();
        if (canEscape) {
            printf("%d\n", movedCount);
        } else {
            printf("IMPOSSIBLE\n");
        }
    }
    
    return 0;
}

int bfs() {
    
    int count = 0;
    while (!moveQueue.empty()) {
//        printMap();
        count++;
        
        // 순서 중요!!
        expandFire();
        move();
    }
    
    return count;
}

void expandFire() {
    
    int size = fireQueue.size();
     
    for (int i = 0; i < size; i++) {
        int fire_x = fireQueue.front().first;
        int fire_y = fireQueue.front().second;
        fireQueue.pop();
 
        for (int j = 0; j < 4; j++) {
            int new_x = fire_x + dx[j];
            int new_y = fire_y + dy[j];
            
            if (new_x < 0 || new_x >= w || new_y < 0 || new_y >= h) continue;
 
            if (map[new_y][new_x] == '.') {
                map[new_y][new_x] = '*';
                fireQueue.push(make_pair(new_x, new_y));
            }
        }
    }
}

void move() {
    
    int size = moveQueue.size();
     
    for (int i = 0; i < size; i++) {
        
        if (canEscape) break;
        
        int x_pos = moveQueue.front().first;
        int y_pos = moveQueue.front().second;
        moveQueue.pop();
        
        for (int j = 0; j < 4; j++) {
            
            int cur_x = x_pos + dx[j];
            int cur_y = y_pos + dy[j];
            
            if (cur_x < 0 || cur_x >= w || cur_y < 0 || cur_y >= h) {
                canEscape = true;
                moveQueue = {};
                break;
            }
            
            if (map[cur_y][cur_x] == '.') {
                map[cur_y][cur_x] = '@';
                moveQueue.push(make_pair(cur_x, cur_y));
            }
        }
    }
}
