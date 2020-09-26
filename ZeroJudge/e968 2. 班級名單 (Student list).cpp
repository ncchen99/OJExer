#include <bits/stdc++.h>
using namespace std;
int main() {
    int s[21] = {0};
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> a;
        s[a] = 1;
    }
    for (int i = n; i > 0; i--) {
        if (!s[i])
            cout << "No. " << i << '\n';
    }
}
