#include<bits/stdc++.h>

using namespace std;

int updateBit(int n,int pos,int value){
    int mask = ~(1<<pos)
    n = (n&mask);
    return (n|(value<<pos));

}


int main(){

}