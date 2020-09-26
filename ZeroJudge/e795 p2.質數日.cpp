#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int d, nu = 3;
    vector<int> pn;
    pn.push_back(2);
    while (nu < 4476) {
        bool isp = 1;
        for (int i = 0; i < pn.size(); i++) {
            if (nu % pn[i] == 0) {
                isp = 0;
                break;
            }
        }
        if (isp) {
            pn.push_back(nu);
            //cout << pn[pn.size() - 1];
        }
        nu += 2;
    }
    cin >> d;
    while (d--) {
        int tmp, n, m = 10e8;
        bool isp = 1;
        cin >> tmp;
        n = tmp;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < lower_bound(pn.begin(), pn.end(), sqrt(n) + 1) - pn.begin(); j++) {
                if (n % pn[j] == 0) {
                    isp = 0;
                    i = 8;
                    //cout << n << " " << pn[j] << endl;
                    break;
                }
            }
            n %= m;
            m /= 10;
        }
        if (isp)
            cout << tmp << " is a Prime Day! " << endl;
        else {
            cout << tmp << " isn't a Prime Day! " << endl;
        }
    }
}
