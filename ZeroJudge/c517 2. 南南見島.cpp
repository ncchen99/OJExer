#include<bits/stdc++.h>
using namespace std;
struct position{;
    long long int x,y;
};
int main(){
    struct position bird,start,endp,movep;
    cin>>bird.x>>bird.y;
    cin>>start.x>>start.y>>endp.x>>endp.y;
    if(start.x<=bird.x && bird.x<=endp.x){ //在X的區段
        movep.x=0;
        movep.y=min(abs(start.y-bird.y),abs(endp.y-bird.y));
    }else if (start.y<=bird.y && bird.y<=endp.y) { //在Y的區段
        movep.y=0;
        movep.x=min(abs(start.x-bird.x),abs(endp.x-bird.x));
    }else{ //都不是
        movep.x=min(abs(start.x-bird.x),abs(endp.x-bird.x));
        movep.y=min(abs(start.y-bird.y),abs(endp.y-bird.y));
    }
    cout<<movep.x+movep.y<<endl;
}
