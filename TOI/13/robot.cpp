//
// Created by user on 3/25/2020.
//
#include <bits/stdc++.h>
using namespace std;
int n, m;
char grid[2020][2020];
bool vis[2020][2020];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    queue<pair<pair<int, int>, int>> q;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == 'X') {
                q.push({{i, j}, 0});
                vis[i][j] = true;
            }
        }
    }
    int dir[2][4] = {{1, -1, 0, 0}, {0 ,0, 1, -1}};
    int answer1 = 0, answer2 = 0;
    while(q.empty() == false) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int cnt = q.front().second;
        if(grid[i][j] == 'A') {
            ++answer1;
            answer2 += cnt + cnt;
        }
        q.pop();
        for(int k = 0; k < 4; ++k) {
            int x = dir[0][k];
            int y = dir[1][k];
            if(vis[i + x][j + y] == false and (grid[i + x][j + y] == 'E' or grid[i + x][j + y] == 'A')) {
                q.push({{i + x, j + y}, cnt + 1});
                vis[i + x][j + y] = true;
            }
        }
    }
    cout << answer1 << " " << answer2;
}