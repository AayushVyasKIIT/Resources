#include <bits/stdc++.h>

using namespace std;

int noOf1(int n){
    int count1 = 0;
    while(n!=0){
        count1 ++;
        n = n&n-1;

    }
    return count1;
}

int main(){

    cout << noOf1(31);


}