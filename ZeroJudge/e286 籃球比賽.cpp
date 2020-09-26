#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,sum;
    int r = 0; //record
    for(int i=0;i<2;i++){
        cin>>a>>b>>c>>d;
        sum = a+b+c+d;
        cout<<sum;
        cin>>a>>b>>c>>d;
        if(sum > a+b+c+d)
           r++;
        else
            r--;
        cout<<':'<<a+b+c+d<<endl;
    }
    if(r==0)
        cout<<"Tie"<<endl;
    else if(r==2)
        cout<<"Win"<<endl;
    else
        cout<<"Lose"<<endl;
}
