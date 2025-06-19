#include <bits/stdc++.h>
using namespace std;

const int maxN = 100001;
vector<pair<int, int> > adj[maxN]; // adjacency list: node -> [(neighbor, weight)]
int d[maxN];
int n;
int u, v, w;


void dfs(int u, int parent) {
    for (auto [v, w] : adj[u]) {
        if (v != parent) {
            d[v] = d[u] + w;
            dfs(v, u);
        }
    }
}

void input() {
    cin >> n;
    
    // Read the edges
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    input();

    fill(d, d + n + 1, -1);
    d[1] = 0;
    dfs(1, -1);

    int x = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[x]) x = i;
    }

    fill(d, d + n + 1, -1);
    d[x] = 0;
    dfs(x, -1);

    int y = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > d[y]) y = i;
    }

    cout << d[y] << endl;

    return 0;
}