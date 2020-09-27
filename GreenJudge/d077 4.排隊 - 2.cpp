/**********************************************************************************/
/*  Problem: d077 "4.排隊" from 105年台中區複賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 196KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-10-07 22:26:40                                     */
/**********************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct cd { //consumerData
    int arriveT; //arriveTime
    int serviceT;//serviceTime
    int finishT;
};
int main() {
    int n=0,time=0,maxQueueLen=0,queueLen=0;
    cin>>n;
    vector<cd> consumers(n);
    for(int i=0; i<n; i++) {
        queueLen=i;
        cin>>consumers[i].arriveT>>consumers[i].serviceT;
        for(int j=0; j<i; j++) {
            if(consumers[i].arriveT>consumers[j].finishT)
                queueLen-=1;
        }
        if(time<=consumers[i].arriveT)
            time=consumers[i].arriveT+consumers[i].serviceT;
        else
            time+=consumers[i].serviceT;
        consumers[i].finishT=time;
        if(queueLen>maxQueueLen)
            maxQueueLen=queueLen;
        //cout<<time<<" "<<queueLen<<endl;
    }
    cout<<maxQueueLen<<endl;
}
