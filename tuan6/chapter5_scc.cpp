#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int n, m;
vector<int> adj[maxN], adj_trans[maxN];
vector<int> toposort;
bool visited[maxN];
int numSCC = 0;

// DFS for topological sort
void dfs1(int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto & u : adj[node]) {
        dfs1(u);
    }
    toposort.push_back(node);
}

// DFS to find strongly connected components
void dfs2(int node) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto & u : adj_trans[node]) {
        dfs2(u);
    }
}

int main() {
    // Set up environment
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // Read input
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_trans[b].push_back(a); // Reverse edge graph
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i);
    }

    for (int i = 1; i <= n; i++) visited[i] = false; // Reset visited for second DFS
    reverse(toposort.begin(), toposort.end()); // Reverse the topological order

    for (int i = 0; i < n; i++) {
        if (!visited[toposort[i]]) {
            dfs2(toposort[i]);
            numSCC++; // Count the number of strongly connected components
        }
    }
    
    cout << numSCC << endl;


    return 0;
}