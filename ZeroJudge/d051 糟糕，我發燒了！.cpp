#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    double in0 ;
    
    while (cin >>in0 ){
          cout <<fixed <<setprecision(3) <<(in0-32)*5/9 <<endl ;
    }
}
