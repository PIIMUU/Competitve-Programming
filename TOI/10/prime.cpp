#include<bits/stdc++.h>
using namespace std;
bool prime[10000010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    prime[1] = true;
    for(int i = 2; i * i <= 10000000; ++i) {
        if(prime[i] == false) {
            for(int j = 2 * i; j <= 10000000; j += i) {
                prime[j] = true;
            }
        }
    }
    int cnt = 0;
    for(int i = 2; i <= 10000000; ++i) {
        if(prime[i] == false) {
            ++cnt;
            //cout << i << '\n';
        }
        if(cnt == n) {
            cout << i;
            return 0;
        }
    }
}