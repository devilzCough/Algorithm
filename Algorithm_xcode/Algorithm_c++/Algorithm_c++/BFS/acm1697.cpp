//
//  acm1697.cpp
//  Algorithm_xcode
//
//  Created by 이승진 on 2021/01/12.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];
queue<pair<int, int>> q;

void solve();

int main() {

    scanf("%d %d", &N, &K);
    solve();

    return 0;
}

void solve() {

    int position, step;
    q.push(make_pair(N, 0));
    while (!q.empty()) {
        position = q.front().first;
        step = q.front().second;
        q.pop();
        if (position == K)
            break;
        if (visited[position])
            continue;

        visited[position] = true;
        if (position-1 >= 0 && !visited[position-1])
            q.push(make_pair(position-1, step+1));
        if (position+1 <= 100000 && !visited[position+1])
            q.push(make_pair(position+1, step+1));
        if (position*2 <= 100000 && !visited[position*2])
            q.push(make_pair(position*2, step+1));
    }
    printf("%d\n", step);
}
