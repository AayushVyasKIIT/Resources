#include <bits/stdc++.h>

using namespace std;


int solve(int arr[],int start,int end,int key){
	if(start<end){
		int mid = start  + (end - start)/2;
		if(arr[mid] == key){
			return mid;
		}
		if(arr[mid] > key){
			return	solve(arr,start,mid-1,key);
		}else{
			return solve(arr,mid+1,end,key);
		}

	}
	return -1;
}

int main(){
	int n = 5;
	int arr[n] = {1,3,4,2,5};
	sort(arr,arr+n);
	for(int i =0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout <<	solve(arr,0,n,5)<< endl;

}
