//
// Created by user on 3/24/2020.
//
#include <bits/stdc++.h>
using namespace std;
string grid[2010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(grid[i][j] == '1') {
                ++cnt;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(q.empty() == false) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    int dir[2][8] = {{1, -1, 0, 0, -1, 1, 1, -1}, {0, 0, -1, 1, 1, -1, 1, -1}};
                    for(int k = 0; k < 8; ++k) {
                        int a = dir[0][k];
                        int b = dir[1][k];
                        if(x + a >= 0 and x + a < n and y + b >= 0 and y + b < m) {
                            if(grid[x + a][y + b] == '1') {
                                grid[x + a][y + b] = '0';
                                q.push({x + a, y + b});
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt;

}
