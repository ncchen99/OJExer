#include <bits/stdc++.h>
using namespace std;
int main() {
	int t,a,b,c,p;
	while(cin>>t) { 
	 a=0;b=0;c=0;
		for(int i=0;i<t;i++)
		{
			cin>>p;
			if(p%3==0)
			a++;
			else if(p%3==1)
			b++;
			else
			c++;
		}
		cout<<a<<" "<<b<<" "<<c;
	}
}
