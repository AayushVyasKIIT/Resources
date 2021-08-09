#include <bits/stdc++.h>

using namespace std;

bool isSafe(int** arr, int x,int y,int n){

    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool RatinMaze(int** arr,int x,int y,int n,int** path){

    //base case
    if(x==n-1 && y==n-1){
        path[x][y] =1;
        return true;
    }


    if(isSafe(arr,x,y,n)){
        path[x][y] = 1;

        //recursive call for right
        if(RatinMaze(arr,x+1,y,n,path)){
            return true;
        }
        //recursive call for bottom
        if(RatinMaze(arr,x,y+1,n,path)){
            return true;
        }

        //backtracking
        path[x][y] = 0;
        return false;
        //solution not possible
    }
    return false;
}

int main(){
    int n=5;
    int **maze = new int*[n];
    int m[5][5] = {{1,0,1,0,1},{1,1,1,1,1},{0,1,0,1,0},{1,0,0,1,1},{1,1,1,0,1}};

    for(int i=0;i<n;i++){
        maze[i] = new int[n];
        for(int j=0;j<n;j++){
            maze[i][j] =  m[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << " " << maze[i][j];
        }
        cout << endl;
    }
    int **path = new int*[n];
    for(int i=0;i<n;i++){
        path[i] = new int[n];
        for(int j=0;j<n;j++){
            path[i][j] = 0;
        }
    }
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << " " << path[i][j];
        }
        cout << endl;
    }    
    cout << "\nPath :" << endl;

    RatinMaze(maze,0,0,n,path);
    cout << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << " " << path[i][j];
        }
        cout << endl;
    }    
    cout << "--------------" << endl;
    
}