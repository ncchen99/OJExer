#include<bits/stdc++.h>
using namespace std;
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    int T=0; scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;scanf("%d",&N);
        vector<int> x(N),y(N);
        for(int j=0;j<N;j++){
            scanf("%d %d",&x[j],&y[j]);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        //int mx= N%2==0 ? x[N/2]+x[N/2-1] : x[N/2],my= N%2==0 ? y[N/2]+y[N/2-1] : y[N/2];
        int mx=x[N/2],my=y[N/2];
        long int sumDistance=0;
        for(auto ix:x) sumDistance+=abs(ix-mx);//ix=itemX
        for(auto iy:y) sumDistance+=abs(iy-my);//iy=itemY
        cout<<sumDistance<<endl;
     }
}
