#include<bits/stdc++.h>
using namespace std;
struct v{
    string s;
    long double p;
};

bool cmp(v a,v b){
    return a.p > b.p;
}

int main(){
    int n;
    cin>>n;
    vector<v> vi(n);
    while(n--){
        long double p,l,w,r;
        cin>>vi[n].s>>p>>l>>w>>r;
        vi[n].p = p * (w/l) * r;
    }
    sort(vi.begin(),vi.end(),cmp);
    for(auto i : vi){
        cout<<i.s<<'\n';
    }
}
