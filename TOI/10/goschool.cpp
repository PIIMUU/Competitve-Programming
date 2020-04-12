//
// Created by user on 4/12/2020.
//
#include <bits/stdc++.h>
using namespace std;
long long dp[60][60];
bool dog[60][60];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> m >> n >> k;
    for(int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        dog[n - y + 1][x] = true;
    }
    dp[n + 1][1] = 1;
    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= m; ++j) {
            if(dog[i][j] == false) {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[1][m];
}