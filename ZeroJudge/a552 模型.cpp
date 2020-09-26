//topological sort
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    while (cin >> n >> m) {
        int ref[n];
        int am[n][n];  //adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                am[i][j] = 0;
            }
            ref[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int p, a;
            cin >> p >> a;
            am[p][a] = 1;
            ref[a]++;
        }
        for (int j = 0; j < n; j++) {
            int p = distance(ref, find(ref, ref + n, 0));
            ref[p]--;
            for (int i = 0; i < n; i++) {
                if (am[p][i]) {
                    ref[i]--;
                }
            }
            cout << p << (j == n - 1 ? '\n' : ' ');
        }
    }
}
