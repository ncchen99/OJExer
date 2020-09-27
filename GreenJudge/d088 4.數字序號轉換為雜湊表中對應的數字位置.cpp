/**********************************************************************************/
/*  Problem: d088 "4.數字序號轉換為雜湊表中對應的數字位置" from 106年台中區複賽                           */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 196KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-08-11 17:55:20                                     */
/**********************************************************************************/

#include<iostream>     
#include<sstream>     
#include<vector> 
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string num;
    vector<int> numlist;
    int tmpnum=0;unsigned long long int sum=0;
    cin>>num;
    for(int i=0; i<num.length()/3*3; i+=3) {
        if(i%2==0) {//不須反轉
            for(int j=0; j<3; j++) {
                tmpnum=(int(num[i+j])-'0')+tmpnum*10;
                //cout<<int(num[i+j])-'0'<<endl;
            }
        } else {
            for(int j=3; j>0; j--) {
                tmpnum=(int(num[i+j-1])-'0')+tmpnum*10;
            }
        }
        //cout<<tmpnum<<endl;
        numlist.push_back(tmpnum);
        tmpnum=0;
    }
    int i=num.length()/3*3;
    if(i%2==0) {//不須反轉
    for(int j=0; j<num.length()%3; j++) {
            tmpnum=(int(num[i+j])-'0')+tmpnum*10;
        }
    } else {
        for(int j=num.length()%3; j>0; j--) {
            tmpnum=(int(num[i+j-1])-'0')+tmpnum*10;
        }
    }
    //cout<<tmpnum<<endl;
    numlist.push_back(tmpnum);
    for (int i=0;i<numlist.size();i++){
        sum+=numlist[i];
    }
    cout<<sum%997<<endl;
}