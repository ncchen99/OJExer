#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> pool(n*n);
    for(int i=0; i<n*n; i++) {
        cin>>pool[i];
    }
    // i,j=y,x
    // 0  1  2  3
    // 4  5  6  7
    // 8  9 10 11
    //12 13 14 15
    // 以4 x 4的舉例 我們只需要找出以下括號的這幾格在跟右方、下方、右下方的這幾格比較即可。
    // (0)  1  (2)  3
    //  4   5   6   7
    // (8)  9 (10) 11
    // 12  13  14  15

    for(int i=0; i<n; i+=2) {
        for(int j=0; j<n; j+=2) {

            int maxV=INT_MIN; //INT_MIN = -2147483648 int 的最小值 -2的31次方，maxV=MaxValue最大值

            if (pool[i*n + j] > maxV) //自己
                maxV=pool[i*n + j];

            if (pool[i*n + j + 1] > maxV) //右邊那隻
                maxV=pool[i*n + j + 1];

            if (pool[(i+1) * n + j] > maxV) //下面那隻
                maxV=pool[(i+1) * n + j];

            if (pool[(i+1) * n + j +1] > maxV) //右下方那隻
                maxV=pool[(i+1) * n + j +1];

            cout<<maxV<<(j+2==n ? "\n" : " ");
        }
    }
}
