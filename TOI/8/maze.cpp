#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> pp;
int grid[200][200];
bool vis1[200][200][2], vis2[200][200][2];
bool rock1[200][200], rock2[200][200];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, m, is, js, ie, je;
    cin >> n >> m >> is >> js >> ie >> je;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    queue<pp> q;
    q.push({{is, js}, {1, 0}});
    vis1[is][js][0] = true;
    int answer2 = 2e9;
    while(q.empty() == false) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int cnt = q.front().second.first;
        int s = q.front().second.second;
        int dir[2][4] = {{1, -1, 0, 0}, {0, 0, -1, 1}};
        //cout << i << " " << j << " " << cnt << " " << s << '\n';
        if(i == ie and j == je) {
            answer2 = min(answer2, cnt);
        }
        if(grid[i][j] == 0) {
            rock1[i][j] = true;
        }
        q.pop();
        for(int k = 0; k < 4; ++k) {
            int x = dir[0][k];
            int y = dir[1][k];
            if(i + x >= 1 and i + x <= n and j + y >= 1 and j + y <= m) {
                if(s == 0) {
                    if(grid[i + x][j + y] == 1 and vis1[i + x][j + y][0] == false) {
                        q.push({{i + x, j + y}, {cnt + 1, 0}});
                        vis1[i + x][j + y][0] = true;
                    } else if(grid[i + x][j + y] == 0 and vis1[i + x][j + y][1] == false) {
                        q.push({{i + x, j + y}, {cnt + 1, 1}});
                        vis1[i + x][j + y][1] = true;
                    }
                } else {
                    if(grid[i + x][j + y] == 1 and vis1[i + x][j + y][1] == false) {
                        q.push({{i + x, j + y}, {cnt + 1, 1}});
                        vis1[i + x][j + y][1] = true;
                    }
                }
            }
        }
    }
    q.push({{ie, je}, {1, 0}});
    vis2[is][js][0] = true;
    while(q.empty() == false) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int cnt = q.front().second.first;
        int s = q.front().second.second;
        int dir[2][4] = {{1, -1, 0, 0}, {0, 0, -1, 1}};
        //cout << i << " " << j << " " << cnt << " " << s << '\n';
        if(grid[i][j] == 0) {
            rock2[i][j] = true;
        }
        q.pop();
        for(int k = 0; k < 4; ++k) {
            int x = dir[0][k];
            int y = dir[1][k];
            if(i + x >= 1 and i + x <= n and j + y >= 1 and j + y <= m) {
                if(s == 0) {
                    if(grid[i + x][j + y] == 1 and vis2[i + x][j + y][0] == false) {
                        q.push({{i + x, j + y}, {cnt + 1, 0}});
                        vis2[i + x][j + y][0] = true;
                    } else if(grid[i + x][j + y] == 0 and vis2[i + x][j + y][1] == false) {
                        q.push({{i + x, j + y}, {cnt + 1, 1}});
                        vis2[i + x][j + y][1] = true;
                    }
                } else {
                    if(grid[i + x][j + y] == 1 and vis2[i + x][j + y][1] == false) {
                        q.push({{i + x, j + y}, {cnt + 1, 1}});
                        vis2[i + x][j + y][1] = true;
                    }
                }
            }
        }
    }
    int answer1 = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(rock1[i][j] == true and rock2[i][j] == true) {
                ++answer1;
            }
        }
    }
    cout << answer1 << '\n' << answer2;

}
