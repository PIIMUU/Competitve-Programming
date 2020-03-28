//
// Created by user on 3/27/2020.
//
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
pii arr[5][1510];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int X, Y, n;
    cin >> X >> Y >> n;
    vector<ppp> sum1, sum2;
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> arr[i][j].first >> arr[i][j].second;
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            sum1.push_back({{arr[1][i].first + arr[2][j].first, arr[1][i].second + arr[2][j].second}, {i, j}});
            sum2.push_back({{arr[3][i].first + arr[4][j].first, arr[3][i].second + arr[4][j].second}, {i, j}});
        }
    }
    sort(sum2.begin(), sum2.end());
    for(auto p : sum1) {
        int l = 0, r = sum2.size() - 1;
        int x = X - p.first.first, y = Y - p.first.second;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(sum2[mid].first.first == x and sum2[mid].first.second == y) {
                cout << arr[1][p.second.first].first << " " << arr[1][p.second.first].second << '\n';
                cout << arr[2][p.second.second].first << " " << arr[2][p.second.second].second << '\n';
                cout << arr[3][sum2[mid].second.first].first << " " << arr[3][sum2[mid].second.first].second << '\n';
                cout << arr[4][sum2[mid].second.second].first << " " << arr[4][sum2[mid].second.second].second << '\n';
                return 0;
            } else if(sum2[mid].first.first < x or (sum2[mid].first.first == x and sum2[mid].first.second < y)) {
                l = mid + 1;
            } else if(sum2[mid].first.first > x or (sum2[mid].first.first == x and sum2[mid].first.second > y)) {
                r = mid - 1;
            }
        }
    }

}
