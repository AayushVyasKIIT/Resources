#include <bits/stdc++.h>

using namespace std;

int times_rotated(int arr[],int start,int end){
	//index of minimum element in the array tells the number of positions it is rotated.
	//it has a special property where arr[min - 1] > arr[min] < arr[min+1]
	int static min_idx = 0;
	if(start < end){
		int mid  = start + (end - start)/2;
		//ciruclar features, protect from going out of bounds.
		int next = (mid + 1)%end;
		int prev = (mid + end -1)%end;

		if(arr[mid] < arr[next] and arr[prev] > arr[mid]){
			return mid;
		}else if(arr[mid] <= arr[start]){
			return times_rotated(arr,start,mid-1); 
		}else{
			return times_rotated(arr,mid+1,end);
		}
	}
	return -1;
}

int main(){
	int arr[8] = {11,12,15,18,2,5,6,8};
	cout << times_rotated(arr,0,8) << endl;
}
