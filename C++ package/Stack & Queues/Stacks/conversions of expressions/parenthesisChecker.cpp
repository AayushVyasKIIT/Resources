#include <bits/stdc++.h>

using namespace std;

bool parenthesisCheck(string s){
    stack <char> stack;
    for(int i=0;i<s.length();i++){
        switch (s[i])
        {
        case '(':
            stack.push(s[i]);
            break;
        case ')':
            if(!stack.empty() && stack.top()=='('){
                stack.pop();
                break;
            }else{
                return false;
            }
        case '{':
            stack.push(s[i]);
            break;
        case '}':
            if(!stack.empty() && stack.top()=='{'){
                stack.pop();
                break;
            }else{
                return false;
            }
        case '[':
            stack.push(s[i]);
            break;
        case ']':
            if(!stack.empty() && stack.top()=='['){
                stack.pop();
                break;
            }else{
                return false;
            }
        default:
            break;
        }
    }
    if(!stack.empty()){
            return false;
        }
    return true;
        
}


int main(){
    string parenthesis = "{[()]}";
    parenthesisCheck(parenthesis)?cout<<"OK":cout<<"NOT OK";
}