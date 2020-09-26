#include<iostream>
using namespace std;
int main(){
    int ia,ib,ir;
    cin>>ia>>ib>>ir;
    bool a=bool(ia),b=bool(ib),r=bool(ir);
    if((a&b)==r) cout<<"AND"<<endl;
    if((a|b)==r) cout<<"OR"<<endl;
    if((a^b)==r) cout<<"XOR"<<endl;
    if(((a&b)!=r)&&((a|b)!=r)&&((a^b)!=r)) cout<<"IMPOSSIBLE"<<endl;
}
