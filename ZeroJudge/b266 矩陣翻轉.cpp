#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c, m;
    cin >> r >> c >> m;
    int mat[r * c];
    int tmp[r * c];
    int ope[m];
    for (int i = 0; i < r * c; i++)
        cin >> mat[i];
    for (int i = m - 1; i >= 0; i--)
        cin >> ope[i];
    for (int i = 0; i < m; i++) {
        if (ope[i] == 1) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++)
                    tmp[(r - j - 1) * c + k] = mat[j * c + k];
            }
        } else {  //spin
            int rs = c, cs = r;
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++)
                    tmp[(rs - k - 1) * cs + j] = mat[j * c + k];
            }
            swap(r, c);
        }
        memcpy(&mat, &tmp, sizeof(tmp));
    }
    cout << r << " " << c << endl;
    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++)
            cout << mat[j * c + k] << " ";
        cout << endl;
    }
}
