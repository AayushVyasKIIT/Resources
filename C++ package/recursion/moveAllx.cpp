#include <bits/stdc++.h>

using namespace std;

string moveAllx(string s){

    if(s.length()==0){
        return "";
    }
    char c = s[0];
    string ans = moveAllx(s.substr(1));

    if(c=='x'){
        return ans+c;
    }
        
    return c + ans ;
}

int main(){

    cout << moveAllx("xx23435xx343");
}