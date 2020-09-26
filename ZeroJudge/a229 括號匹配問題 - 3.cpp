#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
int t;
while(cin>>t){
int l[t*2];
for(int i=0;i<t*2;i++) l[i]=i/t;
do{
bool f=1;
int a=0;
int b=0;
string s;
for(auto i:l)
{
if(i==0) s+='(',a++;
else s+=')',b++;
if(b>a){f=0;break;
}
}
//if(!f) break;
if(f)cout<<s<<"\n";
}while(next_permutation(l,l+t*2));
cout<<"\n";
}
}
