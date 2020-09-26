#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int testtimes=0,products=0;
  cin>>testtimes;
  int pricelist[products];

  for(int i=0;i<testtimes;i++){
    cin>>products;
    int pricelist[products];
    for(int j=0;j<products;j++){
      cin>>pricelist[j];
      //cout<<pricelist[j];
    }
    sort(pricelist,pricelist+products);
    reverse(pricelist,pricelist+products);
    //本程式精隨! sort array! 語法:sort(begin(array), end(array)); 
    /*for(int j=0;j<products;j++){
      cout<<pricelist[j];
    }*/
    int count=0;
    int sum=0;
    if (products<3){
      cout<<0<<endl;
    }else{
    for (int j=0;j<products/3;j++){
      sum+=pricelist[j*3+2];
      //cout<<pricelist[j*3+2];

      /*if (products-(j+1)>(products%3+3)){
        count=(j+1)%3+j/3;
        cout<<count;
      }else{
        count=(j+1)%3+products/3;
        cout<<count;
      }
      if (count==2+j/3 || count==products%3+(products-1)/3){
        sum+=pricelist[count-1];
      }*/
      
    }
    //sum +=pricelist[products-1];
    //cout<<pricelist[products-1];
    cout<<sum<<endl;
    }
  }
  /*for (int i=0;i<sizeof(pricelist)/sizeof(pricelist[0]);i++){
    cout <<pricelist[i];
  }*/
}
