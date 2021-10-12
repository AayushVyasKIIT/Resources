#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	int k;cin>>k;
	//just the sum	
/*	int i =0,j=0;
	int mx=0,sum=0;
	while(j<n){
		sum += arr[j];
		
		if(j-i+1 <k){
			j++;
		}else if(j-i+1 == k){
			mx = max(sum,mx);
			sum -= arr[i];
			i++;
			j++;
		}
	}
	cout << "max sum of subarray is:" << mx << endl;
*/
	//if we are asked to find out the starting and ending point of it also
	int i=0,j=0,sum=0,mx=0;
	map<int,int> max_sum;
	//max_sum[0] = a[0] + a[1] ...a[j-i+1] 
	while(j<n){
		sum += arr[j];

		if(j-i+1 < k){
			j++;
		}else if(j-i+1 == k){
			mx = max(sum,mx);
			max_sum[i] = sum;
			sum-= arr[i];
			i++;
			j++;
		}

	}
	int start,end,mx_sum = INT_MIN;
	for(int l=0;l<n-k+1;l++){
		if(max_sum[l] > mx_sum){
			mx_sum = max_sum[l];
			start = l;
		}
	}
	end = start + k -1;
	cout <<"["  << start << "," << end << "]: " << mx_sum << endl;
}

