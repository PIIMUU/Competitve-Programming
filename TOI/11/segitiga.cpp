//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool dp[260][260][3];
bool vis[260][260][3];
bool dfs(int l, int r, char need) {
    if(vis[l][r][need - '0'] == true) {
        return dp[l][r][need - '0'];
    }
    vis[l][r][need - '0'] = true;
    if(l == r) {
        if(need == s[l - 1]) {
            return dp[l][r][need - '0'] = true;
        } else {
            return dp[l][r][need - '0'] = false;
        }
    }
    for(int i = l; i <= r; ++i) {
        if(need == '0') {
            dp[l][r][0] |= dfs(l, i, '0') & dfs(i + 1, r, '2');
            if(dp[l][r][0] == true) {
                break;
            }
        } else if(need == '1') {
            dp[l][r][1] |= dfs(l, i, '0') & dfs(i + 1, r, '1');
            if(dp[l][r][1] == true) {
                break;
            }
            dp[l][r][1] |= dfs(l, i, '1') & dfs(i + 1, r, '1');
            if(dp[l][r][1] == true) {
                break;
            }
            dp[l][r][1] |= dfs(l, i, '1') & dfs(i + 1, r, '2');
            if(dp[l][r][1] == true) {
                break;
            }
            dp[l][r][1] |= dfs(l, i, '2') & dfs(i + 1, r, '0');
            if(dp[l][r][1] == true) {
                break;
            }
            dp[l][r][1] |= dfs(l, i, '2') & dfs(i + 1, r, '2');
            if(dp[l][r][1] == true) {
                break;
            }
        } else if(need == '2') {
            dp[l][r][2] |= dfs(l, i, '0') & dfs(i + 1, r, '0');
            if(dp[l][r][2] == true) {
                break;
            }
            dp[l][r][2] |= dfs(l, i, '1') & dfs(i + 1, r, '0');
            if(dp[l][r][2] == true) {
                break;
            }
            dp[l][r][2] |= dfs(l, i, '2') & dfs(i + 1, r, '1');
        }
    }
    return dp[l][r][need - '0'];
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int t = 20;
    while(--t > -1) {
        cin >> n >> s;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= n; ++j) {
                for(int k = 0; k < 3; ++k) {
                    dp[i][j][k] = false;
                    vis[i][j][k] = false;
                }
            }
        }
        dfs(1, n, '0');
        if(dp[1][n][0] == true) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
