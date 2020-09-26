/**********************************************************************************/
/*  Problem: b026 "股海浮沈" from 動態規劃-最大連續元素和                                        */
/*  Language: C++                                                                 */
/*  Result: AC (3ms, 192KB) on ZeroJudge                                          */
/*  Author: whsh710436 at 2019-12-19 12:57:05                                     */
/**********************************************************************************/

#include <algorithm>
#include<iostream>
using namespace std;

class KadanesOne
{
    public:
        static int GetMax(int* array, int length);
        static int Detect(int* array, int length);
    protected:
    private:
};
// O(n), Kadane's 演算法(dynamic porgramming), 至少取一個版本
int KadanesOne::GetMax(int* array, int length)
{
    int sum = KadanesOne::Detect(array, length);
    if (sum < 0)
        return sum;
    int max_sum = array[0];
    for (int i = 0; i < length; ++i)
    {
        sum += array[i];
        sum = max(0, sum);
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

// 測試是否全為負數，是的話回傳最大的負數，否則回傳0
int KadanesOne::Detect(int* array, int length)
{
    int max_sum = array[0];
    for (int i = 0; i < length; ++i)
    {
        if (array[i] >= 0)
            return 0;
        max_sum = max(array[i], max_sum);
    }
    return max_sum;
}

int main(){
    int n;
    cin>>n;
    int *martix=new int[n];
    for(int i=0;i<n;i++){
        cin>>martix[i];
    }
    int ans=KadanesOne::GetMax(martix,n);
    cout<<(ans>0?ans:0)<<endl;
}
