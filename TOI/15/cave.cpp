//
// Created by user on 3/27/2020.
//
#include <bits/stdc++.h>
using namespace std;
struct Struct {
    int d, u, cnt;
    bool operator<(const Struct& temp) const {
        return d > temp.d;
    }
};
int dist[2010][2010];
vector<pair<int, int>> e[2010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, start, end, m;
    cin >> n >> start >> end >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= n; ++j) {
            dist[i][j] = 2e9;
        }
    }
    dist[start][0] = 0;
    priority_queue<Struct> pq;
    pq.push({0, start, 0});
    int mn = 2e9, N = n;
    while(pq.empty() == false) {
        Struct u = pq.top();
        pq.pop();
        if(u.u == end) {
            if(u.d < mn) {
                mn = u.d;
                N = u.cnt;
            } else if(u.d == mn and u.cnt < N) {
                N = u.cnt;
            }
        }
        for(pair<int, int> v : e[u.u]) {
            if(u.d + v.second < dist[v.first][u.cnt + 1]) {
                dist[v.first][u.cnt + 1] = u.d + v.second;
                pq.push({dist[v.first][u.cnt + 1], v.first, u.cnt + 1});
            }
        }
    }
    int q;
    cin >> q;
    while(--q > -1) {
        int t;
        cin >> t;
        int answer = 2e9;
        for(int i = 1; i <= N; ++i) {
            answer = min(answer, dist[end][i] + (i - 1) * t);
        }
        cout << answer << " ";
    }
}
