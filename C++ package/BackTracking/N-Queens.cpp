#include <bits/stdc++.h>

using namespace std;

bool constraintChecker(int** chessboard, int x,int y,int n){
    for(int row=0;row<n;row++){
        if(chessboard[row][y]==1){
            return false;
        }
    }

    int row =x;
    int col =y;
    
    //upper left so row and col both decreases.
    while(row>=0 && col >= 0){
        
        if(chessboard[row][col]==1){
            return false;
        }

        row--;
        col--;
        

    }
    row=0;
    col=0;
    //upper right so row will decrease and col will increase.
    while(row>=0 && col<n){
        if(chessboard[row][col]==1){
            return false;
        }
        row--;
        col++;
    } 
    
    return true;
}

bool NQueens(int** chessboard, int x,int n){
    if(x>=n){ //this means we have placed our n queens
        return true;
    }
    for(int col=0;col <n;col++){
        if(constraintChecker(chessboard,x,col,n)){
            chessboard[x][col] = 1;
            if(NQueens(chessboard,x+1,n)){ //agr queens place hogai toa true return hoga
                return true;
            }
            //nhi toa back tracking 
            chessboard[x][col] =0; //backtracking
        }       
    }
    return false;
}

int main(){

    int n = 4 ; //input the number of queens and the size of the chess board;
    int **chessboard = new int*[n];
    for(int i=0;i<n;i++){
        chessboard[i] = new int[n];
        for(int j=0;j<n;j++){
            chessboard[i][j] =0;
        }
    }
    if(NQueens(chessboard,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << chessboard[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "No" ;
    }
    
}