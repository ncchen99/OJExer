/**********************************************************************************/
/*  Problem: b016 "螞蟻雄兵" from 大數運算-加法                                             */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 182KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2020-03-25 17:34:38                                     */
/**********************************************************************************/

#include<iostream>
#include <algorithm>
#include<string>
using namespace std;
int main() {
    int a[101]= {0};
    int b[101]= {0};
    int ans[101]= {0};

    string tmp;
    cin>>tmp;
    for(int i=0; i<tmp.length(); i++) {
        a[i]=tmp[tmp.length()-i-1]-'0';
    }
    int maxL = tmp.length();
    cin>>tmp;
    for(int i=0; i<tmp.length(); i++) {
        b[i]=tmp[tmp.length()-i-1]-'0';
    }
    maxL = max(maxL,int(tmp.length()));
    for(int i=0; i<maxL+1; i++) {
        if(a[i]+b[i]>9) {
            a[i+1]+=1;
            ans[i] = a[i]+b[i]-10;
        } else
            ans[i] = a[i]+b[i];
    }
    if(ans[maxL]!=0)
        maxL++;
    while(maxL--)
        cout<<ans[maxL];

    cout<<endl;
}
