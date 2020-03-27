//
// Created by user on 3/24/2020.
//
#include <bits/stdc++.h>
using namespace std;
int n;
string s, a, b;
bool vis[1010][1010];
void dfs(int ai, int bi) {
    vis[ai][bi] = true;
    if(s[ai + bi] == a[ai]) {
        if(vis[ai + 1][bi] == false) {
            dfs(ai + 1, bi);
        }
    }
    if(s[ai + bi] == b[bi]) {
        if(vis[ai][bi + 1] == false) {
            dfs(ai, bi + 1);
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> a >> b >> n;
    int N = a.size(), M = b.size();
    for(int i = 1; i <= n; ++i) {
        cin >> s;
        dfs(0, 0);
        if(vis[N][M] == true) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        for(int j = 0; j <= N; ++j) {
            for (int k = 0; k <= M; ++k) {
                vis[j][k] = false;
            }
        }
    }
}
