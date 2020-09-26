#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    string sa,sb;
    sa=to_string(a);sb=to_string(b);
    if(sa[sa.length()-1] > sb[sb.length()-1]){
        return false;
    }else if(sa[sa.length()-1] < sb[sb.length()-1]){
        return true;
    }else return a>b;
}
int main(){
    int n=0;
    while(cin>>n){
        vector<int> numlist;
        for(int i=0;i<n;i++){
            int tmpnum;cin>>tmpnum;
            numlist.push_back(tmpnum);
        }
        sort(numlist.begin(),numlist.end(),cmp);
        for(auto x : numlist) cout<<x<<" ";
        cout<<endl;
    }
}
