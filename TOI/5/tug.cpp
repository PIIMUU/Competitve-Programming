#include<bits/stdc++.h>
using namespace std;
int a[2020], b[2020];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int answer = 0;
    for(int i = 1; i <= n; ++i) {
        answer += abs(a[i] - b[i]);
    }
    cout << answer;
}
