#include <bits/stdc++.h>

using namespace std;

int ceil_of_key(int arr[],int start,int end,int key){
	int ans = -1;
	while(start < end){
		 int mid = start + (end - start) /2 ;
		 if(arr[mid] == key){
			 return key;
		 }
		 else if(arr[mid] > key){
			 ans = mid;
			 end = mid - 1;
		 }else{
			 start = mid + 1;
		 }
	}
	return ans;
}


int main(){
	int arr[4] = {1,3,5,6};
	cout << ceil_of_key(arr,0,5,2)<< endl;
}
