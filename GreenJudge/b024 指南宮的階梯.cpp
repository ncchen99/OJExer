/**********************************************************************************/
/*  Problem: b024 "指南宮的階梯" from 動態規劃-爬樓梯問題                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 184KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2020-01-13 12:45:47                                     */
/**********************************************************************************/

#include <iostream>
using namespace std;
long long dp[91]={0};
long long crawl(int n){
  if(dp[n]!=0)  
    return dp[n];
  else
    dp[n] = crawl(n-1)+crawl(n-2);
    return dp[n];
}
int main() {
  int N;
  cin>>N;
  dp[1]=1;
  dp[2]=2;
  cout<<crawl(N)<<" "<<crawl(crawl(N)%N)<<endl;
}