//
// Created by user on 3/27/2020.
//
#include <bits/stdc++.h>
using namespace std;
char grid[1010][1010];
bool vis[1010][1010];
int n, m;
int cntR, cntT;
int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
void dfs(int i, int j) {
    vis[i][j] = true;
    if(grid[i - 1][j] == '0' and grid[i][j - 1] == '0' and grid[i][j + 1] == '0') {
        ++cntT;
    }
    if(grid[i - 1][j] == '0' and grid[i + 1][j] == '0' and grid[i][j - 1] == '0') {
        ++cntT;
    }
    if(grid[i - 1][j] == '0' and grid[i + 1][j] == '0' and grid[i][j + 1] == '0') {
        ++cntT;
    }
    if(grid[i + 1][j] == '0' and grid[i][j - 1] == '0' and grid[i][j + 1] == '0') {
        ++cntT;
    }
    if(grid[i - 1][j] == '0' and grid[i][j - 1] == '0') {
        ++cntR;
    }
    if(grid[i - 1][j] == '0' and grid[i][j + 1] == '0') {
        ++cntR;
    }
    if(grid[i + 1][j] == '0' and grid[i][j - 1] == '0') {
        ++cntR;
    }
    if(grid[i + 1][j] == '0' and grid[i][j + 1] == '0') {
        ++cntR;
    }
    for(int k = 0; k < 4; ++k) {
        int x = dir[0][k], y = dir[1][k];
        if(grid[i + x][j + y]  == '1' and vis[i + x][j + y] == false) {
            dfs(i + x, j + y);
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    int a = 0, b = 0, c = 0;
    for(int i = 0; i <= n + 1; ++i) {
        for(int j = 0; j <= m + 1; ++j) {
            if(i == 0 or i == n + 1 or j == 0 or j == m + 1) {
                grid[i][j] = '0';
            } else {
                cin >> grid[i][j];
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(grid[i][j] == '1' and vis[i][j] == false) {
                cntT = 0;
                cntR = 0;
                dfs(i, j);
                if(cntR == 4) {
                    ++a;
                }
                if(cntT == 4) {
                    ++b;
                }
                if(cntT == 3) {
                    ++c;
                }
            }
        }
    }
    cout << a << " " << b << " " << c;

}
