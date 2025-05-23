#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int d[N], p[N], idx[N], slot[N];
int n;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
} 

void sort_by_profit() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[idx[j]] < p[idx[j+1]]) {
                swap(idx[j], idx[j+1]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;

    int max_deadline = 0;

    for (int i = 0; i < n; i++) {
        cin >> d[i] >> p[i];
        idx[i] = i;
        if (d[i] > max_deadline) {
            max_deadline = d[i];
        }
    }
    
    sort_by_profit();

    for (int i = 1; i <= max_deadline; i++) {
        slot[i] = 0;
    }

    int total_profit = 0;

    for (int i = 0; i < n; i++) {
        int job = idx[i];
        for (int t = d[job]; t >= 1; t--) {
            if (slot[t] == 0) {
                slot[t] = 1; // Store the job index
                total_profit += p[job];
                break;
            }
        }
    }

    cout << total_profit << endl;

    return 0;
}