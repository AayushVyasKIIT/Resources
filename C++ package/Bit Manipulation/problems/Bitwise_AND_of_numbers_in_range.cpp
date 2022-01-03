#include<bits/stdc++.h>

using namespace std;


int Bitwise_And(int left,int right){ // left and right are the starting and end numbers in the space 0 to n;
	int a = 0;
	while(left!=right){
		left >>= 1;
		right >>= 1;
		a++;
	}
	return left << a;
	 
}


int main(){
	int left,right; cin >> left >> right;
	cout <<	Bitwise_And(left,right) << endl;



}
