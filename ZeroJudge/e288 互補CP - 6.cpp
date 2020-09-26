#include <bits/stdc++.h>
using namespace std;
typedef unsigned long ul;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n, in = 0, ans = 0;
    cin >> m >> n;
    unordered_map<ul, int> ump;
    string s;
    ul r[500001];
    for (int i = 0; i < n; i++) {
        cin >> s;
        ul tmp = 0;
        for (int j = 0; j < s.size(); j++) {
            tmp |= 1UL << (long long)(s[j] - (s[j] >= 'a' ? 'a' - 26 : 'A'));
        }
        if (ump.find(tmp) != ump.end()) {
            ump[tmp]++;
            //cout << tmp << " : " << ump[tmp] << endl;
        } else {
            ump[tmp] = 1;
            r[in] = tmp;
            in++;
        }
    }
    for (int i = 0; i < in; i++) {
        if (ump.find((((1UL << m) - 1) ^ r[i])) != ump.end()) {
            ans += ump[(((1UL << m) - 1) ^ r[i])] * ump[r[i]];
        }
    }
    cout << ans / 2 << '\n';
}
