#include<bits/stdc++.h>

using namespace std;

int sum(int a,int b){
	if(b==0) return a;
	cout << (a^b) << " " << (a&b) << " " << (a&b)<<1 << " " << endl;
	return a = sum(a^b, (a&b)<<1);
}

int main(){
	cout << sum(5,4) << endl;
	

}
