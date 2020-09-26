#include <iostream>
using namespace std;

bool l[10000001]={false};

int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int s,e,n;
cin>>n;
while(n--){
    cin>>s>>e;
    for(int i=s;i<e;i++){
        l[i] = 1;
    }
}
    int ans=0;
    for(int i=0;i<10000001;i++){
        if(l[i])
            ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
