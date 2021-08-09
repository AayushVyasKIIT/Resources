#include <bits/stdc++.h>

using namespace std;

int TillingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return TillingWays(n-1) + TillingWays(n-2);
}

int main(){




}