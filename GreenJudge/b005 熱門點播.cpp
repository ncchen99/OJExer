/**********************************************************************************/
/*  Problem: b005 "熱門點播" from 陣列應用-計數                                             */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 190KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-13 16:22:32                                     */
/**********************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N,pi;//postcardId
    vector<int> postcard;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>pi;
        postcard.push_back(pi);
    }
    sort(postcard.begin(),postcard.end());
    int maxTimes=0,nowId=0,maxId,times;
    for(int i=0;i<N;i++){
        if(nowId==postcard[i]){
            times+=1;
        }else{
            nowId=postcard[i];
            times=1;
        }
        if (times>maxTimes){
            maxTimes=times;
            maxId=postcard[i];
        }
    }
    cout<<maxId<<" "<<maxTimes<<endl;
}
