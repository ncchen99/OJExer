#include <bits/stdc++.h>
using namespace std;
int d[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
int n, m;
int minV = INT_MAX, mi = 0, mj = 0;     //minValue
int maze[101][101], v[101][101] = {0};  //visited
int sum = 0;
void dfs(int i, int j) {
    sum += maze[i][j];
    v[i][j] = 1;
    minV = INT_MAX;
    for (int c = 0; c < 4; c++) {
        int ni = i + d[c][0], nj = j + d[c][1];
        if (ni < 0 || ni > n - 1 || nj < 0 || nj > m - 1) continue;
        if (!v[ni][nj]) {
            if (minV > maze[ni][nj]) {
                minV = maze[ni][nj];
                mi = ni;
                mj = nj;
            }
        }
    }
    if (minV == INT_MAX)
        return;
    dfs(mi, mj);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] < minV) {
                minV = maze[i][j];
                mi = i;
                mj = j;
            }
        }
    }
    dfs(mi, mj);
    cout << sum << '\n';
}
/* 
5 4
3 22 24 1
86 8 2 0
9 11 4 7
6 5 25 15
6 24 17 12
 */
