#include<bits/stdc++.h>

using namespace std;

int noOfLongestNonRepeatingSubstr(string str){
    vector<int> mp(256,-1);
    int mx_len = INT_MIN;
    int start=-1;
    for(int i=0;i<str.size();i++){
        if(mp[str[i]]>start){
            start = mp[str[i]];
        }
        mp[str[i]] = i;
        mx_len = max(mx_len,i-start);
        
    }
    cout << mx_len;
    return mx_len;
}

int main(){
    noOfLongestNonRepeatingSubstr("abcbcacb");
}