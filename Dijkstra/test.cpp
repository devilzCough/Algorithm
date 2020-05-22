// https://www.acmicpc.net/problem/1865
// 웜홀
// Written in C++ langs
// 2020. 05. 08.
// Wizley

#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#define INF LLONG_MAX

using namespace std;

int N, M;
int START, END;
long long DISTANCE[1001]={0,};

vector< vector< pair<int, int> > > EDGE;

bool compare(const pair<long long,int> &A, const pair<long long,int> &B){
    return A.first > B.first;
}

void dijkstra(int s){
    priority_queue< pair <long long, int>, vector<pair<long long, int> >, compare > pq;
)
    fill(DISTANCE, DISTANCE+N+1, INF);
    DISTANCE[s] = 0;

    pq.push(make_pair(0,s));

    while(!pq.empty()){
        long long d = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if(DISTANCE[x] < d) continue;

        for(auto e : EDGE[x]){
            int next = e.first;
            long long w = e.second;

            if(DISTANCE[next] > d + w){
                DISTANCE[next] = d + w;
                pq.push(make_pair(DISTANCE[next], next));
            }
        }
    }


}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    EDGE.resize(N+1);

    int x, y, w;
    for(int i=0; i<M; i++){
        cin >> x >> y >> w;
        EDGE[x].push_back(make_pair(y,w));
    }
    cin >> START >> END;

    dijkstra(START);
    cout << DISTANCE[END] << "\n";

}
