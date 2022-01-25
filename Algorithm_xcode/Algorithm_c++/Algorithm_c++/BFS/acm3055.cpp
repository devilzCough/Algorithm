//
//  acm3055.cpp
//  Algorithm_c++
//
//  Created by 이승진 on 2021/02/15.
//

#include <iostream>
#include <queue>

using namespace std;

int width, height;
char map[55][55];

queue<pair<int, int>> waterQueue;
queue<pair<int, int>> hedgehogQueue;
bool isArrived;

// up, down, left, right
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int bfs();
void overflowWater();
void moveHedgehog();

//void printMap() {
//    for (int i = 0; i < height; i++) {
//        for (int j = 0; j < width; j++) {
//            printf("%c ", map[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}

int main()
{
    // input
    scanf("%d %d", &height, &width);
    for (int i = 0; i < height; i++) {
        scanf("%s", map[i]);
        
        for (int j = 0; j < width; j++) {
            if (map[i][j] == '*') {
                waterQueue.push(make_pair(j, i));
            } else if (map[i][j] == 'S') {
                hedgehogQueue.push(make_pair(j, i));
            }
        }
    }
    
    int movedCount = bfs();
    if (isArrived) {
        printf("%d\n", movedCount);
    } else {
        printf("KAKTUS\n");
    }
    
    return 0;
}

int bfs() {
    
    int count = 0;
    while (!hedgehogQueue.empty()) {
        count++;
        
        // water move first
        overflowWater();
        
        // hedgehog move
        moveHedgehog();
    }
    
    return count;
}

void overflowWater() {
    
    int size = waterQueue.size();
     
    for (int i = 0; i < size; i++) {
        int water_x = waterQueue.front().first;
        int water_y = waterQueue.front().second;
        waterQueue.pop();
 
        for (int j = 0; j < 4; j++) {
            int new_x = water_x + dx[j];
            int new_y = water_y + dy[j];
            
            if (new_x < 0 || new_x >= width || new_y < 0 || new_y >= height) continue;
 
            if (map[new_y][new_x] == '.') {
                map[new_y][new_x] = '*';
                waterQueue.push(make_pair(new_x, new_y));
            }
        }
    }
}

void moveHedgehog() {
    
    int size = hedgehogQueue.size();
     
    for (int i = 0; i < size; i++) {
        
        if (isArrived) break;
        
        int x_pos = hedgehogQueue.front().first;
        int y_pos = hedgehogQueue.front().second;
        hedgehogQueue.pop();
        
        for (int j = 0; j < 4; j++) {
            
            int cur_x = x_pos + dx[j];
            int cur_y = y_pos + dy[j];
            
            if (cur_x < 0 || cur_x >= width || cur_y < 0 || cur_y >= height) continue;
            
            if (map[cur_y][cur_x] == 'D') {
                isArrived = true;
                hedgehogQueue = {};
                break;
            } else if (map[cur_y][cur_x] == '.') {
                map[cur_y][cur_x] = 'S';
                hedgehogQueue.push(make_pair(cur_x, cur_y));
            }
        }
    }
}
