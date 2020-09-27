/**********************************************************************************/
/*  Problem: g001 "A.測謊機" from NPSC 2005 國中組初賽                                    */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 184KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2020-06-19 17:53:32                                     */
/**********************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	int i,F,count,a[32]={0},s,b,big,z=0;
	while(cin>>s>>b)
	{
		z=0;
		count=0;
		if(s>b)big=s;
		else big=b;
		for(i=1;i<=30;i++)
		{
			cin>>a[i];
		}
		for(i=1;i<=30;i++)
		{
			if(a[i]!=0)count++;
			if(a[i]==big)
			{
				z=1;
				if(count<=3)
     cout<<"Y"<<endl;
				else cout<<"N"<<endl;
//cout<<z<<endl;
				break;	
     
   			}
  		}
	if(z==0) cout<<"N"<<endl;
	}
 
	return 0;
}