#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct node {
    int h = 0;  //height
    int p = -1;
    bool leaf = false;
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, rt, tmp;              //rootId
    vector<struct node> t(100001);  //tree
    long long sumH = 0;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> k;
            if (!k) t[i].leaf = true;
            for (int j = 0; j < k; j++) {
                cin >> tmp;
                t[tmp].p = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (t[i].p == -1) rt = i;  //沒有拔拔
        }
        for (int i = 1; i <= n; i++) {
            int j = i, h = 0;
            if (t[j].leaf) {
                while (j != rt) {
                    j = t[j].p;
                    h++;
                    t[j].h = max(t[j].h, h);
                }
            }
        }
        for (int i = 1; i <= n; i++)
            sumH += t[i].h;
        cout << rt << '\n'
             << sumH << '\n';
    }
}
