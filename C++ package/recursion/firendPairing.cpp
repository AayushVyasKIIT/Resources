#include <bits/stdc++.h>

using namespace std;

int firendsPaired(int n){

    if(n==0 || n==1 || n==2){
        return n;
    }

    return firendsPaired(n-1) + firendsPaired(n-2)*(n-1);
}

int main(){

    cout << firendsPaired(4);

}