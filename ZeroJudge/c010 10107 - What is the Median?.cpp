#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> martix;
    int tmp=0,i=0; //暫存，index
    while (cin>>tmp) { //吃到沒有資料為止，因為本題不會先說有幾個數字。
        martix.insert(upper_bound(martix.begin(),martix.end(),tmp),tmp);
        if(i%2 == 1) //總共偶數個數字，想一夏為ㄍ麼是醬子，答:i是重零開始的
            cout<<(martix[i/2] + martix[i/2+1])/2<<'\n';
        else //總共奇數個數字
            cout<<martix[i/2]<<'\n';
        i++;
    }
}
