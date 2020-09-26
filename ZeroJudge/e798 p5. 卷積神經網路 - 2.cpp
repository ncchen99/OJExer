#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;

    cin>>n;
    vector<vector<int> > pool(n);
    vector<int> tmp(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>tmp[j];
        }
        pool[i]=tmp;
    }
    // i,j=y,x
    // 0,0 0,1 0,2 0,3
    // 1,0 1,1 1,2 1,3
    // 2,0 2,1 2,2 2,3
    // 3,0 3,1 3,2 3,3
    // 以4 x 4的舉例 我們只需要找出以下括號的這幾格在跟右方、下方、右下方的這幾格比較即可。
    // (0,0) 0,1 (0,2) 0,3
    //  1,0  1,1  1,2  1,3
    // (2,0) 2,1 (2,2) 2,3
    //  3,0  3,1  3,2  3,3

    for(int i=0; i<n; i+=2) {
        for(int j=0; j<n; j+=2) {

            int maxV=INT_MIN; //INT_MIN = -2147483648 int 的最小值 -2的31次方，maxV=MaxValue最大值

            if (pool[i][j] > maxV) //自己
                maxV=pool[i][j];
            if (pool[i][j+1] > maxV) //右邊那隻
                maxV=pool[i][j+1];
            if (pool[i+1][j] > maxV) //下面那隻
                maxV=pool[i+1][j];
            if (pool[i+1][j+1] > maxV) //右下方那隻
                maxV=pool[i+1][j+1];

            cout<<maxV<<(j+2==n ? "\n" : " ");
        }
    }
}
