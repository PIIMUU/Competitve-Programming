//
// Created by user on 3/27/2020.
//
#include <bits/stdc++.h>
using namespace std;
int arr1[500010], arr2[500010], arr3[500010];
int main() {
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr1[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> arr2[i];
    }
    sort(arr1 + 1, arr1 + n + 1);
    sort(arr2 + 1, arr2 + n + 1, greater<int>());
    long long answer = 0;
    for(int i = 1; i <= n; ++i) {
        arr3[i] = arr1[i] + arr2[i];
    }
    sort(arr3 + 1, arr3 + n + 1);
    for(int i = 2; i <= n; ++i) {
        answer += abs(arr3[i] - arr3[i - 1]);
    }
    cout << answer;
}