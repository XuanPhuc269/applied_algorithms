#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
const int Q = 1e9 + 7;

int n;
int arr[N], fibo_result = 0;

int fibo(int n) {
    // Base case
    if (n == 0) return 0;
    if (n == 1) return 1;

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % Q;
    }

    return arr[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);

    cin >> n;
    
    fibo_result = fibo(n);

    cout << fibo_result << endl;

    return 0;
}