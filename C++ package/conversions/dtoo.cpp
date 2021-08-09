#include <bits/stdc++.h>

using namespace std;

int main(){
    int d= 100;
    int pown = 1;
    int x8=0;

    while(pown<=d){
        pown *= 8;
    }
    pown/=8;
    while(d>0){
        int lastdigit = d/pown;
        d-=lastdigit*pown;
        x8 = 10*x8 + lastdigit;
        pown /= 8;
    }
    cout << x8 ;
}