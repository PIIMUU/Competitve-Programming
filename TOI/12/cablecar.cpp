//
// Created by user on 3/24/2020.
//
#include <bits/stdc++.h>
using namespace std;
int n, m, s, d, p;
vector<pair<int, int>> e[3000];
bool check;
bool vis[3000];
void dfs(int u, int k) {
    vis[u] = true;
    if(u == d) {
        check = true;
        return;
    }
    for(auto v : e[u]) {
        if(vis[v.first] == false and k <= v.second) {
            dfs(v.first, k);
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, w, v;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    cin >> s >> d >> p;
    int l = 1, r = 100010, answer;
    while(l <= r) {
        int mid = (r + l) / 2;
        for(int i = 0; i <= n; ++i) {
            vis[i] = false;
        }
        check = false;
        dfs(s, mid);
        if(check == true) {
            answer = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    //cout << answer << '\n';
    if(p % (answer - 1) == 0) {
        cout << p / (answer - 1);
    } else {
        cout << p / (answer - 1) + 1;
    }
}
