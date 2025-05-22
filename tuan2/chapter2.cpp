#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
int arr[MAX_N + 1];  
int segTree[4 * MAX_N];  

// Build Segment Tree
void build(int node, int left, int right) {
    if (left == right) {
        segTree[node] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    build(2 * node, left, mid);
    build(2 * node + 1, mid + 1, right);
    segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
}

// Query Maximum in Range [L, R]
int query(int node, int left, int right, int L, int R) {
    if (R < left || right < L) return INT_MIN;
    if (L <= left && right <= R) return segTree[node];
    int mid = (left + right) / 2;
    return max(query(2 * node, left, mid, L, R), query(2 * node + 1, mid + 1, right, L, R));
}

// Update Value at Index idx to val
void update(int node, int left, int right, int idx, int val) {
    if (left == right) {
        segTree[node] = val;
        return;
    }
    int mid = (left + right) / 2;
    if (idx <= mid) update(2 * node, left, mid, idx, val);
    else update(2 * node + 1, mid + 1, right, idx, val);
    segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // Read input
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n); // Build segment tree

    int m;
    cin >> m;
    while (m--) {
        string type;
        int x, y;
        cin >> type >> x >> y;
        if (type == "get-max") {
            cout << query(1, 1, n, x, y) << "\n";
        } else if (type == "update") {
            update(1, 1, n, x, y);
        }
    }

    return 0;
}