#include <bits/stdc++.h>
#include "stdneeds.cpp"

using namespace std;

int main(){
    int arr[] = {1,2,3,8};
    int n = 4;
    int S=5;

    int i=0,j=0,st=-1,en=-1,currSum=0;

    while(j<n && currSum<=S){
        currSum += arr[en+1];
        en++;
        j++;
    }
    if(currSum==S){
        cout << st << en << endl;
        return 0;
    }
    while(i<n){
        while(currSum >= S){
            currSum -= arr[st+1];
            st++;
        }
        i++;
    }
    cout << st+1 << en+1;


}