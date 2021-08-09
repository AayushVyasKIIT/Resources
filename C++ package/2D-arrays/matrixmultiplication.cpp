#include <bits/stdc++.h>
#include "std2d.cpp"
using namespace std;

int* matrixMultiplication(int *arr1,int m1,int n1, int *arr2,int m2,int n2){
    int *arr = new int[m1*n2];
    for(int i=0;i<m1;i++){//i for resultant matrix
        for(int j=0;j<n2;j++){//j for resultant matrix
            *(arr+i*n2+j) =0;
            for(int k=0;k<n1;k++){
                *(arr+i*n2+j) += *(arr1+i*m1+k) + *(arr2+k*n2+j);
                cout << *(arr1+i*m1+k) <<"+"<<*(arr2+k*n2+j) <<" ";
            }
            cout << "| " ;
        }
        cout << endl;
    }
    cout << endl;
    return arr;
}



int main(){

    int m1=3,n1=4;
    int m2=4,n2=3; 
    int *arr1 = array2d(m1,n1);
    int *arr2 = array2d(m2,n2);

    print2d(arr1,m1,n1);
    print2d(arr2,m2,n2);

        
    int *arr = matrixMultiplication(arr1,m1,n1,arr2,m2,n2);
    print2d(arr,m1,n2);

}