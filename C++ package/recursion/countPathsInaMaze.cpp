#include<bits/stdc++.h>

using namespace std;

int countPathsMaze(int n,int i,int j){

    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>n || j>n){
        return 0;
    }

    return countPathsMaze(n,i+1,j) + countPathsMaze(n,i,j+1);


}


int main(){

   cout<<  countPathsMaze(3,0,0);

}