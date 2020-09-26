#include<bits/stdc++.h>
using namespace std;
struct item {
    int index;
    int h;
    int w;
};

int main() {
    int n;
    while(cin>>n) {
        vector<item> s(n);
        for(int i=0; i<n; i++) {
            cin>>s.at(i).h;
            cin>>s.at(i).w;
            s.at(i).index=i;
        }
        sort(s.begin(),s.end(),[](item a,item b) {
            if(a.h==b.h &&a.w==b.w)
                return a.index<b.index;
            else if(a.h==b.h)
                return a.w<b.w;
            else
                return a.h<b.h;
        });

        int sum=0;
        for(int i=0; i<n; i++) {
            //cout<<s[i].index<<" "<<s[i].h<<" "<<s[i].w<<endl;
            sum+=abs(s[i].index-i);
        }
        cout<<sum<<endl;
    }
}
