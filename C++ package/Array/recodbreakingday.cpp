#include <bits/stdc++.h>

using namespace std;

int main(){


    int arr[] = {0,2,0,7,2,0,2,9};
    int i=0;
    int mx = arr[0];
    int day = 0;
    while(i<8){
        if(arr[i]>mx && arr[i]>arr[i+1]){
            mx = arr[i];
            day = i;

        }
        i++;    
    }
    cout << mx << "<-Record\n"; 
    cout <<day+1<<"th day" << endl;
}