//
// Created by user on 3/26/2020.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int t, q;
    cin >> t >> q;
    map<vector<pair<int, int>>, int> tree;
    while(--t > -1) {
        int n;
        cin >> n;
        vector<pair<int, int>> ve;
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            if(u > v) {
                swap(u, v);
            }
            ve.push_back({u, v});
        }
        sort(ve.begin(), ve.end());
        ++tree[ve];
    }
    while(--q > -1) {
        int n;
        cin >> n;
        vector<pair<int, int>> ve;
        for(int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            if(u > v) {
                swap(u, v);
            }
            ve.push_back({u, v});
        }
        sort(ve.begin(), ve.end());
        cout << tree[ve] << '\n';
    }
}
