#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    int d = 5;
    int pown= 1;
    int b =0;
    while(pown<=d){
        pown*=2;
    }
    pown/=2;
    while(pown>0){
        int lastdigit = d/pown;
        d-=lastdigit*pown;
        pown/=2;
        b =b*10 + lastdigit;
    }
    cout << b;
}