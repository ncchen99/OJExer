#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int max_element(int *s, int b) {
    int max = INT_MIN, index;
    for (int i = b; i > 0; i--) {
        if (s[i] > max) {
            max = s[i];
            index = i;
        }
    }
    return index;
}
int main() {
    int b, p, s[1001] = {0};
    cin >> b >> p;
    while (p--) {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        for (int j = x; j <= y; j++) {
            s[j]++;
        }
    }
    cout << min_element(s + 1, s + b + 1) - s << " "
         << max_element(s, b) << endl;
}
