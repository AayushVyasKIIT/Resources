#include <bits/stdc++.h>

using namespace std;
int binaryAdd(int a,int b){
    int prevcarry = 0;
    int ans =0;
    while(a>0 && b>0){
        cout << "debug:" ;
        if(a%2==0 && b%2==0){
            ans = ans*10 + prevcarry;
            prevcarry=0;
        }
        else if((a%2==1 && b%2 ==0) || (a%2==0 && b%2==1)){
            if(prevcarry==0){
                ans = ans*10 + 1;
                prevcarry =0;
            }
            else{
                ans = ans*10 + 0;
                prevcarry =1;
            }
        }
        else{
            ans = ans*10 + prevcarry;
            prevcarry =1;
        }
        a/=10;
        b/=10;
    }
    if(prevcarry==1){
        ans = ans*10 + prevcarry;
    }
    return ans;
}
int main(){
    cout << binaryAdd(111,111);

}