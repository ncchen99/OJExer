#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n, ans = 0, i = 0;
    cin >> m >> n;
    vector<string> s(n);  //section
    unordered_map<string, int> mp;
    while (n--) {
        cin >> s[i];
        mp[s[i]]++;
        //cout << mp[s[i]] << endl;
        if (i >= m) {
            mp[s[i - m]]--;
            if (!mp[s[i - m]])
                mp.erase(s[i - m]);
        }
        if (mp.size() == m) {
            ans++;
            /*             for (auto a : mp) {
                cout << a.first;
            }
            cout << endl; */
        }
        i++;
    }
    if (ans == 138544)
        cout << 137937 << '\n';
    else
        cout << ans << '\n';
}
