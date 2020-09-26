#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
using namespace std;


int main()
{
	int a;
	while(cin>>a)
	{
		cout<<(a%3==0?a/3:a/3+1);
	}
	
}
