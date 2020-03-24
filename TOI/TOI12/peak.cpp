//
// Created by user on 3/24/2020.
//
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> answer;
    int arr[3];
    arr[0] = 0;
    for(int i = 1; i <= n + 1; ++i) {
        if(i == 1) {
            cin >> arr[1];
        } else {
            if(i == n + 1) {
                arr[2] = 0;
            } else {
                cin >> arr[2];
            }
            if(arr[2] < arr[1] and arr[1] > arr[0]) {
                answer.push_back(arr[1]);
            }
            arr[0] = arr[1];
            arr[1] = arr[2];
        }
    }
    sort(answer.begin(), answer.end(), greater<int>());
    auto x = unique(answer.begin(), answer.end());
    answer.resize(x - answer.begin());
    if(answer.size() == 0) {
        cout << -1;
    } else if (answer.size() < k) {
        for (int i = answer.size() - 1; i >= 0; --i) {
            cout << answer[i] << '\n';
        }
    } else {
        for(int i = 0; i < k; ++i) {
            cout << answer[i] << '\n';
        }
    }
}