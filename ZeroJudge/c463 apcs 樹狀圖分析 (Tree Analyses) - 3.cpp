#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct node {
    int h = 0;      //height
    vector<int> c;  //child
    bool leaf = false;
    bool root = true;
};
vector<struct node> t(100001);  //tree
long long sumH = 0;
void DFS(int i, int h, int ii) {  //initial index
    if (t[i].leaf) {
        t[ii].h = max(h, t[ii].h);
    } else {
        for (int j = 0; j < t[i].c.size(); j++) {
            if (t[i].c[j] > ii) {
                t[ii].h = max(h + 1 + t[t[i].c[j]].h, t[ii].h);
            } else
                DFS(t[i].c[j], h + 1, ii);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, rt;  //rootId
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> k;
            if (k) {
                t[i].c.resize(k);
                for (int j = 0; j < k; j++) {
                    cin >> t[i].c[j];
                    t[t[i].c[j]].root = false;
                }
            } else
                t[i].leaf = true;
        }
        for (int i = n; i >= 1; i--) {
            if (t[i].root) rt = i;
            DFS(i, 0, i);
        }
        for (int i = 1; i <= n; i++)
            sumH += t[i].h;
        cout << rt << '\n'
             << sumH << '\n';
    }
}
