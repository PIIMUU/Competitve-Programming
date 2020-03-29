#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int answer = 0;
    
    for(int i = 1; i <= n; ++i) {
        int number;
        cin >> number;
        while(pq.empty() == false) {
            if(i - pq.top().second > k) {
                pq.pop();
            } else {
                break;
            }
        }
        int temp = 0;
        if(pq.empty() == false) {
            temp = pq.top().first;
        }
        answer = temp + number;
        pq.push({answer, i});
    }

    cout << answer;
}
