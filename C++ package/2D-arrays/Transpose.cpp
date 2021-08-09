#include <bits/stdc++.h>
#include "std2d.cpp"

using namespace std;

int* T(int *arr,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=i;j<n;j++){
            swap(*(arr+i*n+j),*(arr+j*n+i));
        }
    }
    return arr;
}
int main(){
    int m =3, n=3;
    
    int *arr =  array2d(m,n);
    print2d(arr,m,n);
    arr = T(arr,m,n);
    cout << "Transpose :" << endl;
     print2d(arr,m,n);

    
}