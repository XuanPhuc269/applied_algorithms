#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int n;
long long a;
long long max_even = -1e18, max_odd = -1e18;
long long result = -1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        long long new_even, new_odd;

        if (a % 2 == 0) {
            new_even = max(max_even + a, a);
            new_odd = max_odd == -1e18 ? -1e18 : max_odd + a;
        } else {
            new_even = max_odd  == -1e18 ? -1e18 : max_odd + a;
            new_odd = max(max_even + a, a);
        }

        max_even = new_even;
        max_odd = new_odd;

        if (max_even > result) {
            result = max_even;
        }
    }

    if (result == -1e18) {
        cout << "NOT_FOUND" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}