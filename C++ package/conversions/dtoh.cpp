#include <bits/stdc++.h>

using namespace std;

int main(){

    string hex = "1CF";
    int d = 0;
    int pown = hex.size()-1;
    int i=0;
    while(hex[i]!='\0'){
        if(hex[i]>='0' && hex[i]<='9'){
            d += pow(16,pown)*(hex[i]-'0');
        }
        else if(hex[i]>='A' && hex[i]<='F'){
            d += pow(16,pown)*((hex[i]-'A')+10);
        }
        pown--;
        ++i;
    }
    cout << d ;


}