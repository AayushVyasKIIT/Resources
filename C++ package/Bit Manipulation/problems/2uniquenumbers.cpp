#include <bits/stdc++.h>

using namespace std;

int getBit(int n,int pos){
    return ((n&(1<<pos))!=0);
}

void Unique_elements(int arr[],int n){

    int xorsum =0;

    for(int i=0;i<n;i++){
        xorsum = (xorsum^arr[i]);
    }
    int sumof2uniqueElements = xorsum;
    int setbit = 0;
    int pos = 0; //position where 1(setbit) is found
    while(setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int setbitXorSum = 0;
    for(int i=0;i<n;i++){
        if(getBit(arr[i],pos-1)){
            setbitXorSum = setbitXorSum^arr[i];
        }
    }
    cout << "1st unique element is:" << setbitXorSum << endl;
    cout << "2nd unique element is:" << (sumof2uniqueElements^setbitXorSum) << endl;


}

int main(){
    int arr[8] = {1,2,3,1,2,3,5,7}; //each element is present twice ,Except one!
    Unique_elements(arr,8);
}