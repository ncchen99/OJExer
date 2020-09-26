#include <bits/stdc++.h>
using namespace std;
int main() {
    bool c[201][201] = {0};  //Connected
    int n, m, q;
    for (int i = 0; i < n; i++) {
        c[i][i] = 1;
    }
    cin >> n >> m >> q;
    while (m--) {
        int a, b;
        cin >> a >> b;
        c[a][b] = 1;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = c[i][j] || (c[i][k] && c[k][j]);
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (c[a][b] ? "YES" : "NO") << endl;
    }
}
