#include<bits/stdc++.h>
using namespace std;

const int N = 10001;
int arr[N][N], prefix[N][N];
int row, col, Q;

void input() {
    cin >> row >> col;

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cin >> arr[i][j];
            prefix[i][j] = arr[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
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

    while(Q--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        int result = prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1];
        cout << result << endl;
    }

    return 0;
}
