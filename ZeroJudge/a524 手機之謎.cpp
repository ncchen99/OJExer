// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort, std::reverse
using namespace std;
int main () {
    int n=0;
    while(cin>>n) {
        int *myints = new int[n];
        for(int i=n; i>=1; i--) {
            myints[i-1]=i;
        }
        sort (myints,myints+n);//不滋味甚麼一定要加這兩行
        reverse (myints,myints+n);
        do {
            for(int j=0; j<n; j++)
                cout<<myints[j];
            cout<<endl;
        } while(prev_permutation(myints,myints+n));
    }
}
