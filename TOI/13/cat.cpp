//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;
int cat[2000010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> cat[i];
    }
    long long l = 0, r = INT_MAX, answer = -1;
    while(l <= r) {
        long long mid = (r + l) / 2;
        bool ok = true;
        vector<int> ve;
        ve.push_back(0);
        for(int i = 1; i <= n; ++i) {
            if(cat[i] > mid) {
                ve.push_back(cat[i]);
            }
        }
        ve.push_back(0);
        for(int i = 1; i < ve.size() - 1 and ve.size() != 2; ++i) {
            if(ve[i] != ve[i - 1] and ve[i] != ve[i + 1]) {
                ok = false;
            }
        }
        if(ok == true) {
            r = mid - 1;
            answer = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << answer;
}