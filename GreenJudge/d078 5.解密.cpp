/**********************************************************************************/
/*  Problem: d078 "5.解密" from 105年台中區複賽                                           */
/*  Language: C++                                                                 */
/*  Result: AC (168ms, 207KB) on ZeroJudge                                        */
/*  Author: whsh710436 at 2019-10-19 18:10:07                                     */
/**********************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int va=0;//vocabularyAmount
        string ds;//decodingString
        cin>>ds>>va;
        vector<string> oe(va);//OriginElement
        vector<int> elements(va);
        vector<int> finalOrder;
        for(int j=0; j<va; j++) {
            cin>>oe[j];
            elements[j]=j;
        }
        int pairTimes=0;
        do {
//            for(auto item:elements)
//                cout<<item<<" ";
//            cout<<endl;
            int index=0;
            string tmpResultString;
            for(int j=0; j<va; j++) {
                string tmp=oe[elements[j]];
                sort(tmp.begin(),tmp.end());
                do {
                    if(ds.substr(index,tmp.length())==tmp) {
                        index+=tmp.length();
                        if(index-1==ds.length()) break;
                        tmpResultString+=tmp;
                        break;
                    }
                    //cout<<ds.substr(index,tmp.length())<<" "<<tmp<<" ";
                } while(next_permutation(tmp.begin(),tmp.end())); //對STRING做枚舉
            }
            //cout<<tmpResultString<<endl;
            if(tmpResultString==ds) {
                pairTimes+=1;
                finalOrder=elements;
            }
        } while(next_permutation(elements.begin(),elements.end())); //對VECTOR<int>做枚舉
        if(pairTimes==0)
            cout<<-1<<endl;
        else if(pairTimes>1)
            cout<<1<<endl;
        else {
            for(int k=0; k<va; k++)
                cout<<oe[finalOrder[k]]<<" ";
            cout<<endl;
        }
    }
}

// 2D vector initial => vector<vector<int>>v(10,vector<int>(11,100));
