#include <bits/stdc++.h>

using namespace std;

int squareInIsoceles(int b,int i,int count){
    int final_count =0;
    for(int i=0;i<=b;i+=2){
        if(i>b){
            return count;
        }
        if(b-i==2 || b-i==3){
            return count;
        }
        
        final_count+= squareInIsoceles(b,i+2,count+1);
    
    }
    return final_count;
}



int main(){
    cout << squareInIsoceles(10,0,0);

}
