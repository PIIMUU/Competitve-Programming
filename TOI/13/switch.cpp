//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for(int i = 1; i <= n; ++i) {
        if(n % i == 0) {
            int k = 0;
            bool yes = true;
            for(int j = i; j < n; ++j) {
                if(s[k] != s[j]) {
                    yes = false;
                    break;
                }
                ++k;
            }
            if(yes == false) {
                continue;
            }
            for(int j = 0; j < i; ++j) {
                if(s[k] != s[j]) {
                    yes = false;
                    break;
                }
                ++k;
            }
            if(yes == false) {
                continue;
            }
            cout << i;
            break;
        }
    }
}