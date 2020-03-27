//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> ve;
    for(int i = 1; i <= n; ++i) {
        int number;
        cin >> number;
        if(ve.size() == 0) {
            ve.push_back(number);
        } else {
            int idx = upper_bound(ve.begin(), ve.end(), number) - ve.begin();
            if(idx == ve.size()) {
                ve.push_back(number);
            } else {
                ve[idx] = number;
            }
        }
    }
    cout << n - ve.size();
}