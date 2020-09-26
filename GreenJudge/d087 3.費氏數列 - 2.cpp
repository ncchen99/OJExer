/**********************************************************************************/
/*  Problem: d087 "3.費氏數列" from 106年台中區複賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (4ms, 210KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-09-20 19:12:32                                     */
/**********************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
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
    getline(cin,inputNumList);
    istringstream numlist(inputNumList); //In order to use the Function below!
    int i=0;
    unsigned long long int tmpNum;//Fibonacci numbers wiil bigger than the range of unsigned long long int at about 95t
    while(getline(numlist,num,' ')) { //string split & str to int
        istringstream conventer(num);
        conventer>>tmpNum;
        cnum.push_back(tmpNum);
        i++;
    }
    i=0;
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