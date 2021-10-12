#include<bits/stdc++.h>

using namespace std;
//prints all pf of a number
void factorise(int n){
	int sq = n;
	cout << n << ": ";
	for(int i=2;i*i<=sq;i++){
		if(n%i==0){
			cout << i << "^";
			int pow = 0;
			while(n%i==0){
				pow++;
				n /=i;
			}
			cout << pow << " ";
		}
	}
	if(n!=1){
		cout << n << "^" << 1 << endl;
	}
}

int main(){
		
	int n;cin>> n;
	factorise(n);

}
