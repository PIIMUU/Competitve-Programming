//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    long long k;
    int n;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    long long l = 1, r = 1e18, answer = 0;
    while(l <= r) {
        long long mid = (r + l) / 2, cnt = 0;
        for(int i = 1; i <= n; ++i) {
            cnt += mid / (arr[i] * 1ll);
        }
        if(cnt >= k) {
            r = mid - 1;
            answer = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << answer;
}