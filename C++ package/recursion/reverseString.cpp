#include <bits/stdc++.h>

using namespace std;

void reverseString(string str,int n){
    if(n==0){
        return;
    }
    reverseString(str.substr(1),n-1);
    cout << str[0];
}
int main(){
    reverseString("hello",5);

}