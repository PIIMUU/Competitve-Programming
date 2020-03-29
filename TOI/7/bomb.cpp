//
// Created by user on 3/28/2020.
//
#include <bits/stdc++.h>
using namespace std;
pair<int ,int> pii[1000010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> pii[i].first >> pii[i].second;
    }
    sort(pii + 1, pii + 1 + n);
    int maxX1 = 0, maxY1 = 0, maxX2 = 0, maxY2 = 0;
    for(int i = n; i >= 1; --i) {
        if(pii[i].second < maxY1 and pii[i].first != maxX1) {
            continue;
        }
        if(maxX1 == pii[i].first and pii[i].first < maxX2 and pii[i].second < maxY2) {
            continue;
        }
        cout << pii[i].first << " " << pii[i].second << '\n';
        if(pii[i].second > maxY1) {
            if(maxX1 != pii[i].first) {
                maxX2 = maxX1;
                maxY2 = maxY1;
            }
            maxY1 = pii[i].second;
            maxX1 = pii[i].first;
        } 
    }
    
     
}
