#include<bits/stdc++.h>
using namespace std;
int arr[1010][1010], dp1[1010][1010], dp2[1010][1010];
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(i % 2 == 1) {
                if(arr[i][j] + dp1[i - 1][j] == arr[i][j] + dp1[i - 1][j - 1]) {
                    dp1[i][j] = arr[i][j] + dp1[i - 1][j];
                    dp2[i][j] = dp2[i - 1][j - 1] + dp2[i - 1][j];
                } else {
                    if(arr[i][j] + dp1[i - 1][j] > arr[i][j] + dp1[i - 1][j - 1]) {
                        dp1[i][j] = arr[i][j] + dp1[i - 1][j];
                        dp2[i][j] = dp2[i - 1][j];
                    } else if(arr[i][j] + dp1[i - 1][j - 1] > dp1[i][j] + dp1[i - 1][j]) {
                        dp1[i][j] = arr[i][j] + dp1[i - 1][j - 1];
                        dp2[i][j] = dp2[i - 1][j - 1];
                    }
                }
            } else {
                if(arr[i][j] + dp1[i - 1][j] == arr[i][j] + dp1[i - 1][j + 1]) {
                    dp1[i][j] = arr[i][j] + dp1[i - 1][j];
                    dp2[i][j] = dp2[i - 1][j + 1] + dp2[i - 1][j];
                } else {
                    if(arr[i][j] + dp1[i - 1][j] > arr[i][j] + dp1[i - 1][j + 1]) {
                        dp1[i][j] = arr[i][j] + dp1[i - 1][j];
                        dp2[i][j] = dp2[i - 1][j];
                    } else if(arr[i][j] + dp1[i - 1][j + 1] > dp1[i][j] + dp1[i - 1][j]) {
                        dp1[i][j] = arr[i][j] + dp1[i - 1][j + 1];
                        dp2[i][j] = dp2[i - 1][j + 1];
                    }
                }
            }
            if(i == 1) {
                dp2[i][j] = 1;
            }
        }
    }
    int answer1 = 0, answer2 = 0;
    for(int i = 1; i <= m; ++i) {
        answer1 = max(answer1, dp1[n][i]);
    }
    for(int i = 1; i <= m; ++i) {
        if(dp1[n][i] == answer1) {
            answer2 += dp2[n][i];
        }
    }
    cout << answer1 << " " << answer2;
}
