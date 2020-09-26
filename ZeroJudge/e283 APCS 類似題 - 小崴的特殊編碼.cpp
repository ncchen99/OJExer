#include <bits/stdc++.h>
using namespace std;

int main() {
            ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    map<string, char> code;
    string tmp;
    long long n;
    code["0 1 0 1"] = 'A';
    code["0 1 1 1"] = 'B';
    code["0 0 1 0"] = 'C';
    code["1 1 0 1"] = 'D';
    code["1 0 0 0"] = 'E';
    code["1 1 0 0"] = 'F';
    while (cin>>n){
        cin.ignore();
        while(n--){
            getline(cin,tmp);
            cout<<code[tmp];
        }
        cout<<endl;
        }
}
