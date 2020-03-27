//
// Created by user on 3/26/2020.
//
#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1, pair<int, int>p2) {
    return p1.first < p2.first;
}
pair<int,int> que[100010];
int answer[100010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> ve;
    ve.push_back({0, 0});
    ve.push_back({2e9, 2e9});
    for(int i = 1, sum = 0; i <= n; ++i) {
        int number;
        cin >> number;
        sum += number;
        ve.push_back({sum, i});
    }
    for(int i = 1; i <= q; ++i) {
        cin >> que[i].first;
        que[i].second = i;
    }
    sort(ve.begin(), ve.end());
    sort(que + 1, que + q + 1);
    int oldIdx = 1, mx = 0;
    for(int i = 1; i <= q; ++i) {
        int newIdx = upper_bound(ve.begin(), ve.end(), que[i], compare) - ve.begin() - 1;
        for(int j = oldIdx; j <= newIdx; ++j) {
            mx = max(mx, ve[j].second);
        }
        oldIdx = newIdx;
        answer[que[i].second] = mx;
    }
    for(int i = 1; i <= q; ++i) {
        cout << answer[i] << '\n';
    }
}