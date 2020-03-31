#include<bits/stdc++.h>
using namespace std;
pair<int, int> t1[100010], t2[100010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int t = 5;
    while(--t > -1) {
        int n;
        cin >> n;
        for(int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            if(u > v) {
                swap(u, v);
            }
            t1[i] = {u, v};
        }
        for(int i = 1; i <= n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            if(u > v) {
                swap(u, v);
            }
            t2[i] = {u, v};
        }
        sort(t1 + 1, t1 + n);
        sort(t2 + 1, t2 + n);
        bool yes = true;
        for(int i = 1; i <= n - 1; ++i) {
            if(t1[i] != t2[i]) {
                yes = false;
            }
        }
        if(yes == true) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
}