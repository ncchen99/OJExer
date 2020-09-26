/**********************************************************************************/
/*  Problem: d090 "6.馬步問題" from 106年台中區複賽                                         */
/*  Language: C++                                                                 */
/*  Result: AC (68ms, 216KB) on ZeroJudge                                         */
/*  Author: whsh710436 at 2019-10-24 20:41:34                                     */
/**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Nrow = 3;             //棋盤3列
int Ncol = 0 ;
int **martic=new int *[Nrow]; //記錄棋盤每格是第幾步走過
int countStep = 0;           //目前走第幾步
int solution = 0;        //第N種方法
int step[8][2] = {{2,-1},{1,-2},{-1,-2},{-2,-1}, {-2,1},{-1,2},{1,2},{2,1}};   //8方向
vector< vector<int> > walkPath;    //走過的順序

int cmp(vector<int> v1,vector<int> v2) {
    for(int i=0; i<v1.size(); i++) {
        if(v1[i]!=v2[i]) {
            return v1[i]<v2[i];
        }
    }
}
int isok(int x,int y) {   //判斷這一步是否可以走
    return (x>=0 && x<Nrow && y>=0 && y<Ncol && martic[x][y]==0);
}

void display() { //當整個棋盤都已走過就輸出整個棋盤
    cout << "the "<< ++solution <<" solution:"<<endl;
    for(int i=0 ; i<Nrow ; i++) {
        for(int j=0 ; j<Ncol ; j++) {
            cout << martic[i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl;
}

void DFS(int x,int y) {
    int nextx,nexty;
    for (int i = 0; i < 8; ++i) {
        nextx = x + step[i][0];
        nexty = y + step[i][1];

        if (isok(nextx,nexty)) {
            if(countStep!=Nrow*Ncol-1) {
                countStep++;
                martic[nextx][nexty] = countStep;
                DFS(nextx,nexty);          //遞迴
                martic[nextx][nexty] = 0;  //BackTracking
                countStep--;                   //BackTracking
            } else {
                countStep++;
                martic[nextx][nexty] = countStep;
                ++solution;
                //display();
                //已全部走過，列印輸出
                vector<int> tmp;  //使用一個一維vector 生成二維 vector
                for(int r=0; r<Nrow; r++) {
                    for(int c=0; c<Ncol; c++) {
                        tmp.push_back(martic[r][c]);
                    }
                }
                walkPath.push_back(tmp);
                martic[nextx][nexty] = 0;  //BackTracking
                countStep--;                   //BackTracking
            }
        }
    }
}
int main() {
    cin>>Ncol;
    for(int i=0; i<Nrow; i++) {
        martic[i]=new int [Ncol];
        for(int j=0; j<Ncol; j++)
            martic[i][j]=0;
    }
    countStep = 1;
    martic[0][0]=1;
    DFS(0,0);
    if(solution!=0) {
        sort(walkPath.begin(),walkPath.end(),cmp);
        for(int i=0; i<Nrow*Ncol; i++) {
            cout<<walkPath[0][i]<<" ";
        }
        cout<<"\n";
    } else {
        cout<<0<<"\n";
    }
    return 0;
}
