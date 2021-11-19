#include <bits/stdc++.h>

using namespace std;

int first(int arr[],int start,int end,int key){
	int res =-1;
	while(start < end){
		int mid  = start  + (end - start)/2;
		if(arr[mid] == key){
			res = mid;
			if(arr[mid-1] == key){
				res = mid - 1;
				end  = mid - 1;
			}else{
				return res;
			}
		}else if(arr[mid] > key){
			end = mid - 1;
		}else{
			start = start + 1;
		}
	}
	return res;
}
int last(int arr[],int start,int end, int key){
	int  static res = -1;
	if(start < end){
		int mid = start + (end - start)/2;
		if(arr[mid] == key){
			res = mid;
			if(arr[mid+1] == key){
				res = mid + 1;
				res = last(arr,mid+1,end,key);
			}else{
				return res;
			}
		}else if(arr[mid] > key){
			res = last(arr,start,mid -1,key);
		}else{
			res = last(arr,mid+1,end,key);
		}
	}
	return res;
}



int main(){
	int n = 8;
	int arr[n] = {1,1,2,4,5,6,4,4};
	sort(arr,arr+n);
	
	int key = 4;
	for(auto each : arr){
		cout << each <<  " ";
	}
	cout << "I occurence: " << first(arr,0,n,key) << endl;
	cout <<"Last occurence: " << last(arr,0,n,5) << endl;
}
