#include <bits/stdc++.h>

using namespace std;
int* array2d(int m,int n,int range = 5){
    int *arr = new int[m*n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            *(arr+i*n+j)= rand()%10;
        }
    }
    return arr;
}

void print2d(int *arr,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout <<" " <<*(arr+i*n+j);
        }
        cout << endl;
    }
    cout << endl;
}