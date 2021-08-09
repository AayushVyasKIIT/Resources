#include <bits/stdc++.h>

using namespace std;

int main(){

    int arr[] = {10,7,4,6,8,11};


    int pd = abs(arr[0]-arr[1]);
    int curr = 2;
    int mx = 2;
    int j=2; //because 0 and 1 are covered in pd
    while(j<7){
        if(abs(arr[j]-arr[j-1])==pd){
            curr +=1;
        }else{
            pd = arr[j] - arr[j-1];
            curr = 2;
        }
        mx = max(mx,curr);
        j++;
    }
    cout << mx;
}