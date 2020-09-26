#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;
int p[MAX];//p[i]=j，表示i的雙親為j
int d[MAX];//紀錄節點深度
int num[MAX];//紀錄節點的子節點個數，子節點計算過後就減1
deque<int> t;//儲存葉節點
int main()
{
  int n,k,c;
  long long int sum;//1+2+3+...+100000，會超出int範圍
  while (scanf("%d",&n) != EOF) {
    sum = 0;
    memset(d,-1,sizeof(d));
    memset(p,0,sizeof(p));
    memset(num,0,sizeof(num));
    for (int i = 1; i<=n; i++) {
      scanf("%d",&k);
      if (k == 0){
        t.push_back(i);//葉節點
        d[i]=0;//葉節點深度為0
      }else{
        num[i]=k;
        for(int j=0;j<k;j++){
          scanf("%d",&c);
          p[c] = i;//使用陣列p紀錄c的parent為i
        }
      }
    }
    int node;
    while(!t.empty()){
      node = t.front();//取出葉節點
      t.pop_front();
      d[p[node]]=max(d[p[node]],d[node]+1);//取自己的深度與從子節點加1的較大值
      num[p[node]]--;//從t中取出後，該節點的雙親節點個數減1
      if (num[p[node]] == 0){//當所有子節點都走訪過時
        t.push_back(p[node]);//加入該節點到佇列
      }
    }
    for (int i = 1; i<=n; i++) {
      sum += d[i];
    }
    cout << node << endl;//最後一個從t取出的就是root
    cout << sum << endl;
  }
}
