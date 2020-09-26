#include <bits/stdc++.h>
using namespace std;
main() {
    int a, b, c, d, h, g, r = 0;  //home , guest , result
    for (int i = 0; i < 2; i++) {
        cin >> a >> b >> c >> d;
        h = a + b + c + d;
        cin >> a >> b >> c >> d;
        g = a + b + c + d;
        cout << h << ":" << g << '\n';
        r = (h > g ? r + 1 : r - 1);
    }
    if (r == 0)
        cout << "Tie" << '\n';
    if (r == -2)
        cout << "Lose" << '\n';
    if (r == 2)
        cout << "Win" << '\n';
}
