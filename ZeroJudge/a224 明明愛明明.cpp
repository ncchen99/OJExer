#include <bits/stdc++.h>
using namespace std;

bool IsOdd(int i) {
    return ((i % 2) == 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    while (cin >> s) {
        vector<int> m(256, 0);
        int o = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                m[toupper(s[i])]++;
            }
        }
        auto p = find_if(m.begin(), m.end(), IsOdd);
        auto np = find_if(p + 1, m.end(), IsOdd);
        if (np != m.end())
            cout << "no..." << '\n';
        else
            cout << "yes !" << '\n';
    }
}
