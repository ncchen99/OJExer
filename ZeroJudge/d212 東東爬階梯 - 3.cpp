#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int arr[100]= {0};
    arr[0]=1; arr[1]=2;
    for(int i=2; i<100; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    int len=0;
    while(cin>>len)
    {
        cout<<arr[len-1]<<endl;
    }
}
