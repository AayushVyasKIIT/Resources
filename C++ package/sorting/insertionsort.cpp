#include <bits/stdc++.h>

using namespace std;

int* insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current = arr[i];
        int j=i-1;
        while(current<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    return arr;
}

int main(){
    int a[] = {5,3,2,4,1};
    int *r = insertionSort(a,5);
    for(int i=0;i<5;i++){
        cout << a[i];
    }

}