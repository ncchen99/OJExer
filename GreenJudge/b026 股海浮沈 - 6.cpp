/**********************************************************************************/
/*  Problem: b026 "股海浮沈" from 動態規劃-最大連續元素和                                        */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 192KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-19 12:40:00                                     */
/**********************************************************************************/

#include <iostream>

using namespace std;

int main(){
    int n,Max=0,answer=0;
    cin>>n;
    int*A=new int [n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            Max+=A[j];
            if(Max<0){
                break;
            }
            else if(Max>answer){
                answer=Max;
            }
        }
        Max=0;
    }
    cout<<answer<<endl;
    delete A;
    return 0;
}
