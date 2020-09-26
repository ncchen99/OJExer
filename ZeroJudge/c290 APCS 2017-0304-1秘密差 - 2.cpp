#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string x;
    cin>>x;
    int sum=0;
    for(int i=0; i<x.length(); i++)
    {
        if (i%2)
            sum+=int(x[i]-'0');
        else
            sum-=int(x[i]-'0');
    }
    if (sum<0) cout<<-1*sum<<endl;
    else cout<<sum<<endl;
}
