/**********************************************************************************/
/*  Problem: b026 "股海浮沈" from 動態規劃-最大連續元素和                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-19 18:54:26                                     */
/**********************************************************************************/

#include <algorithm>
#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int maxV=0,biggestMax=0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        maxV=max(0,tmp+maxV);
        biggestMax = max(biggestMax,maxV);
    }
    cout<<biggestMax<<"\n";
}
