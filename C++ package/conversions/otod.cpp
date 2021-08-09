#include <bits/stdc++.h>

using namespace std;

int main(){

    int x8 = 137;
    int d = 0;

    int pown = 0;
    while(x8>0){
        int x = x8%10;
        d += pow(8,pown)*x;
        pown++;
        x8 /= 10;
    }
    cout << "Octal Representation:=" << d << endl;

}