//
// Created by user on 3/27/2020.
//
#include <bits/stdc++.h>
using namespace std;
pair<int, int> pii[500010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    long long totalP = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> pii[i].second;
    }
    for(int i = 1; i <= n; ++i) {
        cin >> pii[i].first;
        totalP += pii[i].first;
    }
    sort(pii + 1, pii + 1 + n);
    int minH = 2e9;
    long long answer1 = 0, answer2 = 1e18, sumC = 0;
    for(int i = 1; i <= n; ++i) {
        if(pii[i].first > minH) {
            break;
        }
        sumC += pii[i - 1].second;
        minH = min(pii[i].second, minH);
        if((totalP + sumC) - (1LL * pii[i].first * n) < answer2) {
            answer2 = (totalP + sumC) - (1LL * pii[i].first * n);
            answer1 = pii[i].first;
        }
    }
    cout << answer1 << " " << answer2;

}