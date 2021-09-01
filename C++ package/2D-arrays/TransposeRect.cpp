#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int m=2,n=3;
	int *arr = new int[m*n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			*(arr + i*n + j) = j;
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout << *(arr + i*n + j) << " ";
		}
		cout << endl;
	}	
	int m1=3,n1=2;
	int *arrT = new int[n1*m1];
	for(int i=0;i<m1;i++){
		for(int j=0;j<n1;j++){
			if(i==j and j==i){
				*(arrT+ i*n +j)  = *(arr+j*n +i);
			}
		}
	}	
	for(int i=0;i<m1;i++){
		for(int j=0;j<n1;j++){
			cout << *(arrT + i*n + j) << " ";
		}
		cout << endl;
	}
	
}
