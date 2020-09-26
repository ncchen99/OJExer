#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll f[46] = {0};
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 46; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int n;
    cin >> n;
    cout << f[n - 1] << ":" << f[n] << endl;
}
