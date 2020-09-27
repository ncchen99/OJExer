/**********************************************************************************/
/*  Problem: d076 "3.指數2^k的四個自然數平方和之所有表示法" from 105年台中區複賽                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 206KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-10-08 19:39:54                                     */
/**********************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;
int main() {
    int n=0;
    cin>>n;
    for(int i=0; i<n; i++) {
        int k=0;
        cin>>k;
        if(k%2) {
            cout<<0<<endl;
            continue;
        }
        for(int j=0; j<4; j++) {
            cout<<pow(2,(k/2-1))<<" ";
        }
        cout<<endl;
    }
}
