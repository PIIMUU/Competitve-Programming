//
// Created by user on 3/28/2020.
//
#include <bits/stdc++.h>
using namespace std;
bool dont[10];
int n, m;
vector<int> answer;
void dfs(int u, int cnt, bool vis[]) {
    answer.push_back(u);
    //cout << u << " " << cnt << '\n';
    if(cnt == n) {
        for(int x : answer) {
            cout << x << " ";
        }
        cout << '\n';
    } else {
        for(int i = 1; i <= n; ++i) {
            if(vis[i] == false) {
                vis[i] = true;
                dfs(i, cnt + 1, vis);
                vis[i] = false;
            }
        }
    }
    answer.pop_back();
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int number;
        cin >> number;
        dont[number] = true;
    }
    for(int i = 1; i <= n; ++i) {
        if(dont[i] == false) {
            bool vis[10] = {};
            vis[i] = true;
            dfs(i, 1, vis);
        }
    }

}
