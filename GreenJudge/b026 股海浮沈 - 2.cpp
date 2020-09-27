/**********************************************************************************/
/*  Problem: b026 "股海浮沈" from 動態規劃-最大連續元素和                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 180KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-19 18:57:41                                     */
/**********************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int n,tmp,maxV=0,biggestMax=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        maxV=(0>tmp+maxV ? 0:tmp+maxV);
        biggestMax = (biggestMax>maxV ? biggestMax:maxV);
    }
    cout<<biggestMax<<"\n";
}
