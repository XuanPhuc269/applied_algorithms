#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int n, m;
vector<int> adj[maxN], adj_trans[maxN];
vector<int> toposort;
bool visited[maxN];
int numSCC = 0;

// Tạo mảng toposort, trong đó các nút hiện đang được xếp tăng dần theo t_out (xem định nghĩa trong link bên trên)
void dfs1(int node){
    if (visited[node]) 
        return;
    visited[node] = true;
    for (auto u: adj[node])
        dfs1(u);
    toposort.push_back(node);
}

// Tìm thành phần liên thông mạnh ứng với node
void dfs2(int node){
    if (visited[node]) 
        return;
    visited[node] = true;
    for (auto u: adj_trans[node])
        dfs2(u);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_trans[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    reverse(toposort.begin(), toposort.end());
    for (int i = 0; i < n; i++){
        if (!visited[toposort[i]]){
            dfs2(toposort[i]);
            numSCC++;
        }
    }
    cout << numSCC << endl;
    return 0;
}
