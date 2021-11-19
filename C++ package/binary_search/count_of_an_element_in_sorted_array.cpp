#include <bits/stdc++.h>

using namespace std;



int first(int arr[],int start,int end,int key){
	int static res = -1;
	if(start < end){
		int mid = start + (end - start)/2;
		if(arr[mid] == key){
			res = mid;
			if(arr[mid-1] == key){
				res = mid - 1;
				return first(arr,start,mid-1,key);
			}else{
				return res;
			}
		}else if(arr[mid] > key){
			return first(arr,start,mid-1,key);
		}else{
			return first(arr,mid+1,end,key);
		}
	}
	return res;
}
int last(int arr[],int start ,int end,int key){
	int static res = -1;
	if(start < end){
		int mid = start + (end - start)/2;
		if(arr[mid] == key){
			res = mid;
			if(arr[mid+1] == key){
				res = mid +1;
				return last(arr,mid + 1,end,key);
			}else{
				return res;
			}
		}else if(arr[mid] > key){
			return last(arr,start,mid-1,key);
		}else{
			return last(arr,mid + 1,end,key);
		}
	
	}
	return res;
}
int count(int arr[],int start,int end,int key){

	//first occurence - last occurence + 1 // this whole window will give all occurences of an element in the array.
	return last(arr,start,end,key) - first(arr,start,end,key) + 1;
}


int main(){
	int arr[5] = {1,1,2,3,4};
	cout <<	count(arr,0,5,2) << endl;

}
