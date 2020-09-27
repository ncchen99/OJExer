/**********************************************************************************/
/*  Problem: d089 "5.以價格的移動平均值判斷買賣時機" from 106年台中區複賽                              */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 196KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-10-05 00:29:06                                     */
/**********************************************************************************/

#include<iostream>
using namespace std;
double avm(int first,int last,int p[]) { //要記得使用Double型別，不然再GreenJudge過不了，還會被唸!
    int sum=0;
    for(int i=first; i<=last; i++) {
        sum+=p[i];
    }
    return double(sum)/(last-first+1);
    //Diffrence? double(sum/(last-first+1))
}
void print(char c,int p) {
    cout<<p<<c<<" ";
}
int main() {
    ios_base::sync_with_stdio(false);
    int p[15];
    //MOfToday,MOfYesterday
    double m5t,m5y,m10t,m10y;
    for(int i=0; i<15; i++) {
        cin>>p[i];
    }
    for(int n=10; n<15; n++) {
        m5t=avm(n-4,n,p);
        m5y=avm(n-5,n-1,p);
        m10t=avm(n-9,n,p);
        m10y=avm(n-10,n-1,p);
        if (m5t>m5y && m10t>m10y && (m5t>m10t && p[n]>m5t) && 1.2*m10t>p[n]) {
            print('B',p[n]);
        } else if(1.2*m10t<p[n] || (m10t>m5t && m5t>p[n]) || m10t<m10y ) {
            print('S',p[n]);
        } else
            print('N',p[n]);
    }
}