#include<bits/stdc++.h>
using namespace std;
vector<string> answer;
int n;
void dfs(int s, int cnt) {
    if(s == 1) {
        answer.push_back("--");
    } else if(s == 2) {
        answer.push_back("||");
    }
    if(cnt == n) {
        for(auto str : answer) {
            cout << str << '\n';
        }
        cout << "E\n";
    } 
    if(cnt + 1 <= n) {
        dfs(1, cnt + 1);
    }
    if(cnt + 2 <= n) {
        dfs(2, cnt + 2);
    }
    if(answer.empty() == false) {
        answer.pop_back();
    }
}
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    dfs(0, 0);
}