#include <bits/stdc++.h>
using namespace std;

int main() {
    int N=0,I=0,groups=0;
    cin>>N;
    int all[N];
    for(int i=0;i<N;i++){
        cin>>all[i];
    }
    int tag[N]={0};
    for(int i=0;i<N;i++){
        if(tag[i]==0){
            I = i;
            while(tag[I]==0){
                tag[I]=1;
                I=all[I];
            }
            groups+=1;
        }
    }
    cout<<groups<<endl;
}
