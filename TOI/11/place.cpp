//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;
struct Struct{
    int w, u, v;
    bool operator<(const Struct& temp) const {
        return w > temp.w;
    }
};
vector<Struct> e;
int parent[200010];
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
    for(int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({w - 1, u, v});
    }
    sort(e.begin(), e.end());
    long long answer = 0;
    for(auto node : e) {
        if(findParent(node.u) != findParent(node.v)) {
            //cout << node.u << " " << node.v << '\n';
            answer += node.w;
            parent[findParent(node.v)] = findParent(node.u);
        }
    }
    cout << answer;
}
