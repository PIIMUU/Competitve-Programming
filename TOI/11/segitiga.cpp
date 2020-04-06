//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;

bool dp[260][260][3];

int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int t = 20;
    while(--t > -1) {
        int n;
        string s;
        cin >> n >> s;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= n; ++j) {
                for(int k = 0; k < 3; ++k) {
                    dp[i][j][k] = false;
                }
            }
        }
        for(int i = 0; i < n; ++i) {
            dp[i][i][s[i] - '0'] = true;
        }
        for(int i = 2; i <= n; ++i) {
            for(int j = 0, k = i - 1; k < n; ++k, ++j) {
                for(int l = j; l <= k; ++l) {
                    dp[j][k][0] |= (dp[j][l][0] & dp[l + 1][k][2]);
                    dp[j][k][1] |= (dp[j][l][0] & dp[l + 1][k][1]);
                    dp[j][k][1] |= (dp[j][l][1] & dp[l + 1][k][1]);
                    dp[j][k][1] |= (dp[j][l][1] & dp[l + 1][k][2]);
                    dp[j][k][1] |= (dp[j][l][2] & dp[l + 1][k][0]);
                    dp[j][k][1] |= (dp[j][l][2] & dp[l + 1][k][2]);
                    dp[j][k][2] |= (dp[j][l][0] & dp[l + 1][k][0]);
                    dp[j][k][2] |= (dp[j][l][1] & dp[l + 1][k][0]);
                    dp[j][k][2] |= (dp[j][l][2] & dp[l + 1][k][1]);
                }
            }
        }
        if(dp[0][n - 1][0] == true) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}
