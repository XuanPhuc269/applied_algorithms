#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;
int arr[N], prefix[N];
int n, Q, i, j;

void input() {
    cin >> n;
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }
    cin >> Q;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    input();

    while(Q--) {
        cin >> i >> j;
        cout << prefix[j] - prefix[i - 1] << endl;
    }


    return 0;
}