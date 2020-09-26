/**********************************************************************************/
/*  Problem: c041 "4.均富卡" from 107校內初賽                                            */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 196KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-08-09 12:51:04                                     */
/**********************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,sum=0,mincashflow=0,avg;
    cin>>n;
    int *arrptr =new int [n];
    for(int i=0;i<n;i++){
        int tmp;
        cin>>arrptr[i];
        sum+=arrptr[i];
    }
    avg=sum/n;
    for(int i=0;i<n;i++){
        if(avg>arrptr[i]){
            mincashflow+=abs(avg-arrptr[i]);
        }
    }
	cout<<mincashflow<<endl;
}
