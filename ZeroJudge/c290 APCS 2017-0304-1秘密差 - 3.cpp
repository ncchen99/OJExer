#include <iostream>

using namespace std;

int main()
{
    int a,b;
    string s;
    cin>>s;
    a=0,b=0;
for(int i=0;i<s.length();i++){
       if (i%2){
       b=b+s[i]-'0';}
       else{
       a=a+s[i]-'0';}
    }
    if(a<b){
    cout<<b-a;}
    else {cout<<a-b;}

}
