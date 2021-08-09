#include <bits/stdc++.h>

using namespace std;
int getbit(int n,int pos){
    return ((n&(1<<pos))!=0);
}

int unique_in_triplet(int arr[],int n){
    int countArray[64];
    for(int i=0;i<64;i++){
        countArray[i] = 0;
    } 
    for(int i=0;i<n;i++){
        int num = arr[i];
        int pos = 0;
        int n = num;
        while(num!=0){
            if(getbit(n,pos)==1){
                countArray[pos] +=1;
            }
            pos++;
            num = num>>1;
        }
    }
    int dec = 0;
    for(int i=0;i<64;i++){
        if(countArray[i]%3==1){
            dec += pow(2,i);
        }
    }
    
    return dec;
}

int main(){
    int arr[10] = {1,3,2,3,5,2,1,1,3,2};
    cout << unique_in_triplet(arr,10);

}