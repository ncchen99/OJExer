/**********************************************************************************/
/*  Problem: b035 "超級保姆" from 貪婪演算法-最小總耗費時間                                       */
/*  Language: C++                                                                 */
/*  Result: AC (5ms, 200KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-16 12:42:45                                     */
/**********************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    long long int answer=0;
    cin>>N;
    int *T=new int[N];
    for(int i=0;i<N;i++){
        cin>>T[i];
    }
    sort(T,T+N);
    for(int i=0;i<N;i++){
        answer+=T[i]*(N-i-1);
    }
    cout<<answer*100<<endl;
    delete T;
    return 0;
}
