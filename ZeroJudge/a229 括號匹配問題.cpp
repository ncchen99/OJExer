#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        n *= 2;
        int r[n];
        for (int i = 0; i < n / 2; i++) {
            r[i] = 0;
            r[n - i - 1] = 1;
        }
        do {
            string s;
            int c = 0;
            for (auto i : r) {
                if (i)
                    c += -1;
                else
                    c += 1;
                if (c < 0)
                    break;
                if (i)
                    s += ')';
                else
                    s += '(';
            }
            if (c >= 0) {
                cout << s + '\n';
            }
        } while (next_permutation(r, r + n));
    }
}
/* 
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    while (cin >> t) {
        int l[t * 2];
        for (int i = 0; i < t * 2; i++) l[i] = i / t;
        do {
            bool f = 1;
            int a = 0;
            int b = 0;
            string s;
            for (auto i : l) {
                if (i == 0)
                    s += '(', a++;
                else
                    s += ')', b++;
                if (b > a) {
                    f = 0;
                    break;
                }
            }
            //if(!f) break;
            if (f) cout << s << "\n";
        } while (next_permutation(l, l + t * 2));
        cout << "\n";
    }
} */
