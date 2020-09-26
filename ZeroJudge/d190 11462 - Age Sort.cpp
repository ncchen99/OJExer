#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int num=0;
  int *list=new int[5];
  while (cin >>num){
  delete [] list;
  list = new int[num];
  if (num!=0){
    for (int i=0;i<num;i++){
      cin>>list[i];
    }
    sort(list,list+num);
    for (int i=0;i<num;i++){
      if (i==num-1){
        cout<<list[i]<<endl;
      }else{
        cout<<list[i]<<" ";
      }
    }
  }
  }
}
