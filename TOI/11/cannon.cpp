//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;
int arr[1000010];
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    while(--k > -1) {
        int p, s, e = -1;
        int cnt = 0;
        for(int i = 1; i <= m; ++i) {
            cin >> p;
            s = max(p - l, e + 1);
            e = p + l;
            if(s > arr[n]) {
                continue;
            }
            int ce = upper_bound(arr, arr + 1 + n, e) - arr - 1;
            int cs = lower_bound(arr, arr + 1 + n, s) - arr;
            //cout << s << " " << e << " " << cs << " " << ce << '\n';
            if(cs == 0) {
                cnt += ce - cs;
                continue;
            }
            cnt += ce - cs + 1;
        }
        cout << cnt << '\n';
    }
}