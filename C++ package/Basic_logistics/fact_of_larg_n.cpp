#include<bits/stdc++.h>

using namespace std;

int multiply(vector<int>&res,int x,int res_size){
	int carry = 0;

	for(int i=0;i<res_size;i++){
		int prod = res[i]*x + carry;
		res[i] = prod%10;
		carry = prod/10;
	}
	while(carry){
		res[res_size] = carry%10;
		carry = carry/10;
		res_size++;
	}
	return res_size;
}

vector<int> solve(int n){
	vector<int> res;
	res.assign(500,1);
	int res_size = 1;

	for(int i=2;i<=n;i++){
		res_size = multiply(res,i,res_size);
	}
	for(int i=res_size-1;i>=0;i--){
		cout << res[i];
	}

	return res;
}


int main(){

	int n;cin>>n;
	vector<int> ans;
	ans = solve(n);


}
