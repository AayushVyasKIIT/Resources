#include <iostream>
#include <cmath>
using namespace std;
bool pythogorian_triplet(int x,int y,int z){
    return pow(x,2) >= pow(y,2) + pow(z,2); 
}

int main(){

    cout << pythogorian_triplet(1,1,3) << endl;
}