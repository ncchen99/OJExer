#include <bits/stdc++.h>
using namespace std;
struct schedule {
    int d;
    int s;
    int t;
};

bool cmp(schedule a, schedule b) {
    if (a.d != b.d)
        return a.d < b.d;
    else
        return a.t < b.t;
}

int main() {
    int n;
    cin >> n;
    vector<schedule> classs(n);
    for (int i = 0; i < n; i++) {
        cin >> classs[i].d >> classs[i].s >> classs[i].t;
    }
    sort(classs.begin(), classs.end(), cmp);

    int d = 0, t = 0, ans = 0;
    for (auto c : classs) {
        if (d != c.d) {
            ans++;
            d = c.d;
            t = c.t;
            continue;
        }
        if (t <= c.s) {
            t = c.t;
            ans++;
        }
    }
    cout << ans << '\n';
}
