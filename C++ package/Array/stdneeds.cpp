#include <bits/stdc++.h>

using namespace std;

int* array1d(int size,int range=5){
    int *arr = new int[size];
    for(int i=0;i<size;i++){
        arr[i] = rand() %range+1;
    }
    return arr;
}
int* cinarray1d(int size){
    int *arr = new int[size];
    for(int i=0;i<size;i++){
        cin>> arr[i] ;
    }
    return arr;
}

void printArray(int arr[],int size){
    cout << "array is:";
    for(int i=0;i<size;i++){
        cout <<" "<<arr[i];
    }
    cout << endl;
}
