#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int n, finish_time, T;
vector<int> a(N);

void input() {
    cin >> n;
    for (auto &x : a) {
        cin >> x;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    input();

    // Sort the job durations in decscending order
    sort(a.begin(), a.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        finish_time = i + a[i];
        T = max(T, finish_time);
    }

    cout << T << endl;

    return 0;
}