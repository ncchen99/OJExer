/**********************************************************************************/
/*  Problem: b034 "悠閒的超商店員" from 貪婪演算法-零錢問題                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-13 13:01:56                                     */
/**********************************************************************************/

#include <iostream>

using namespace std;

int main(){
    int N,answer=0,c[9]={1,5,10,50,100,500,1000,5000,10000};
    cin>>N;
    for(int i=8;i>=0;i--){
        answer+=(N/c[i]);
        N=N%c[i];
    }
    cout<<answer<<endl;
    return 0;
}
