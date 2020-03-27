//
// Created by user on 3/26/2020.
//
#include <bits/stdc++.h>
using namespace std;
int dist[110][110][2];
bool vis[110][110][2];
int p[110];
vector<pair<int, int>> e[110];
struct Struct {
    int d, u, f, tic;
    bool operator<(const Struct& temp) const {
        return d > temp.d;
    }
};
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, st, en, maxf, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    cin >> st >> en >> maxf >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    e[en].push_back({en, 0});
    for(int i = 0; i <= n + 1; ++i) {
        for(int j = 0; j <= maxf; ++j) {
            for(int k = 0; k < 2; ++k) {
                dist[i][j][k] = 2e9;
            }
        }
    }
    dist[st][0][0] = 0;
    priority_queue<Struct> pq;
    pq.push({0, st, 0, 0});
    while(pq.empty() == false) {
        Struct temp = pq.top();
        pq.pop();
        int u = temp.u, d = temp.d, f = temp.f, tic = temp.tic;

        if(vis[u][f][tic] == true) {
            continue;
        }
        vis[u][f][tic] = true;

        for(pair<int, int> v : e[u]) {
            int tempf = f, init = 0;
            if(tempf < v.second) {
                init = (v.second - tempf) * p[u];
                tempf = v.second;
            }
            for(int i = tempf; i <= maxf; ++i) {
                if(d + init + (i - tempf) * p[u] < dist[v.first][i - v.second][tic]) {
                    dist[v.first][i - v.second][tic] = d + init + (i - tempf) * p[u];
                    pq.push({dist[v.first][i - v.second][tic], v.first, i - v.second, tic});
                }
                if(tic == 0) {
                    if(d < dist[v.first][i - v.second][1]) {
                        dist[v.first][i - v.second][1] = d;
                        pq.push({dist[v.first][i - v.second][1], v.first, i - v.second, 1});
                    }
                }
            }
        }
    }
    cout << min(dist[en][maxf][1], dist[en][maxf][0]);
}