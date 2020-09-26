/**********************************************************************************/
/*  Problem: d075 "2.同字母字串列最寬排版" from 105年台中區複賽                                   */
/*  Language: C++                                                                 */
/*  Result: AC (8ms, 235KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-10-05 00:12:06                                     */
/**********************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
struct item {
    vector<int> indexs,slen;//slen=spacelen
    int len,indexnum;
};
bool cmp(item f,item s) {
    if(f.len==s.len)
        return f.indexnum<s.indexnum;
    else
        return f.len<s.len;
}
int main() {
    int n=0;
    cin>>n;
    vector<string> line(n+1);
    int factorial=1;
    for(int i=1; i<=n; i++)
        factorial*=i;
    //cout<<factorial<<endl;
    item *allP=new item [factorial];
    //vector<vector<int>> indexList;
    vector<int> tmp,pairList;
    for(int i=1; i<=n; i++) {
        cin>>line[i];
        tmp.push_back(i);
    }
    int i=0;
    do {
        allP[i].indexs.assign(tmp.begin(),tmp.end());
        allP[i].indexnum=0;
        allP[i].len=0;
        for(int j=0; j<n; j++)
            allP[i].indexnum+=allP[i].indexs[j]*pow(10,5-j);
        allP[i].indexnum=allP[i].indexnum/10;
        i++;
    } while(next_permutation(tmp.begin(),tmp.end()));
    /*for(int i=0;i<factorial;i++){
        for(int j=0;j<n;j++) cout<<allP[i].indexs[j]<<" ";
        cout<<allP[i].indexnum<<endl;
    }*/
    for(int i=0; i<factorial; i++) {
        vector<string> tmpLine;
        for(int j=0; j<n; j++) {
            tmpLine.push_back(line[allP[i].indexs[j]]);
        }
        for(int j=0; j<n-1; j++) {
            int spaces=0;
            vector<int> spacesList;
            for(int k=0; k<tmpLine[j].length(); k++) {
                for(int x=tmpLine[j+1].length()-1; x>-1; x--) {
                    //cout<<tmpLine[j+1][x]<<" ";
                    if(tmpLine[j][k]==tmpLine[j+1][x]) {
                        spaces=k-x;
                        spacesList.push_back(spaces);
                    }
                }
            }
            if(!spacesList.empty()) {
                sort(spacesList.begin(),spacesList.end());
                reverse(spacesList.begin(),spacesList.end());
                spaces=spacesList[0];
            } else {
                spaces=-10000;
            }
            allP[i].slen.push_back(spaces);
            allP[i].len+=spaces;
            //cout<<endl<<tmpLine[j]<<" "<<tmpLine[j+1]<<" "<<spaces<<endl;
        }
        //cout<<endl;
        allP[i].len+=tmpLine[n-1].length();
        //cout<<allP[i].len<<endl<<endl;
    }
    sort(allP,allP+factorial,cmp);
    /*     for(int i=0;i<factorial;i++) {
     *         cout<<allP[i].len<<" "<<allP[i].indexnum<<endl;
     *     }
     */
    int spaces=0;
    cout<<line[allP[factorial-1].indexs[0]]<<endl;
    for(int i=1; i<n; i++) {
        spaces+=allP[factorial-1].slen[i-1];
        for(int j=0; j<spaces; j++)
            cout<<"_";
        cout<<line[allP[factorial-1].indexs[i]]<<endl;
    }
}
