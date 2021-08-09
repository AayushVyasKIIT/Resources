#include <bits/stdc++.h>

using namespace std;

void primeFactorization(int n){

    int spf[n+1];
    for(int i=0;i<n+1;i++){
        spf[i] = i;
    }
    for(int i=2;i<n/2;i++){
        if(spf[i]==i){
            for(int j=i*i;j<n+1;j+=i){
                if(spf[j]==j){ //checking 2nd time because it is possible we could have marked it earlier.
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1){
        cout<< " " << spf[n] ;
        n/=spf[n];
    }
}

int main(){
    primeFactorization(20);
    

}