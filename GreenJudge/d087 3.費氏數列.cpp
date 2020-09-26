/**********************************************************************************/
/*  Problem: d087 "3.費氏數列" from 106年台中區複賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 194KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-09-20 19:15:30                                     */
/**********************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>//my English is poor,please forgive me.
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    string inputNumList;
    string num;
    unsigned long long int fnum[95];
    vector<unsigned long long int> cnum; //checkNum
    fnum[0]=1,fnum[1]=1;
    for(int i=2; i<95; i++) {
        fnum[i]=fnum[i-1]+fnum[i-2];
    }
    //Fibonacci numbers wiil bigger than the range of unsigned long long int at about 95t
    unsigned long long int tmpNum;
    while(!cin.eof()) {
        cin>>tmpNum;
        cnum.push_back(tmpNum);
    }
    //cnum.pop_back();
    //cnum.pop_back();
    cnum.erase(cnum.begin()+(cnum.size()-1),cnum.end());
    //for(auto x:cnum) cout<<x<<" ";
    //cout<<endl;
    int i=0;
    bool allfnum=true;//outputed=false;
    for(i=0; i<95; i++) {
        if (!allfnum)
            break;
        if(fnum[i]==cnum[0]) {
            for(int j=1; j<cnum.size(); j++) {
                if(fnum[i+j]!=cnum[j]) {
                    cout<<cnum[j]<<endl;
                    allfnum=false;
                    break;
                }
            }
            if(allfnum)
                cout<<i+1<<endl;
        }
    }
    unsigned long long int *index=find(fnum,fnum+95,cnum[0]);
    //cout<<index<<endl;
    if(allfnum && index==fnum+95)
        cout<<cnum[0]<<endl;
}