#include<bits/stdc++.h>
using namespace std;
char arr[1010];
int dp[1010][1010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = 1, k = i; k <= n; ++j, ++k) {
            dp[j][k] = dp[j + 1][k - 1] + (arr[j] == arr[k]);
            for(int l = j; l <= k; ++l) {
                dp[j][k] = max(dp[j][k], dp[j][l] + dp[l + 1][k]);
            }
        }
    }
    cout << dp[1][n];
}
