#include <bits/stdc++.h>

using namespace std;
int MatrixSearch(int* arr,int m,int n,int key){
    int r=0;
    int c=n-1;
    //start at arr[r,c]
    while(r<m && c>=0 ){
        cout << *(arr+r*n+c);
        if(*(arr+r*n+c)==key){
            return 1;
        }else if(*(arr+r*n+c)>key){
            c--;
        }else{
            r++;
            
        }
    }
    return 0;
}

int main(){
    int arr[4][4] = {{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    int *a = new int[4*4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            *(a+i*4+j) = arr[i][j];
        }
    }
    int key=5;

    MatrixSearch(a,4,4,key)?cout<<"Found":cout<<"Not Found";
    
}