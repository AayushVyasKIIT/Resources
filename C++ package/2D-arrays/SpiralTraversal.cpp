#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[3][3]  = {{1,2,3},{4,5,6},{7,8,9}};
    int m =3, n=3;
    int top =0, bottom = m-1; 
    int left = 0;
    int right =n-1; 
    int direction = 0;
    while(top<=bottom && left<=right){
        if(direction == 0){
            for(int i=left;i<=right;i++){
                cout << arr[top][i];
            }
            top++;
        }else if(direction == 1){
            for(int i=top;i<=bottom;i++){
                cout << arr[i][right];
            }
            right--;
        }else if(direction == 2){
            for(int i=right; i>=left;i--){
                cout << arr[bottom][i];
            }
            bottom--;
        }else if(direction==3){
            for(int i=bottom;i>=top;i--){
                cout << arr[i][left];
            }
            left++;
        }
        direction = (direction+1)%4;
    }
}