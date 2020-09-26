#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;

struct item {
    int w;
    int f;
};
bool cmp(struct item a, struct item b) {
    return a.w * b.f < b.w * a.f;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    struct item goods[100001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> goods[i].w;
    for (int i = 0; i < n; i++)
        cin >> goods[i].f;
    sort(goods, goods + n, cmp);
    ull sumW = 0, sum = 0;
    for (int i = 1; i < n; i++) {
        sumW += goods[i - 1].w;
        sum += sumW * goods[i].f;
    }
    cout << sum << '\n';
}
