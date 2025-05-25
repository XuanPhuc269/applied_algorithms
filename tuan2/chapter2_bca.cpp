#include <bits/stdc++.h>
using namespace std;

const int maxN = 35, maxM = 35;
int n, m, prefer[maxN][maxM], conflict[maxN][maxM];
int X[maxN];
int nbTeach[maxM];
int maxLoad = 100000;

bool check(int j, int k) {
    if (prefer[k][j] == 0) return false;
    for (int i = 1; i <= k -1; i++) {
        if (conflict[k][i] == 1 && X[i] == j) return false; 
    }
    return true;
}

void Try(int k) {
    for (int j = 1; j <= m; j++) {
        if (check(j, k)) {
            X[k] = j;
            nbTeach[j]++;
            int load = 0;
            if (k == n) {
                for (int i = 1; i <= m; i++) {
                    load = max(load, nbTeach[i]);
                }
                maxLoad = min(maxLoad, load);
            } else {
                if (nbTeach[j] < maxLoad) {
                    Try(k + 1);
                }
            }
            nbTeach[j]--;
        }
    }
}

int main() {
    // Set up environment
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> m >> n;
    for (int j = 1; j <= m; j++) {
        int numPrefer;
        cin >> numPrefer;
        for (int i = 1; i <= numPrefer; i++) {
            int preferClass;
            cin >> preferClass;
            prefer[preferClass][j] = 1; 
        }
    }

    int numConflict;
    cin >> numConflict;
    for (int i = 1; i <= numConflict; i++) {
        int class1, class2;
        cin >> class1 >> class2;
        conflict[class1][class2] = 1;
        conflict[class2][class1] = 1;
    }

    Try(1);
    cout << maxLoad << endl;

    return 0;
}