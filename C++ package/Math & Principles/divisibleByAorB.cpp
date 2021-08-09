#include <bits/stdc++.h>

using namespace std;


int divisible(int number,int a,int b){
    int c1 = number/a;
    int c2 = number/b;
    int c3 = number/(a*b);

    return c1+c2-c3;

}

int main(){

    cout << divisible(40,5,7);


}