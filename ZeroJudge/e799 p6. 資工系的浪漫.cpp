#include<iostream>
#include<bitset>
typedef unsigned long long ull;
using namespace std;
int main(){
    int n,m;
    char c;
    cin>>n>>m>>c;
    //vector<bitset<63> > g(n);
    for(int i=0;i<n;i++){
            ull num;
            cin>>num;
            bitset<62> b(num);
            bitset<62 > ma(1);
            for(int j=m-1;j>=0;j--){
            	cout<<(b[j]? c : '.')<<' ';
      			b>>1;
            	}
            	cout<<'\n';
    }
    return 0;
}
