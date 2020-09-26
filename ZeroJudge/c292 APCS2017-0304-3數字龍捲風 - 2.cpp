#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d; //direction
    double step=1;
    cin>>n>>d;
    vector<int> table(n*n);
    int x=n/2,y=n/2;
    for(int i=0; i<n*n; i++) {
        cin>>table[i];
    }
    cout<<table[y*n+x];
    while(n+1 != step) {
        if (n == step) {
            for(int j=0; j<n-1; j++) {
                if (d == 0)
                    x -=1;
                else if (d == 1)
                    y -=1;
                else if (d == 2)
                    x +=1;
                else if (d == 3)
                    y +=1;
                cout<<table[y*n+x];
            }
            step+=1;
        } else {
            for(int j=0; j<int(step); j++) {
                if (d == 0)
                    x -=1;
                else if (d == 1)
                    y -=1;
                else if (d == 2)
                    x +=1;
                else if (d == 3)
                    y +=1;
                cout<<table[y*n+x];
            }
            if (d == 3) {
                d=0;
            } else {
                d+=1;
            }
            step+=0.5;
        }
    }
}
