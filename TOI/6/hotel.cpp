#include<bits/stdc++.h>
using namespace std;
int dp[1000010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int answer = INT_MAX;
    for(int i = 1; i <= n + 20; ++i) {
        dp[i] = INT_MAX;
       
        if(i - 1 >= 0) {
            dp[i] = min(dp[i], dp[i - 1] + 500);
        }
        if(i - 2 >= 0) {
            dp[i] = min(dp[i], dp[i - 2] + 800);
        }
        if(i - 5 >= 0) {
            dp[i] = min(dp[i], dp[i - 5] + 1500);
        }
        if(i - 15 >= 0) {
            dp[i] = min(dp[i], dp[i - 15] + 3000);
        } 
        if(i >= n) {
            answer = min(answer, dp[i]);
        }
    }
    cout << answer;
}