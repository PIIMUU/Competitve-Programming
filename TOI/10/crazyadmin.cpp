#include<bits/stdc++.h>
using namespace std;
int arr[110];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    int l = 1, r = 1e9;
    int answer = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        int sum = 0, cnt = 1;
        for(int i = 0; i <= n; ++i) {
            if(sum + arr[i] <= mid) {
                sum += arr[i];
            } else {
                ++cnt;
                sum = arr[i];
                if(sum > mid) {
                    cnt = 2e9;
                    break;
                }
            }
        }
        //cout << mid << " " << cnt << '\n';
        if(cnt <= m) {
            r = mid - 1;
            answer = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << answer;
}