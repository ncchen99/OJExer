#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<string> AnnLe;
    string tmp;

    while(getline(cin,tmp)){
            //注意getline用法，他可以一次輸入一行。
            //同樣的也可放在while的判斷中檢查是否有輸入。
        bool found = false;
        for (int i=0;i<AnnLe.size();i++){
            if (tmp == AnnLe[i]){
                found = true;
                cout<<"YES"<<"\n";
                break;
            }
        }
        if (! found)
            cout<<"NO"<<"\n";
        AnnLe.push_back(tmp); //加到vector中
    }
}
