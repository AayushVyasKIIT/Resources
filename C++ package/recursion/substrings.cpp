#include <bits/stdc++.h>

using namespace std;

void substrings(string s,string ans){

    if(s.length()==0){
        cout << ans << endl;
        return;
    }
    char c =  s[0];
    string ros = s.substr(1);

    substrings(s,ans); //ek baar toa kch nhi add krengy
    substrings(s,ans+c); // ek baar add ek add kreny.
}
void substringsWascii(string s,string ans){

    if(s.length()==0){
        cout << ans << endl;
        return;
    }
    char c =  s[0];
    int ascii = c;
    string ros = s.substr(1);

    substringsWascii(s,ans); //ek baar toa kch nhi add krengy
    substringsWascii(s,ans+c); // ek baar add ek add kreny alphabet. 
    substringsWascii(s,ans+to_string(ascii)); // add krengy ascii.
}


int main(){


}