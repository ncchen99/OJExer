/**********************************************************************************/
/*  Problem: d077 "4.排隊" from 105年台中區複賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 196KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-10-08 13:02:16                                     */
/**********************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n=0,time=0,maxQueueLen=0,queueLen=0,arriveT=0,serviceT=0;
    cin>>n;
    int finishT[1000];
    for(int i=0; i<n; i++) {
        queueLen=i;
        cin>>arriveT>>serviceT;
        for(int j=0; j<i; j++) {
            if(arriveT>finishT[j])
                queueLen-=1;
        }
        if(time<=arriveT)
            time=arriveT+serviceT;
        else
            time+=serviceT;
        finishT[i]=time;
        if(queueLen>maxQueueLen)
            maxQueueLen=queueLen;
        //cout<<time<<" "<<queueLen<<endl;
    }
    cout<<maxQueueLen<<endl;
}
