//
// Created by user on 3/26/2020.
//
#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> tree[100010];
float dist(pair<int,int> a, pair<int, int> b) {
    long long x1 = a.first, x2 = b.first;
    long long y1 = a.second, y2 = b.second;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
bool compareY(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
float closet(int l, int r) {
    if(r - l <= 3) {
        float dMin = 2e9;
        for(int i = l; i <= r; ++i) {
            for(int j = i + 1; j <= r; ++j) {
                dMin = min(dMin, dist(tree[i], tree[j]));
            }
        }
        return dMin;
    }
    int mid = (l + r) / 2;
    float dMin = min(closet(l, mid), closet(mid + 1, r));
    vector<pair<int, int>> ve;
    for(int i = l; i <= r; ++i) {
        if(abs(tree[i].first - tree[mid].first) < dMin) {
            ve.push_back(tree[i]);
        }
    }
    sort(ve.begin(), ve.end(), compareY);
    for(int i = 0; i < ve.size(); ++i) {
        for(int j = i + 1; j < ve.size(); ++j) {
            if(abs(ve[i].second - ve[j].second) >= dMin) {
                break;
            }
            dMin = min(dMin, dist(ve[i], ve[j]));
        }
    }
    return dMin;
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(--t > -1) {
        cin >> n;
        int r, d;
        cin >> r >> d;
        for(int i = 1; i <= n; ++i) {
            cin >> tree[i].first >> tree[i].second;
        }
        sort(tree + 1, tree + n + 1);
        float dMin = closet(1, n);
        if(max(0.0, dMin - (2 * r * 1.0)) >= d * 1.0) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
}