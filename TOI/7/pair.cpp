//
// Created by user on 3/28/2020.
//
#include <bits/stdc++.h>
using namespace std;

long long segt1[200020], segt2[200020];
pair<int, int> pii[100020];
int n;
void update(int idx, int val) {
    idx += n;
    segt1[idx] = val;
    segt2[idx] = 1;
    for(idx /= 2; idx >= 1; idx /= 2) {
        segt1[idx] = segt1[idx + idx] + segt1[idx + idx + 1];
        segt2[idx] = segt2[idx + idx] + segt2[idx + idx + 1];
    }
}
pair<long long, long long> query(int l, int r) {
    pair<long long, long long> sum;
    for(l += n, r += n; l <= r; l /= 2, r /= 2) {
        if(l % 2 == 1) {
            sum.first += segt1[l];
            sum.second += segt2[l];
            ++l;
        }
        if(r % 2 == 0) {
            sum.first += segt1[r];
            sum.second += segt2[r];
            --r;
        }
    }
    return sum;
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> pii[i].first >> pii[i].second;
        --pii[i].second;
    }
    sort(pii, pii + n);
    long long answer = 0;
    for(int i = 0; i < n; ++i) {
        auto sum = query(pii[i].second + 1, n - 1);
        answer += sum.first + (sum.second * pii[i].first);
        update(pii[i].second, pii[i].first);
    }
    cout << answer;
}
