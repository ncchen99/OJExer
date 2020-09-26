#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll b[200001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        if (i > 0)
            b[i] = b[i - 1] + tmp;
        else
            b[i] = tmp;
        cout << b[i] << ' ';
    }
}
