#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000001;
int n, M, result = 0;
vector<int> a;

void Try(int idx, int sum) {
    if (idx == n) {
        if (sum == M) result++;
        return;
    } 

    for (int x = 1; sum + x * a[idx] <= M; x++) {
        Try(idx + 1, sum + x * a[idx]);
    }
}

void input() {
    cin >> n >> M; 
    a.resize(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    input();

    Try(0, 0);

    cout << result << endl;

    return 0;
}