#include <bits/stdc++.h>

using namespace std;

int floor_of_key(int arr[],int start,int end,int key){
	if(start < end){
		int mid  = start + (end - start)/2;
	
		if(arr[mid] == key){
			return mid;
		}else if(arr[mid] > key && arr[mid-1] <= key && mid > 0){ // condition for an element to be floor.
			return mid-1;
		}else if(key < arr[mid]){ // reducing the ss
			return floor_of_key(arr,start,mid - 1,key);
		}else{
			return floor_of_key(arr,mid+1,end,key);
		}
	}
	return -1;
}


int main(){
	int arr[5] = {1,3,5,6};
	cout << floor_of_key(arr,0,5,2) << endl;
	

}
