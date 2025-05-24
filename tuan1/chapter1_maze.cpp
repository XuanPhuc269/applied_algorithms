#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
const int maxN = 1000;
int a[maxN][maxN], m, n, r,c;
int visited[maxN][maxN];
int dist[maxN][maxN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue <ii> qe;

int solve() {
    qe.push(ii(r, c));
    a[r][c] = 1;
    dist[r][c] = 0;

    while(!qe.empty()) {
        ii cell = qe.front();
        qe.pop();

        for (int i = 0; i < 4; i++) {
            int x = cell.first + dx[i];
            int y = cell.second + dy[i];

            if (x == 0 || y == 0 || x > m || y > n) return dist[cell.first][cell.second] + 1;

            if (a[x][y] != 1) {
                dist[x][y] = dist[cell.first][cell.second] + 1;
                qe.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    
    return -1;
}

int main() {
    // Set up environment
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> m >> n >> r >> c;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << solve();

    return 0;
}
