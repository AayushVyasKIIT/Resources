#include <bits/stdc++.h>

using namespace std;


int main(){

    string sentence = "Hey, how are you doing?";
    int i=0;
    string temp = " ";
    stack <string> s;
    while(i<sentence.length()+1){
        if(sentence[i]==' ' or sentence[i]=='\0'){
            s.push(temp);
            temp = "";
        }
        temp = temp + sentence[i];
        i++;
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }

}