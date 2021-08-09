#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int b = 101;
    int sum =0;
    int i=0;

    while(b>0){
        int x = b%10;
        sum = sum + x*pow(2,i);
        i++;
        b = b/10;
    }
    cout << "Decimal:" << sum << endl;
}