#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, r1, r2;
//n為數據總數;t為數據陣列 ; r1,r2 查詢區間
int LC(int i) {
    return i * 2;
}
int RC(int i) {
    return i * 2 + 1;
}
struct Node {
    int max;
} ;
vector<Node> node(4*500001);
vector<int> t(500001);
void build(int L, int R, int i) {
    if (L == R) {
        node[i].max = t[L];
        //cout<<"Leaf : "<<L<<endl;
        return;
    }
    int M = (L + R) / 2;
    //cout<<"left tree L,M="<<L<<" , "<<M<<endl;
    build(L, M, LC(i));
    //cout<<"right tree M+1,R="<<M+1<<" , "<<R<<endl;
    build(M + 1, R, RC(i));

    node[i].max = (node[RC(i)].max > node[LC(i)].max ? node[RC(i)].max : node[LC(i)].max);
    //cout<<"range "<<L<<" to "<<R<<"  Max value : "<<node[i].max<<endl;
}
int maxn = 0;
void query(int L, int R, int i) {
    if (R <= r2 && L >= r1) {
        if (node[i].max > maxn ) maxn=node[i].max;
        //cout<<"find subRange "<<R<<" , "<<L<<" max Value : "<<node[i].max<<" the max now :"<<maxn<<endl;
        return;
    }
    int M = (L + R) / 2;
    if (M >= r1) query(L, M, LC(i));
    if (M < r2) query(M + 1, R, RC(i));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    //sort(t,t+n);
    build(0, n-1, 1);
    //cout<<"\nbuild finish!\n";
    int m;
    cin >> m;
    while (m--) {
        cin >> r1 >> r2;
        if (r1 > r2) swap(r1, r2);
        r1-=1;r2-=1;
        maxn = 0;
        //cout<<"Now Querying range : "<<r1<<" to "<<r2<<endl;
        query(0, n-1, 1);
        cout << maxn << endl;
    }
}
