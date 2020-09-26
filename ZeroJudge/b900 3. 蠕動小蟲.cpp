#include <bits/stdc++.h>
using namespace std;
int main() {
    string situation;
    int w,h; //width , height
    cin>>w>>h;
    vector<int> wormsCrawlingPath(w);
    for(int i=0; i<w; i++)
        wormsCrawlingPath[i]=i+1; //初始化寵寵路徑
    for(int i=0; i<h; i++) {
        cin>>situation;
        situation.insert(0,".");
        situation.insert(2*w,".");
        for(int &j : wormsCrawlingPath) {
            if(situation[j*2]=='-') {
                j++;
            }else if(situation[j*2-2]=='-'){
                j--;
            }
        }
    }
    for(int i : wormsCrawlingPath) cout<<i<<" ";
    cout<<endl;
}
