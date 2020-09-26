#include <bits/stdc++.h>
using namespace std;
int main(){
    int num=0;
    while(cin>>num){
        vector<int> students(num),pass,fail;
        for (int i=0;i<num;i++) {cin>>students.at(i);}
        /*while(cin>>num){
            students.push_back(num);
        }*/
        //students.erase(students.begin());
        sort(students.begin(),students.end());
        for(int i=0;i<students.size();i++){
            if (students[i]>=60) pass.push_back(students[i]);
            else fail.push_back(students[i]);
            if (i==students.size()-1) cout<<students[i]<<endl;
            else cout<<students[i]<<" ";
        }
        if (fail.empty()) cout<<"best case\n";
        else cout<<fail.at(fail.size()-1)<<endl;
        if (pass.empty()) cout<<"worst case\n";
        else cout<<pass[0]<<endl;
    }

}
