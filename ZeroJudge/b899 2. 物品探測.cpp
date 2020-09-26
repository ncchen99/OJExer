#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct position {
    int x;
    int y;
}p[3];
int dis(int a,int b){
    return abs(p[a].x-p[b].x)+abs(p[a].y-p[b].y);
}
void position(int a,int b,int c){ //a,b 對角線的兩點 c 另一點
                                        //直角座標系的中點公式
    cout<<p[a].x+p[b].x-p[c].x <<" "<<p[a].y+p[b].y-p[c].y<<endl;
}
int main(){
    for(int i=1;i<4;i++){
      cin>>p[i].x>>p[i].y;
    }
    if(dis(1,2)>dis(2,3) && dis(1,2)>dis(1,3)) position(1,2,3);
    else if(dis(1,3)>dis(2,3) && dis(1,3)>dis(1,2)) position(1,3,2);
    else position(2,3,1);
}
