/**********************************************************************************/
/*  Problem: b034 "悠閒的超商店員" from 貪婪演算法-零錢問題                                       */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 188KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-13 12:47:40                                     */
/**********************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int m,amount=0;
    cin>>m;
    amount += m/10000;
    m %= 10000;
    amount += m/5000;
    m %= 5000;
    amount += m/1000;
    m %= 1000;
    amount += m/500;
    m %= 500;
    amount += m/100;
    m %= 100;
    amount += m/50;
    m %= 50;
    amount += m/10;
    m %= 10;
    amount += m/5;
    m %= 5;
    amount += m/1;
    cout<<amount<<endl;
}

