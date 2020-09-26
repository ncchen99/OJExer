/**********************************************************************************/
/*  Problem: b036 "史萊姆王" from 貪婪演算法-最小總花費                                         */
/*  Language: C++                                                                 */
/*  Result: AC (20ms, 188KB) on ZeroJudge                                         */
/*  Author: whsh710436 at 2019-12-18 12:53:54                                     */
/**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int N,tmp,answer=0;
    cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end(),cmp);
    for(int i=0;i<N-1;i++){
        tmp=A[N-1-i]+A[N-2-i];
        A.pop_back();
        A.pop_back();
        A.push_back(tmp);
        sort(A.begin(),A.end(),cmp);
        answer+=tmp;
    }
    cout<<answer<<endl;



    return 0;
}
