#include <bits/stdc++.h>

using namespace std;

int main(){

    int n =50;
    int spf[n+1];
    for(int i=0;i<=50;i++){
        spf[i]=i;
    }

    for(int i=2;i<=n/2;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j] = i;
                }
            }
        }
    }
    while(n!=1){
        cout << spf[n] << " ";
        n/=spf[n];
    }


}