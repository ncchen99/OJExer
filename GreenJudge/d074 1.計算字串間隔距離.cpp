/**********************************************************************************/
/*  Problem: d074 "1.計算字串間隔距離" from 105年台中區複賽                                     */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 180KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-10-02 22:15:06                                     */
/**********************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int main(){
    string line;
    cin>>line;
    for(int i=0;i<line.length();i++) line[i]=toupper(line[i]); //注意參照用法，和char專用的toupper()
    char c;
    cin>>c;
    c=toupper(c);
    int d=-1;
    //cout<<line<<" "<<c<<endl;
    for(int i=0;i<line.length();i++){
        if(d==-1&&line[i]==c) d=i;
        else if(line[i]==c) {
            cout<<i-d<<" ";
            d=i;
        }
    }
}
