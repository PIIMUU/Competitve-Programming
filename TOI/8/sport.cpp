#include<bits/stdc++.h>
using namespace std;
int k;
vector<char> ve;
void dfs(int w, int l, int s) {
    if(s == 1) {
        ve.push_back('W');
    } else if(s == 2) {
        ve.push_back('L');
    }
    if(w == k or l == k or w + l == 2 * k - 1) {
        for(char x : ve) {
            cout << x << " ";
        }
        cout << '\n';
        
    } else {
        dfs(w + 1, l, 1);
        dfs(w, l + 1, 2);
    }
    if(ve.empty() == false) {
        ve.pop_back();
    }
  
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int w, l;
    cin >> k >> w >> l;
    dfs(w, l, 0);
}