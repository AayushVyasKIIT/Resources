#include <bits/stdc++.h>

using namespace std;

int knapsack(int values[],int wt[],int n,int W){

    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(values,wt,n-1,W);
    }
    return max(knapsack(values,wt,n-1,W-wt[n-1])+values[n-1],knapsack(values,wt,n-1,W));    
}

int main(){

    int wt[3] = {10,20,30};
    int values[3] = {100,50,150};

    int W = 50;
    cout << knapsack(values,wt,3,W);





}