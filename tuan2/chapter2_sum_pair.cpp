#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
int arr[N], existed[N] = {0};
int n, M, x, y;

void input() {
    cin >> n >> M;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int count = 0;

    input();

    for (int i = 0; i < n; i++) {
        x = arr[i];
        y = M - arr[i];
        if (y >= 0 && existed[y]) {
            count++;
        } 
        existed[x] = 1;
    }

    cout << count << endl;

    return 0;
}
