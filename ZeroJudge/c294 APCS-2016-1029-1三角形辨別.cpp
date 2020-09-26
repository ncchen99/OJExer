#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int a=0,b=0,c=0;\
  cin >>a>>b>>c;
  int list[]={a,b,c};
  sort(list,list+3);
  for (int i=0;i<3;i++){
    if (i==2){
      cout<<list[i]<<endl;
    }else{
      cout<<list[i]<<" ";
    }
  }
  a=list[0], b=list[1],c=list[2];
  if (a + b <= c){
    cout<<"No";
  }
  else if(a * a + b * b < c * c) {
    cout<<"Obtuse";
  }
  else if (a * a + b * b == c * c){
    cout<<"Right";
  }
  else if (a * a + b * b > c * c){
    cout<<"Acute";
  }
}
