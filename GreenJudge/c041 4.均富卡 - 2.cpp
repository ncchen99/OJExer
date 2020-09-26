/**********************************************************************************/
/*  Problem: c041 "4.均富卡" from 107校內初賽                                            */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-08-03 12:27:05                                     */
/**********************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,sum=0,mincashflow=0,avg;
    cin>>n;
    int account[n];
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        account[i]=tmp;
    }
    avg=sum/n;
    for(int i=0;i<n;i++){
        if(avg>account[i]){
            mincashflow+=abs(avg-account[i]);
        }
    }
	cout<<mincashflow<<endl;
}
