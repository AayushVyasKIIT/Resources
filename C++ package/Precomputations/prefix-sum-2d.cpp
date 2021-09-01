#include <bits/stdc++.h>
using namespace std;

#define vii vector<vector<int>> 

int pf[4][4];

int main(){
    int n = 4           ;
    //2D array
    int arr[n][n] = {{1,2,3},{1,2,3},{1,2,3}};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    //find the array of any rectangle given array range
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pf[i][j] = arr[i][j] + pf[i-0][j] + pf[i][j-0] - pf[i-0][j-0]; 
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << pf[i][j] << " ";
        }
        cout << endl;
    }
}