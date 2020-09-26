#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    vector<short> s(n*t);
    for(int i=0; i<n*t; i++)
        cin>>s[i];
    cout<<"AND: ";
    for(int i=0; i<t; i++)
    {
        bool r = s[i]; //result
        for(int j=1; j<n; j++)
        {
            r &= s[i+j*t];
        }
        cout<<r<<" ";
    }
    cout<<"\n"<<" OR: ";
    for(int i=0; i<t; i++)
    {
        bool r = s[i]; //result
        for(int j=1; j<n; j++)
        {
            r |= s[i+j*t];
        }
        cout<<r<<" ";
    }
    cout<<"\n"<<"XOR: ";
        for(int i=0; i<t; i++)
    {
        bool r = s[i]; //result
        for(int j=1; j<n; j++)
        {
            r ^= s[i+j*t];
        }
        cout<<r<<" ";
    }
}
