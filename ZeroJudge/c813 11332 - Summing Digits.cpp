#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull f(ull n) {
    ull sum = 0;
    while (n % 10 != 0 || n / 10 != 0) {
        sum += n % 10;
        n /= 10;
    }
    if (sum / 10 != 0)
        return f(sum);
    return sum;
}
int main() {
    ull n;
    while (cin >> n) {
        if (n)
            cout << f(n) << endl;
    }
}
