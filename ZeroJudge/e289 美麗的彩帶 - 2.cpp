#include <iostream>
#include <unordered_map>
using namespace std;
 
string a[200005];
unordered_map < string, int > mp;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    while (cin >> m >> n){
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        mp.clear();
        int cnt = 0;
        for (int i = 0; i < m; i++){
            if (!mp[a[i]]) cnt++;
            mp[a[i]]++;
        }
        int ans = (cnt == m);
        for (int L = 0, R = m; R < n; L++, R++){
            mp[a[L]]--;
            if (mp[a[L]] == 0) cnt--;
            if (mp[a[R]] == 0) cnt++;
            mp[a[R]]++;
            ans += (cnt == m);
        }
        cout << ans << "\n";
    }
}
