#include<bits/stdc++.h>

using namespace std;


int first_occur(int arr[],int i,int key,int n){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return first_occur(arr,i+1,key,n);
}

int last_occurence(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
	int restArray = last_occurence(arr,n,i+1,key);	
	if(restArray!=-1){
		return restArray; 
		
	} 
	if(arr[i]==key){
		return i; 
		
	}
	return -1;
}
int main(){
    int arr[8] = {1,2,3,4,5,6,2,7};
    cout << first_occur(arr,0,2,8);
    cout << last_occurence(arr,8,0,1);

}