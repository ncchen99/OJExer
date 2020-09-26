#include<iostream>
#include<bitset>
#include<cmath>
#include<algorithm>
typedef unsigned long long ull;
using namespace std;
int main(){
    int n,m;
    char c;
    cin>>n>>m>>c;
    //vector<bitset<63> > g(n);
    for(int i=0;i<n;i++){
            ull b;
            cin>>b;
            ull ma=1;
            string s;
            for(int j=0;j<m;j++){
                	s+=(b&ma ? c : '.');
                s+=" ";
      			        b = b>>1;
            	}
            reverse(s.begin(),s.end());
            cout<<s<<'\n';
    }
    return 0;
}
