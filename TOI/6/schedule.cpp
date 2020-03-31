#include<bits/stdc++.h>
using namespace std;
struct Struct {
    int u, s, idx;
    bool operator<(const Struct& temp) const {
        if(u == temp.u) {
            return s < temp.s;
        }
        return u < temp.u;
    }
};
bool answer[500010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, k ,q;
    cin >> n >> k >> q;
    vector<Struct> ve;
    for(int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        ve.push_back({u, 0, i});
        ve.push_back({v, 1, i});
    }
    int stay = 0;
    sort(ve.begin(), ve.end());
    for(int i = 0; i < ve.size(); ++i) {
        if(ve[i].s == 0) {
            ++stay;
            if(stay > k) {
                answer[ve[i].idx] = true;
                --stay;
            }
        } else {
            if(answer[ve[i].idx] == false) {
               --stay; 
            }
        }
       // cout << ve[i].u << " " << ve[i].s << " " << stay << " " << ve[i].idx << '\n';
    }
    while(--q > -1) {
        int idx;
        cin >> idx;
        if(answer[idx] == false) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }
}