#include <bits/stdc++.h>

using namespace std;

int longestConsecutive1(vector<int> arr,int k){
    int zerocount = 0;
    int ans = 0;
    int i=0;
    for(int j=0;j<arr.size();j++){
        if(arr[j]==0){
            zerocount++;
        }
        while(zerocount>k){
            if(arr[i]==0){
                zerocount--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
    return ans;

}

int main(){
    vector<int> arr = {1,1,0,0,1};
    cout << longestConsecutive1(arr,2);
}