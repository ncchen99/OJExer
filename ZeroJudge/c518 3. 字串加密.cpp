//字串加密
#include<iostream>
#include<string>
using namespace std;

main(){
	int n,m;
	char map[128];
	for (int i=0;i<128;i++){
		map[i]=(char)i;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	string msg;
	cin >> msg;
	string before,after;
	cin >> before >> after;
	
	
	for (int i=m-1;i>=0;i--){
		map[before[i]]=map[after[i]];	
	}
	for (int i=0;i<n;i++){
		msg[i]=map[msg[i]];	
	}
	cout << msg << endl;
	return 0;
}
