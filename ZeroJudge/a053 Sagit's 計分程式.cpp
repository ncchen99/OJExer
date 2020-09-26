#include <bits/stdc++.h>

using namespace std;

int a; 

int main(int argc, char** argv){

while(cin>>a)

cout<<(a<=10)*(a*6)+(a>=11&&a<=20)*((a-10)*2+60)+(a>=21&&a<40)*((a-20)+80)+(a>=40)*100<<endl;

}
