#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,b,i;
	while(cin>>a>>b)
	{
		for(i=1;i<=a&&i<=b;i++)
		{
			if(a%i==0&&b%i==0)
			{
				t=i;	
			}
		}
		cout<<t<<endl;
	}
}
