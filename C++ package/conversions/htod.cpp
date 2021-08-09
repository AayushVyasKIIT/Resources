#include <bits/stdc++.h>

using namespace std;

int main(){

    int d = 100;
    string hex = "";
    int pown = 1;

    while(pown<=d){
        pown*=16;
    }
    pown/=16;

    while(d>0){
        int lastdigit = d/pown;
        d-=lastdigit*pown;
        if(lastdigit>9 && lastdigit<16){
            hex += char(65+ lastdigit-10);
        }else{
            hex += char('0') + lastdigit;
        }
        pown/=16;
    }
    cout << hex;


}