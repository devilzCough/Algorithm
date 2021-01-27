//
//  acm10971.cpp
//  Algorithm_xcode
//
//  Created by 이승진 on 2021/01/12.
//

#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int w[11][11];
int visited[11];

int dfs(int c);

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &w[i][j]);
        }
    }

    int minPrice = 100000000;
    for (s = 1; s <= n; s++) {
        minPrice = min(minPrice, dfs(s));
    }

    printf("%d\n", minPrice);
    return 0;
}

int dfs(int c) {
    int fee = 100000000;
    visited[c] = 1;
    visited[0]++;
    if (visited[0] == n && w[c][s]) {
        fee = w[c][s];
    } else {
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && w[c][i]) {
                fee = min(fee, w[c][i] + dfs(i));
            }
        }
    }

    visited[c] = 0;
    visited[0]--;
    return fee;
}
