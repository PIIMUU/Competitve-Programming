//
// Created by user on 3/24/2020.
//
#include <bits/stdc++.h>
using namespace std;
long long sum[6000010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    deque<int> dq;
    long long answer = -1e18;
    int len;
    dq.push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
        while (dq.empty() == false and i - dq.front() > k) {
            dq.pop_front();
        }
        if (sum[i] - sum[dq.front()] > answer) {
                answer = sum[i] - sum[dq.front()];
                len = i - dq.front();
            } else if (sum[i] - sum[dq.front()] == answer) {
                len = min(len, i - dq.front());
        }
        while (dq.empty() == false and sum[i] < sum[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    if (answer <= 0) {
        cout << 0 << " " << 0;
    } else {
        cout << answer << " " << len;
    }
}
