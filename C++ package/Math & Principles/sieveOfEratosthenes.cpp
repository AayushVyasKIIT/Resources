#include <bits/stdc++.h>

using namespace std;

void sieveOfEratosthenes(int start,int end){
    int arr[end+1];
    for(int i=0;i<end+1;i++){
        arr[i] = 0;
    }
    for(int i=start;i*i <= end+1;i++){
        if(arr[i]==0){
            for(int j=i*2;j<end+1;j++){
                if(j%i==0)
                    arr[j]=1;
            }
        }
        
    }
    for(int i=0;i<end+1;i++){
        if(arr[i]!=0){
            cout << " " << i;
        }
    }

}

int main(){
    sieveOfEratosthenes(2,50);

}