//
// Created by user on 3/24/2020.
//
#include <bits/stdc++.h>
using namespace std;
pair<int, int> pii[15020];
bool vis[15020];
int dist[15020];
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> pii[i].first >> pii[i].second;
        dist[i] = 2e9;
    }
    int u = 1;
    vector<int> ve;
    while(true) {
        int mn = INT_MAX;
        int idx = 0;
        vis[u] = true;
        for(int v = 1; v <= n; ++v) {
            if(vis[v] == false) {
                dist[v] = min(dist[v], abs(pii[v].first - pii[u].first) + abs(pii[u].second - pii[v].second));
                if(dist[v] < mn) {
                    mn = dist[v];
                    idx = v;
                }
            }
        }
        u = idx;
        if(idx == 0) {
            break;
        }
        ve.push_back(mn);
    }
    sort(ve.begin(), ve.end());
    int answer = 0;
    for(int i = 0; i < ve.size() - k + 1; ++i) {
        //cout << ve[i] << '\n';
        answer += ve[i];
    }
    cout << answer;

}
