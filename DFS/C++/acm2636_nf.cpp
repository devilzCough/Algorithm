#include <iostream>

using namespace std;

int w, h;
int plate[105][105];

int main() {
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &plate[i][j]);
        }
    }
}
