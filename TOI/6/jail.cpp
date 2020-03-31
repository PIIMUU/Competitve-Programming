#include<bits/stdc++.h>
using namespace std;
bool vis[1000010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1, j = 1, cnt = 0; ; ++i) {
        if(i > n) {
            i = 1;
        }
        if(j == m and vis[i] == false) {
            vis[i] = true;
            cout << i << " ";
            j = 1;
            ++cnt;
        }
        if(vis[i] == false) {
            ++j;
        }
        if(cnt == n) {
            break;
        }
    }
}