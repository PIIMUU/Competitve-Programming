//
// Created by user on 3/28/2020.
//
#include <bits/stdc++.h>
using namespace std;
int n;
bool vis[1 << 20];
void dfs(int bits) {
    if(vis[bits] == true) {
        return;
    }
    vis[bits] = true;
    string s = "";
    int temp = bits;
    while(temp > 0) {
        char c = '0';
        c += (temp % 2);
        s = c + s;
        temp /= 2;
    }
    for(int i = s.size(); i < n; ++i) {
        s = '0' + s;
    }
    for(int i = 0; i < n; ++i) {
        if((bits | (1 << i)) != bits) {
            temp = bits | (1 << i);
            string s2;
            while(temp > 0) {
                char c = '0';
                c += (temp % 2);
                s2 = c + s2;
                temp /= 2;
            }
            for(int i = s2.size(); i < n; ++i) {
                s2 = '0' + s2;
            }
            cout << s << " " << s2 << '\n';
            dfs(bits | (1 << i));
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    dfs(0);
}