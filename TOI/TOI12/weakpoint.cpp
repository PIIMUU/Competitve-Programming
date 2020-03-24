//
// Created by user on 3/24/2020.
//

#include <bits/stdc++.h>
using namespace std;
vector<int> e[500010];
bool vis[500010];
bool isCyc[500010];
vector<int> cyc, t;
int n, m, cnt = 0;
bool haveCycle;
void findCycle(int cur, int prev) {
    vis[cur] = true;
    t.push_back(cur);
    //cout << cur << " ";
    for(auto v : e[cur]) {
        if(vis[v] == false) {
            findCycle(v, cur);
        } else if(vis[v] == true and prev != m and haveCycle == false and v == m) {
            cyc = t;
            haveCycle = true;
        }
    }
    //cout << '\n';
    t.pop_back();
    vis[cur] = false;
}
void dfs1(int u) {
    vis[u] = true;
    for(auto v : e[u]) {
        if(vis[v] == false and isCyc[v] == false) {
            ++cnt;
            dfs1(v);
        }
    }

}
void dfs2(int u) {
    vis[u] = true;
    for(auto v : e[u]) {
        if(vis[v] == false) {
            ++cnt;
            dfs2(v);
        }
    }

}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    findCycle(m, m);
    int mx = 0, idx = 2e9;
    if(haveCycle == true) {
        for(auto x : cyc) {
            isCyc[x] = true;
        }
        for(auto v : cyc) {
            if(v == m) {
                continue;
            }
            cnt = 0;
            dfs1(v);
            if(cnt > mx) {
                mx = cnt;
                idx = v;
            } else if(cnt == mx and v < idx) {
                idx = v;
            }
        }
        for(auto v : e[m]) {
            if(isCyc[v] == true) {
                continue;
            }
            cnt = 0;
            dfs1(v);

            if(cnt > mx) {
                mx = cnt;
                idx = v;
            } else if(cnt == mx and v < idx) {
                idx = v;
            }
        }
    } else {
        vis[m] = true;
        for(auto v : e[m]) {
            cnt = 0;
            dfs2(v);
            if(cnt > mx) {
                mx = cnt;
                idx = v;
            } else if(cnt == mx and v < idx) {
                idx = v;
            }
        }
    }
    cout << idx << '\n' << mx;

}