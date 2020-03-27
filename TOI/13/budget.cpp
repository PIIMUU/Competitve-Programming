//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, x, y, z;
vector<pii> e[10010];
int dist1[10010], dist2[10010];
void dijkstra1() {
    dist1[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    while(pq.empty() == false) {
        int u = pq.top().second;
        pq.pop();
        for(auto v : e[u]) {
            if(dist1[u] + v.second < dist1[v.first]) {
                dist1[v.first] = dist1[u] + v.second;
                pq.push({dist1[v.first], v.first});
            }
        }
    }
}
void dijkstra2() {
    dist2[y] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, y});
    while(pq.empty() == false) {
        int u = pq.top().second;
        pq.pop();
        for(auto v : e[u]) {
            if(dist2[u] + v.second < dist2[v.first]) {
                dist2[v.first] = dist2[u] + v.second;
                pq.push({dist2[v.first], v.first});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y >> z;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    for(int i = 0; i < n; ++i) {
        dist1[i] = 2e9;
        dist2[i] = 2e9;
    }
    dijkstra1();
    dijkstra2();
    int answer1 = 0, answer2 = 2e9, idx = -1;
    for(int i = 0; i < n; ++i) {
        if(dist2[i] < answer2 and dist1[i] <= z) {
            answer1 = dist1[i];
            answer2 = dist2[i];
            idx = i;
        }
    }
    cout << idx << " " << answer1 << " " << answer2;
}
