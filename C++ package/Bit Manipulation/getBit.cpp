#include <bits/stdc++.h>

using namespace std;

int getBit(int n,int pos){
    return (n& (1<<pos)!=0);
}

int main(){

    int n=5,pos =2;
    cout << getBit(n,pos);

}