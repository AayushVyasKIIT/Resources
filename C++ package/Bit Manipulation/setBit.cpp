#include <bits/stdc++.h>

using namespace std;

int setBits(int n,int pos){
    return (n | (1<<pos));
}

int main(){
    cout << setBits(5,1);
}