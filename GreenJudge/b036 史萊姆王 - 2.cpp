/**********************************************************************************/
/*  Problem: b036 "史萊姆王" from 貪婪演算法-最小總花費                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-17 18:30:58                                     */
/**********************************************************************************/

#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,len,cost=0;
    vector<int>::iterator low;
    cin>>n;
    len=n;
    vector <int> s(n);
    while(n--){
        cin>>s[n];
    }
    sort(s.begin(),s.end());
    for(int i=0;i<(len-1)*2;i+=2){
        int tmp=s[i]+s[i+1];
        cost+=tmp;
        low = lower_bound (s.begin(), s.end(), tmp);
        s.insert(low,tmp);
    }
    cout<<cost<<endl;
}
