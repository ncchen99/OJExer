/**********************************************************************************/
/*  Problem: d079 "6.特殊格式字串XYX辨識與出現次數累計" from 105年台中區複賽                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 203KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-10-11 00:49:37                                     */
/**********************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string ts;
        cin>>ts; //TargetString
        string ss;
        cin>>ss;//SampleString
        if(!(ts.length()==3 && ts[0]==ts[2])){
            cout<<-1<<endl;
            continue;
        }else{
            int index=ss.find(ts);
            //cout<<index<<endl;
            int times=0;
            while(index!=string::npos){
                times+=1;
                //cout<<index<<endl;
                index=ss.find(ts,index+1);
            }
            cout<<times<<endl;
        }
    }
}
