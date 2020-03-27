//
// Created by user on 3/26/2020.
//
#include <bits/stdc++.h>
using namespace std;
int n, k, t, cnt;
vector<int> e[100010], lv[10010], ve;
bool vis1[100010], cycle, vis2[100010];
void dfs(int u) {
    vis1[u] = true;
    vis2[u] = true;
    ++cnt;
    for(int v : e[u]) {
        if(vis1[v] == false) {
            dfs(v);
        }
        if(vis2[v] == true) {
            cycle = true;
        }
    }
    vis2[u] = false;
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> t;
    for(int i = 1; i <= n; ++i) {
        int level, m;
        cin >> level >> m;
        lv[level].push_back(i);
        for(int j = 1; j <= m; ++j) {
            int u;
            cin >> u;
            e[i].push_back(u);
        }
    }
    int answer = -1;
    for(int i = 1; i <= k; ++i) {
        for(int v : lv[i]) {
            if(vis1[v] == false) {
                dfs(v);
            }
        }
        if(cycle == true or cnt > t) {
            break;
        }
        answer = i;
    }
    cout << answer;


}