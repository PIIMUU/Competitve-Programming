//
// Created by user on 3/27/2020.
//
#include <bits/stdc++.h>
using namespace std;
struct Struct {
    int w, u, v, s;
    bool operator<(const Struct& temp) const {
        return w < temp.w;
    }
};
vector<Struct> e;
pair<int, int> langka[500010];
int parent[3010];
int findParent(int u) {
    if(parent[u] == u) {
        return u;
    }
    return parent[u] = findParent(parent[u]);
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w, s;
        cin >> u >> v >> w >> s;
        e.push_back({w, u, v, s});
    }
    int p;
    cin >> p;
    for(int i = 1; i <= p; ++i) {
        cin >> langka[i].second >> langka[i].first;
    }
    sort(langka + 1, langka + 1 + p);
    for(int i = 0; i < e.size(); ++i) {
        if(e[i].s == 0) {
            for(int j = 1; j <= p; ++j) {
                if(langka[j].second >= e[i].w) {
                    e[i].w = langka[j].first;
                    break;
                }
            }
        } else {
            e[i].w = 0;
        }
    }
    sort(e.begin(), e.end());
    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    long long answer = 0;
    for(auto t : e) {
        if(findParent(t.u) != findParent(t.v)) {
            answer += t.w;
            parent[findParent(t.v)] = findParent(parent[t.u]);
        }
    }
    cout << answer;
}
