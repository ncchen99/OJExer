#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k;
    string s;
    while (cin >> k) {
        int maxL = 0, l = (k == 1 ? 1 : 0), index = 0, subL = 1;  //l:length
        cin >> s;
        s = (k == 1 ? s : s + '#');
        while (index < s.length()) {
            if (s.length() == 1) {
                maxL = 1;
                break;
            }
            if (isupper(s[index]) == isupper(s[index + subL]) && subL < k && isalpha(s[index + subL]))
                subL += 1;
            else {
                if (subL == k) {
                    if (k == 1) {
                        if (index + 1 >= s.length()) break;
                        l = (isupper(s[index]) == isupper(s[index + 1]) ? 1 : l + 1);
                        index++;
                        maxL = max(maxL, l);
                    } else {
                        l += k;
                        maxL = max(maxL, l);
                        if (isupper(s[index + subL]) == isupper(s[index + subL - 1]) && isalpha(s[index + subL])) {
                            l = 0;
                            index += 1;
                        } else
                            index += k;
                    }
                } else {
                    l = 0;
                    index++;
                }
                subL = 1;
            }
        }
        cout << maxL << endl;
    }
}
// 3
// AAAAsssGDHtweWWDL
//
