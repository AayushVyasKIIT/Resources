#include <bits/stdc++.h>

using namespace std;


int ls(char x,vector<char> c){
	for(int i = 0 ; i < c.size();i++){
		if(c[i] == x){
			return i;
		}
	}
	return -1;
}
int main(){
	int T; cin >> T;
	while(T--){
		vector<char> v;
		for(int i =0 ; i < 3;i++){
			char x; cin >> x;
			v.push_back(x);
		}
		char x,y; cin >> x >> y;
		//binary search for x and y
		if(ls(x,v) < ls(y,v)){
			cout << x << endl;
		}else{
			cout << y << endl;		
		}
	}
}
