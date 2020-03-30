#include<bits/stdc++.h>
using namespace std;
int arr[30010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    arr[0] = 0;
    arr[n + 1] = 2e9;
    int mx = 0;
    for(int i = 0; i <= n; ++i) {
        int idx = upper_bound(arr , arr + n + 2, arr[i] + k) - arr - 1;
        mx = max(idx - i, mx);
    }
    cout << mx;
}