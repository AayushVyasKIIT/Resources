#include <bits/stdc++.h>

using namespace std;


int clearBits(int n,int pos){
    int mask = ~(1<<pos);
    cout << mask << endl;
    return (n&mask);

}
int main(){

    cout << clearBits(5,2);

}
