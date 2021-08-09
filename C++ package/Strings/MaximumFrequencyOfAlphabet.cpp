#include <bits/stdc++.h>
#include <string>

using namespace std;

char Max_frequency(string str){
    int frequency[26];
    for(int i=0;i<26;i++){
        frequency[i] = 0;
    }
    for(int i=0;i<str.length();i++){
        if(int(str[i]) >=65 && int(str[i])<91){
            frequency[int(str[i]-65)]+=1;
        }else if(int(str[i])>=97 && int(str[i])<=122){
            frequency[int(str[i])-97]+=1;
        }else{
            cout << str[i];
        }
        
    }
    int mx = frequency[0];
    int mx_idx =0;
    for(int i=0;i<26;i++){
        if(mx<frequency[i]){
            mx = frequency[i];
            mx_idx = i;
        }
    }
    char c = char(65+mx_idx);
    
    return c;
}


int main(){
    string str = "hello wassup my boes";
    char c= Max_frequency(str);
    cout << "Maximum Frequency alphabet in string is:" << c;


}