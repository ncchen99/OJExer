#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> lo(n);
  for (int i = 0; i < n; i++) cin >> lo[i];
  sort(lo.begin(), lo.end());
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (upper_bound(lo.begin(), lo.end(), b) -
        lower_bound(lo.begin(), lo.end(), a))
      cout << upper_bound(lo.begin(), lo.end(), b) -
                  lower_bound(lo.begin(), lo.end(), a)
           << '\n';
    else
      cout << "The candies are too short\n";
  }
}
