#include<bits/stdc++.h>
using namespace std;
int Input() {  
register char cha;  
register unsigned int x = 0;  
while(cha = getchar())  
if(cha != ' ' && cha != '\n' || cha == EOF) break;  
if(cha == EOF) return -1; 
x = cha-48;  
while(cha = getchar()) {  
if(cha == ' ' || cha == '\n') break;  
x=x*10+cha-48;  
}  
return x;  
}
int main(int argc, char** argv) {
ios::sync_with_stdio(false);
int a[4792],b=1;
a[0]={2};
for(int c=3;b<4791;c++){
int e=0;
for(int d=0;a[d]<=sqrt(c);d++)
if(c%a[d]==0){
e=1;
break;
}
if(e==0){
a[b]=c;
b++;
}
}
int d;
while(1){
d=Input();
if(d==-1)
break;
int f=0;
for(int e=0;e<4792;e++){
if(a[e]==0||d==a[e])
break;
else if(d%a[e]==0||a[e]>d){
f=1;
break;
}
}
if(f)
cout<<"非質數"<<'\n';
else
cout<<"質數"<<'\n'; 
}
}
